using System;
using System.Collections.Generic;

public class Activity
{
    // Перечисления
    public enum MuscleGroup { CHEST, BACK, LEGS }                    // Мышечные группы для целевых мышц
    public enum ActivityType { STRENGTH, CARDIO }                    // Тип упражнения: силовое или кардио

    // Статическое поле для подсчета количества созданных активностей
    private static int activityCount = 0;
    // Статический метод для получения общего количества активностей
    public static int GetActivityCount() => activityCount;

    // Поля класса 
    private string id;                                               // Уникальный идентификатор упражнения
    private string title;                                            // Название упражнения
    private List<MuscleGroup> targetedMuscles;                       // Список задействованных мышечных групп
    private ActivityType category;                                   // Тип активности (сила / кардио)
    private List<ProfileManager.Equipment> requiredEquipment;        // Необходимое оборудование
    private ProfileManager.Level complexity;                         // Уровень сложности
    private string description;                                      // Описание техники выполнения упражнения

    // Конструктор: инициализирует все поля упражнения
    public Activity(string id, string title, List<MuscleGroup> targetedMuscles,
        ActivityType category, List<ProfileManager.Equipment> requiredEquipment,
        ProfileManager.Level complexity, string description)
    {
        // Использование this 
        this.id = id;
        this.title = title;
        this.targetedMuscles = targetedMuscles;
        this.category = category;
        this.requiredEquipment = requiredEquipment ?? new List<ProfileManager.Equipment>();
        this.complexity = complexity;
        this.description = description;
        
        activityCount++;
    }

    // Метод проверки совместимости упражнения с пользователем с обработкой исключений
    public bool MatchesUser(ProfileManager user)
    {
        try
        {
            // Проверка уровня сложности (не должно быть выше уровня пользователя)
            if (this.complexity > user.GetFitnessLevel()) return false;

            // Проверка оборудования: у пользователя должно быть всё необходимое
            foreach (var eq in this.requiredEquipment)
                if (!user.GetAvailableEquipment().Contains(eq))
                    return false;
            return true;
        }
        catch (Exception ex) 
        {
            Console.WriteLine($"Ошибка при проверке совместимости упражнения: {ex.Message}");
            return false;
        }
    }

    public ProfileManager.Level GetComplexity() => complexity;
    public List<ProfileManager.Equipment> GetRequiredEquipment() => requiredEquipment;
    public string GetTitle() => title;
    public ActivityType GetCategory() => category;
}
