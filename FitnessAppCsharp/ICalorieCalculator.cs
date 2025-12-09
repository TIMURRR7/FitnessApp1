using System;

namespace FitnessApp2
{
    // Интерфейс для калькуляторов калорий с поддержкой паттерна делегирования
    public interface ICalorieCalculator
    {
        // Рассчитывает количество калорий для указанной активности
        int CalculateCalories(
            int baseCaloriesPerMinute,
            int durationMinutes,
            Activity.ActivityType activityType,
            params object[] additionalParameters
        );
    }
}
