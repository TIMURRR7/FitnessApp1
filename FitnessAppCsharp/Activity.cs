using System;
using System.Collections.Generic;
using System.Linq; 

public class Activity
{
    // Перечисления
    public enum MuscleGroup { CHEST, BACK, LEGS }                    // Мышечные группы
    public enum ActivityType { STRENGTH, CARDIO }                    // Тип упражнения

    // Поля класса
    private string id;                                               // Уникальный идентификатор упражнения
    private string title;                                            // Название упражнения
    private List<MuscleGroup> targetedMuscles;                       // Задействованные мышцы
    public ActivityType category;                                   // Тип активности (сила / кардио)
    public List<ProfileManager.Equipment> requiredEquipment;        // Необходимое оборудование
    public ProfileManager.Level complexity;                         // Уровень сложности
    private string description;                                      // Описание упражнения

    // Конструктор: инициализирует упражнение
    public Activity(string id, string title, List<MuscleGroup> targetedMuscles,
        ActivityType category, List<ProfileManager.Equipment> requiredEquipment,
        ProfileManager.Level complexity, string description)
    {
        this.id = id;
        this.title = title;
        this.targetedMuscles = targetedMuscles;
        this.category = category;
        this.requiredEquipment = requiredEquipment;
        this.complexity = complexity;
        this.description = description;
    }

    // Метод: проверяет, подходит ли упражнение пользователю (есть ли всё оборудование и подходящий уровень)
    public bool MatchesUser(ProfileManager user)
    {
        // Проверяем уровень сложности
        if (complexity > user.fitnessLevel) 
            return false;

        // Проверяем, есть ли у пользователя всё нужное оборудование
        var userEquipment = user.GetAvailableEquipment();
        foreach (var eq in requiredEquipment)
        {
            if (!userEquipment.Contains(eq))
                return false;
        }
        return true;
    }

    // Метод: возвращает примерную длительность упражнения в минутах (заглушка)
    public int GetDurationEstimate()
    {
        return 10; 
    }

    // Дополнительные геттеры (удобно для вывода)
    public string GetTitle() { return title; }
    public ActivityType GetCategory() { return category; }
    public List<MuscleGroup> GetTargetedMuscles() { return targetedMuscles; }
}