using System;
using System.Collections.Generic;

public class ProfileManager
{
    // Перечисления
    public enum Gender { Male, Female }                         // Пол пользователя
    public enum Goal { LoseWeight, GainMass, Health }           // Цель тренировок
    public enum Level { Beginner, Intermediate, Advanced }     // Уровень подготовки
    public enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday }
    public enum Equipment { Dumbbells, Barbell, Bench }         // Доступное оборудование

    // Поля класса
    private string id;                          // Уникальный идентификатор пользователя
    private string username;                    // Имя (никнейм) пользователя
    private int age;                            // Возраст пользователя в годах
    private Gender gender;                      // Пол пользователя (Male / Female)
    private int heightCm;                       // Рост в сантиметрах
    private double currentWeightKg;             // Текущий вес в килограммах
    private Goal targetGoal;                    // Цель тренировок
    public Level fitnessLevel;                 // Уровень подготовки
    private List<Weekday> workoutDaysPref;      // Список предпочитаемых дней для тренировок
    private List<Equipment> availableEquipment; // Список доступного оборудования
    private bool alertsEnabled;                // Включены ли уведомления

    // Конструктор: инициализирует профиль пользователя
    public ProfileManager(string id, string username, int age, Gender gender,
        int heightCm, double currentWeightKg, Goal targetGoal, Level fitnessLevel,
        List<Weekday> workoutDaysPref, List<Equipment> availableEquipment,
        bool alertsEnabled)
    {
        this.id = id;
        this.username = username;
        this.age = age;
        this.gender = gender;
        this.heightCm = heightCm;
        this.currentWeightKg = currentWeightKg;
        this.targetGoal = targetGoal;
        this.fitnessLevel = fitnessLevel;
        this.workoutDaysPref = workoutDaysPref;
        this.availableEquipment = availableEquipment;
        this.alertsEnabled = alertsEnabled;
    }

    // Метод: обновляет вес пользователя
    public void ChangeWeight(double newWeight)
    {
        currentWeightKg = newWeight;
    }

    // Метод: изменяет цель пользователя
    public void UpdateGoal(Goal newGoal)
    {
        targetGoal = newGoal;
    }

    // Метод: рассчитывает индекс массы тела (BMI)
    public double CalculateBMI()
    {
        double heightM = heightCm / 100.0;
        return currentWeightKg / (heightM * heightM);
    }

    // Метод: возвращает доступное оборудование
    public List<Equipment> GetAvailableEquipment()
    {
        return availableEquipment;
    }
    public Goal GetGoal()
    {
        return targetGoal;
    }
    public string GetUsername()
    {
        return username;
    }
}