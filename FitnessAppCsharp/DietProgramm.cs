using System;
using System.Collections.Generic;

public class DietProgram
{
    // Статическая база данных продуктов с калорийностью
    private static readonly Dictionary<string, double> FoodDatabase = new()
    {
        { "Курица", 165 }, { "Рис", 130 }, { "Новый продукт", 100 }, { "Гречка 100г", 110 }
    };

    // Поля класса 
    private string id;                              // Уникальный идентификатор плана питания
    private string ownerUserId;                     // ID владельца (пользователя)
    private string planDate;                        // Дата плана (например, "2025-11-26")
    private List<string> dailyMeals;                // Список приёмов пищи (названия блюд)
    private string dailyTargets;                    // Цели по калориям

    // Конструктор: инициализирует план питания
    public DietProgram(string id, string ownerUserId, string planDate, List<string> dailyMeals, string dailyTargets = "2000 ккал")
    {
        this.id = id;
        this.ownerUserId = ownerUserId;
        this.planDate = planDate;
        this.dailyMeals = new List<string>(dailyMeals);
        this.dailyTargets = dailyTargets;
    }

    // Метод для добавления продуктов в базу данных
    public static void AddFoodToDatabase(string name, double calories)
    {
        if (!FoodDatabase.ContainsKey(name))
            FoodDatabase[name] = calories;
    }

    // Метод замены блюда с обработкой исключений
    public void SwapDish(string oldDish, string newDish)
    {
        try
        {
            int index = dailyMeals.IndexOf(oldDish);
            if (index == -1) throw new KeyNotFoundException($"Блюдо \"{oldDish}\" не найдено в плане");
            dailyMeals[index] = newDish;
            Console.WriteLine($"[DietProgram] Блюдо \"{oldDish}\" заменено на \"{newDish}\"");
        }
        catch (KeyNotFoundException ex) 
        {
            Console.WriteLine($"[DietProgram] Ошибка: {ex.Message}");
        }
    }

    // Метод расчета дневной калорийности и формирования отчета
    public string CalcDailySummary()
    {
        double total = 0;
        var known = new List<string>();
        var unknown = new List<string>();


        foreach (var meal in dailyMeals)
        {
            if (FoodDatabase.TryGetValue(meal, out double kcal))
            {
                total += kcal;
                known.Add($"{meal}: {kcal}");
            }
            else unknown.Add(meal);
        }

        string unknownText = unknown.Count > 0 ? $", неизвестно в базе: {string.Join(", ", unknown)}" : "";
        return $"День {planDate}: {total} ккал ({string.Join(" + ", known)}){unknownText}. Цель: {dailyTargets}";
    }
}
