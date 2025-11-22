using System;
using System.Collections.Generic;
using System.Linq;

namespace FitnessApp2
{
    // Класс DietProgram: план питания на день 
    public class DietProgram
    {
        // СТАТИЧЕСКАЯ БАЗА ПРОДУКТОВ
        private static readonly Dictionary<string, double> FoodDatabase = new()
        {
            { "Яблоко", 78 },
            { "Банан", 133.5 },
            { "Курица", 165 },
            { "Рис", 130 },
            { "Овсянка", 68 },
            { "Яйца", 155 },
            { "Гречка 100г", 110 },
            { "Овощи", 121 }
        };

        // ПОЛЯ КЛАССА 
        private readonly string id;                    // Уникальный идентификатор плана
        private readonly string ownerUserId;           // ID владельца (пользователя)
        private readonly string planDate;              // Дата плана (например, "2025-11-18")
        private readonly List<string> dailyMeals;      // Список приёмов пищи (названия блюд)
        private string dailyTargets;                   // Цели по калориям и КБЖУ

        // КОНСТРУКТОР 
        public DietProgram(
            string id,
            string ownerUserId,
            string planDate,
            List<string> dailyMeals,
            string dailyTargets = "2000 ккал, 150г белка")
        {
            this.id = id ?? throw new ArgumentNullException(nameof(id));
            this.ownerUserId = ownerUserId ?? throw new ArgumentNullException(nameof(ownerUserId));
            this.planDate = planDate ?? throw new ArgumentNullException(nameof(planDate));
            this.dailyMeals = dailyMeals != null ? new List<string>(dailyMeals) : new List<string>();
            this.dailyTargets = dailyTargets;
        }

        //  МЕТОДЫ 

        // Обновляет план при изменении веса пользователя
        public void updateForWeightShift(double weightDelta)
        {
            int adjustment = (int)Math.Round(weightDelta / 5.0) * 300;
            Console.WriteLine($"[DietProgram] Вес изменился на {weightDelta:+0.0;-0.0;0} кг → корректировка калорий: {adjustment:+0;-0;0} ккал");
        }

        // Рассчитывает итоговую калорийность и возвращает строку-подведение
        public string calcDailySummary()
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
                else
                {
                    unknown.Add(meal);
                }
            }

            string unknownText = unknown.Count > 0
                ? $", неизвестно: {string.Join(", ", unknown)}"
                : "";

            return $"День {planDate}: {total} ккал ({string.Join(" + ", known)}){unknownText}. Цель: {dailyTargets}";
        }

        // Заменяет одно блюдо на другое
        public void swapDish(string mealTime, string replacement)
        {
            int index = dailyMeals.IndexOf(mealTime);
            if (index != -1)
            {
                dailyMeals[index] = replacement;
                Console.WriteLine($"[DietProgram] Блюдо \"{mealTime}\" заменено на \"{replacement}\"");
            }
            else
            {
                Console.WriteLine($"[DietProgram] Ошибка: блюдо \"{mealTime}\" не найдено в плане");
            }
        }

        
    }
}