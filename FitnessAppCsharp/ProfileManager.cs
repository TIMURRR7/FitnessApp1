using System;
using System.Collections.Generic;

public class ProfileManager
{
    // Перечисления для характеристик пользователя
    public enum Gender { Male, Female }                         // Пол пользователя
    public enum Goal { LoseWeight, GainMass, Health }           // Цель тренировок
    public enum Level { Beginner, Intermediate, Advanced }      // Уровень подготовки
    public enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday } // Дни недели
    public enum Equipment { Dumbbells, Barbell, Bench }         // Доступное оборудование

    // Статическое поле для подсчета количества созданных профилей
    private static int profileCount = 0;
    // Статический метод для получения общего количества профилей
    public static int GetProfileCount() => profileCount;

    //Поля класса 
    private string id;                                          // Уникальный идентификатор пользователя
    private string username;                                    // Имя пользователя
    private int age;                                            // Возраст пользователя в годах
    private Gender gender;                                      // Пол пользователя
    private int heightCm;                                       // Рост в сантиметрах
    private double currentWeightKg;                             // Текущий вес в килограммах
    private Goal targetGoal;                                    // Цель тренировок
    private Level fitnessLevel;                                 // Уровень подготовки
    private List<Weekday> workoutDaysPref;                      // Список предпочитаемых дней для тренировок
    private List<Equipment> availableEquipment;                 // Список доступного оборудования
    private bool alertsEnabled;                                 // Включены ли уведомления

    // Конструктор: инициализирует профиль пользователя
    public ProfileManager(string id, string username, int age, Gender gender,
        int heightCm, double currentWeightKg, Goal targetGoal, Level fitnessLevel,
        List<Weekday> workoutDaysPref, List<Equipment> availableEquipment,
        bool alertsEnabled)
    {
        // Использование this 
        this.id = id;
        this.username = username;
        this.age = age;
        this.gender = gender;
        this.heightCm = heightCm;
        this.currentWeightKg = currentWeightKg;
        this.targetGoal = targetGoal;
        this.fitnessLevel = fitnessLevel;
        this.workoutDaysPref = workoutDaysPref ?? new List<Weekday>();
        this.availableEquipment = availableEquipment ?? new List<Equipment>();
        this.alertsEnabled = alertsEnabled;
        profileCount++;
    }

    public string Username
    {
        get => username;
        set => username = value;
    }

    public double GetCurrentWeightKg() => currentWeightKg;
    public int GetHeightCm() => heightCm;
    public Level GetFitnessLevel() => fitnessLevel;

    // Метод изменения веса с обработкой исключений
    public void ChangeWeight(double newWeight)
    {
        try
        {
            if (newWeight <= 0) throw new ArgumentException("Вес должен быть положительным числом");
            this.currentWeightKg = newWeight;
        }
        catch (ArgumentException ex) 
        {
            Console.WriteLine($"Ошибка при обновлении веса: {ex.Message}");
        }
    }

    // Метод расчета индекса массы тела с обработкой исключений
    public double CalculateBMI()
    {
        try
        {
            if (this.heightCm <= 0) throw new InvalidOperationException("Рост должен быть положительным для расчёта BMI");
            double heightM = heightCm / 100.0;
            return Math.Round(currentWeightKg / (heightM * heightM), 2);
        }
        catch (InvalidOperationException ex) 
        {
            Console.WriteLine($"Ошибка расчёта BMI: {ex.Message}");
            return 0.00;
        }
    }

   
    public List<Equipment> GetAvailableEquipment() => availableEquipment;
}
