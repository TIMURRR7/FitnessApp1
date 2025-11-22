using System;
using System.Collections.Generic;
using System.Linq;

public class FitnessDatabase
{
    // Поля класса
    private List<Activity> activities;          // Все упражнения в базе
    private string updateTimestamp;             // Когда последний раз обновляли базу

    // Конструктор
    public FitnessDatabase()
    {
        activities = new List<Activity>();
        updateTimestamp = "2025-11-16";
    }

    // Метод: поиск упражнений по названию 
    public List<Activity> FindByName(string searchQuery)
    {
        var result = new List<Activity>();

        foreach (var act in activities)
        {
            if (act.GetTitle().IndexOf(searchQuery, StringComparison.OrdinalIgnoreCase) >= 0)
            {
                result.Add(act);
            }
        }
        return result;
    }

    // Метод: фильтрация по цели, оборудованию и уровню 
    public List<Activity> FilterActivities(ProfileManager.Goal targetGoal,
        List<ProfileManager.Equipment> equip, ProfileManager.Level lvl)
    {
        var result = new List<Activity>();

        foreach (var act in activities)
        {
            // 1. Проверка уровня сложности
            if (act.complexity > lvl) continue;

            // 2. Проверка, есть ли у пользователя всё нужное оборудование
            bool hasAllEquipment = true;
            foreach (var req in act.requiredEquipment)
            {
                if (!equip.Contains(req))
                {
                    hasAllEquipment = false;
                    break;
                }
            }
            if (!hasAllEquipment) continue;

            // 3. Проверка по цели (простая логика: если цель — похудеть, то кардио важнее)
            bool matchesGoal = true;
            if (targetGoal == ProfileManager.Goal.LoseWeight && act.category != Activity.ActivityType.CARDIO)
            {
                // Можно пропускать силовые, если цель — похудеть (по желанию)
          
            }

            // Если прошли все проверки — добавляем
            result.Add(act);
        }

        return result;
    }

    // Метод: добавить одно упражнение
    public void AddActivity(Activity newActivity)
    {
        activities.Add(newActivity);
        updateTimestamp = DateTime.Now.ToString("yyyy-MM-dd HH:mm");
    }

    // Метод: полностью заменить библиотеку
    public void UpdateLibrary(List<Activity> newActivities)
    {
        activities = new List<Activity>(newActivities); // копируем
        updateTimestamp = DateTime.Now.ToString("yyyy-MM-dd HH:mm");
    }

    // Вспомогательный: получить все упражнения (удобно для тестов)
    public List<Activity> GetAllActivities()
    {
        return activities;
    }
}