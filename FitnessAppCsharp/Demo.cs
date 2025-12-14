using System;
using System.Collections.Generic;
using System.Linq;

namespace FitnessApp2
{
    public static class Demo
    {
        public static void DemonstrateCollections()
        {
            Console.WriteLine("\n=== Демонстрация использования .NET Collections Framework ===");

            // Создание объектов базового и производных классов
            Activity baseActivity = new Activity("base_1", "Базовая активность", category: Activity.ActivityType.STRENGTH);
            StrengthActivity strength = new StrengthActivity(10);
            CardioActivity cardio = new CardioActivity(5.0);

            // 1. List<T> (аналог std::vector)
            Console.WriteLine("\n1. List<T> (динамический массив):");
            List<Activity> activityList = new List<Activity> { baseActivity, strength, cardio };
            activityList.Add(new StrengthActivity(15));

            Console.WriteLine("Активности в списке:");
            foreach (var activity in activityList)
            {
                Console.WriteLine($"- {activity.Title} ({activity.Category})");
            }

            // Сортировка (аналог std::sort)
            activityList.Sort((a, b) => string.Compare(a.Title, b.Title));
            Console.WriteLine("\nПосле сортировки по названию:");
            foreach (var activity in activityList)
            {
                Console.WriteLine($"- {activity.Title}");
            }

            // 2. LinkedList<T> (аналог std::list)
            Console.WriteLine("\n2. LinkedList<T> (двусвязный список):");
            LinkedList<Activity> activityLinkedList = new LinkedList<Activity>();
            activityLinkedList.AddLast(baseActivity);
            activityLinkedList.AddLast(strength);
            activityLinkedList.AddFirst(cardio);

            Console.WriteLine("Активности в связном списке:");
            foreach (var activity in activityLinkedList)
            {
                Console.WriteLine($"- {activity.Title}");
            }

            // 3. Dictionary<TKey, TValue> (аналог std::map)
            Console.WriteLine("\n3. Dictionary<TKey, TValue> (ассоциативный массив):");
            Dictionary<string, Activity> activityMap = new Dictionary<string, Activity>
            {
                ["strength"] = strength,
                ["cardio"] = cardio,
                ["base"] = baseActivity
            };

            Console.WriteLine("Активности в словаре:");
            foreach (var kvp in activityMap)
            {
                Console.WriteLine($"- Ключ: {kvp.Key}, Значение: {kvp.Value.Title}");
            }

            // Поиск (аналог std::find)
            var found = activityMap.FirstOrDefault(kvp => kvp.Value.Category == Activity.ActivityType.CARDIO);
            if (!string.IsNullOrEmpty(found.Key))
            {
                Console.WriteLine($"\nНайдена кардио активность: {found.Value.Title}");
            }

            // 4. Array (аналог std::array)
            Console.WriteLine("\n4. Array (фиксированный массив):");
            Activity[] activityArray = new Activity[3] { baseActivity, strength, cardio };

            Console.WriteLine("Активности в массиве:");
            for (int i = 0; i < activityArray.Length; i++)
            {
                Console.WriteLine($"- [{i}] {activityArray[i].Title}");
            }

            // 5. Span<T> (аналог std::span)
            Console.WriteLine("\n5. Span<T> (представление непрерывного участка данных):");
            Span<Activity> activitySpan = activityArray.AsSpan();
            Console.WriteLine("Span содержит " + activitySpan.Length + " элементов");

            // LINQ алгоритмы (аналоги STL алгоритмов)
            Console.WriteLine("\n=== LINQ алгоритмы ===");

            // min_element, max_element
            var maxCalories = activityList.Max(a => a.EstimateCalories(30));
            var minCalories = activityList.Min(a => a.EstimateCalories(30));
            Console.WriteLine($"Максимальные калории: {maxCalories}, Минимальные калории: {minCalories}");

            // any_of
            bool hasStrengthActivities = activityList.Any(a => a.Category == Activity.ActivityType.STRENGTH);
            Console.WriteLine($"Есть силовые активности: {hasStrengthActivities}");

            // copy_if, transform
            var strengthActivities = activityList
                .Where(a => a.Category == Activity.ActivityType.STRENGTH) // filter
                .Select(a => $"{a.Title} ({a.EstimateCalories(30)} кал)") // transform
                .ToList(); // copy

  
        }

        public static void DemonstrateGenericFunctions()
        {
            Console.WriteLine("\n=== Демонстрация обобщенных функций ===");

            try
            {
                // Демонстрация CalculateBMI
                double bmi = FitnessCalculations.CalculateBMI(70.0, 1.75);
                Console.WriteLine($"BMI для веса 70kg и роста 1.75m: {bmi:F2}");

                // Демонстрация ошибки в CalculateBMI (отрицательный рост)
                Console.WriteLine("\nПопытка расчета BMI с отрицательным ростом:");
                double invalidBmi = FitnessCalculations.CalculateBMI(70.0, -1.75);
                Console.WriteLine($"BMI: {invalidBmi:F2}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }

            try
            {
                // Демонстрация CalculateTrainingVolume
                List<double> sets = new List<double> { 3, 4, 3 };
                List<double> reps = new List<double> { 10, 8, 12 };
                List<double> weights = new List<double> { 50.0, 60.0, 40.0 };

                double volume = FitnessCalculations.CalculateTrainingVolume(sets, reps, weights);
                Console.WriteLine($"Тренировочный объем: {volume} кг");

                // Демонстрация CalculateIntensityPercentage
                double intensity = FitnessCalculations.CalculateIntensityPercentage(80.0, 100.0);
                Console.WriteLine($"Интенсивность: {intensity:F1}%");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }

        public static void DemonstrateGenericClass()
        {
            Console.WriteLine("\n=== Демонстрация обобщенного класса ===");

            // Создание экземпляра класса
            var tracker = new FitnessTracker(
                "Иван Петров",
                new StandardExecutionStrategy()
            );

            // Нешаблонные методы
            tracker.PrintStatistics();

            // Шаблонные методы
            tracker.AddActivity(new StrengthActivity(12));
            tracker.AddActivity(new CardioActivity(7.5));
            tracker.AddActivity(new Activity("flex_1", "Гибкость", category: Activity.ActivityType.FLEXIBILITY));

            Console.WriteLine("\nВсе активности:");
            foreach (var activity in tracker.GetActivities())
            {
                Console.WriteLine($"- {activity.Title} ({activity.Category})");
            }

            // Выполнение с текущей стратегией
            var activities = tracker.GetActivities();
            if (activities.Count > 0)
            {
                tracker.ExecuteWithStrategy(activities[0]);
            }

            // Фильтрация активностей
            var strengthActivities = tracker.FilterActivities(a => a.Category == Activity.ActivityType.STRENGTH);
            Console.WriteLine($"Найдено силовых активностей: {strengthActivities.Count()}");

            // Смена стратегии в существующем трекере
            var progressiveStrategy = new ProgressiveOverloadStrategy();
            tracker.SetStrategy(progressiveStrategy);
            Console.WriteLine("\nПосле смены стратегии:");
            tracker.PrintStatistics();
        }
    }
}

