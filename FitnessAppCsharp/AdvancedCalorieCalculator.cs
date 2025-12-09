using System;

namespace FitnessApp2
{
   
    // Продвинутый калькулятор калорий с учетом типа активности и дополнительных параметров
    public class AdvancedCalorieCalculator : ICalorieCalculator
    {
        public int CalculateCalories(int baseCaloriesPerMin, int durationMinutes,
                                   Activity.ActivityType activityType, params object[] additionalParams)
        {
            double multiplier = 1.0;

            // Множитель в зависимости от типа активности
            switch (activityType)
            {
                case Activity.ActivityType.CARDIO:
                    multiplier = 1.2; // Кардио 
                    break;
                case Activity.ActivityType.STRENGTH:
                    multiplier = 1.5; // Силовые упражнения 
                    break;
                case Activity.ActivityType.FLEXIBILITY:
                    multiplier = 0.8; // Гибкость 
                    break;
                case Activity.ActivityType.BALANCE:
                    multiplier = 0.9; // Баланс 
                    break;
            }

            // Учет дополнительных параметров
            if (additionalParams.Length > 0)
            {
                foreach (var param in additionalParams)
                {
                    if (param is int intensity && intensity > 0)
                    {
                        multiplier *= (1.0 + intensity * 0.1); // Интенсивность увеличивает расход
                    }
                    else if (param is double weight && weight > 0)
                    {
                        multiplier *= (1.0 + weight * 0.01); // Вес влияет на расход
                    }
                }
            }

            return (int)(baseCaloriesPerMin * durationMinutes * multiplier);
        }
    }
}
