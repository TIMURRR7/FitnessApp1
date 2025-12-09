using System;

namespace FitnessApp2
{
    
    // Настраиваемый калькулятор калорий с пользовательскими формулами
    public class CustomCalorieCalculator : ICalorieCalculator
    {
        private Func<int, int, Activity.ActivityType, object[], int> _customFormula;

        public CustomCalorieCalculator(Func<int, int, Activity.ActivityType, object[], int> formula)
        {
            _customFormula = formula ?? throw new ArgumentNullException(nameof(formula));
        }

        public int CalculateCalories(int baseCaloriesPerMin, int durationMinutes,
                                   Activity.ActivityType activityType, params object[] additionalParams)
        {
            return _customFormula(baseCaloriesPerMin, durationMinutes, activityType, additionalParams);
        }

        // Метод для создания калькулятора с формулой Харриса-Бенедикта
        public static CustomCalorieCalculator CreateHarrisBenedictCalculator()
        {
            return new CustomCalorieCalculator((baseCal, duration, type, params_) =>
            {
       
                double bmr = 1500; 
                double activityMultiplier = type switch
                {
                    Activity.ActivityType.CARDIO => 8.0,
                    Activity.ActivityType.STRENGTH => 6.0,
                    Activity.ActivityType.FLEXIBILITY => 3.0,
                    Activity.ActivityType.BALANCE => 4.0,
                    _ => 5.0
                };

                return (int)((bmr / 1440 * duration) * activityMultiplier / 10);
            });
        }

        
        // Метод для создания калькулятора с линейной формулой
        public static CustomCalorieCalculator CreateLinearCalculator(double slope, double intercept)
        {
            return new CustomCalorieCalculator((baseCal, duration, type, params_) =>
            {
                return (int)(slope * duration + intercept);
            });
        }
    }
}
