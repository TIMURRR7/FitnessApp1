using System;

namespace FitnessApp2
{
    
    // Базовый калькулятор калорий 
    public class BasicCalorieCalculator : ICalorieCalculator
    {
        public int CalculateCalories(int baseCaloriesPerMin, int durationMinutes,
                                   Activity.ActivityType activityType, params object[] additionalParams)
        {
            // Простой расчет: базовые калории * продолжительность
            return baseCaloriesPerMin * durationMinutes;
        }
    }
}
