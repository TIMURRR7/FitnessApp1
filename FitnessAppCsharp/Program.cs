using System;
using System.Text;
using System.Collections.Generic;

namespace FitnessApp2
{
    class Program
    {
        
        static void Main()
        {
            // Статическая конфигурация - установка калькулятора по умолчанию
            Console.WriteLine("Статическая конфигурация:");
            Activity.DefaultCalculator = new AdvancedCalorieCalculator();
            Console.WriteLine("Установлен продвинутый калькулятор по умолчанию");

            CardioActivity cardioWithAdvanced = new CardioActivity(8.0);
            StrengthActivity strengthWithAdvanced = new StrengthActivity(12);

            Console.WriteLine($"Кардио с продвинутым калькулятором: {cardioWithAdvanced.EstimateCalories(10)} калорий");
            Console.WriteLine($"Силовые с продвинутым калькулятором: {strengthWithAdvanced.EstimateCalories(10)} калорий");

            // Динамическая конфигурация - смена калькулятора во время выполнения
            Console.WriteLine("\nДинамическая конфигурация:");
            ICalorieCalculator customCalculator = CustomCalorieCalculator.CreateHarrisBenedictCalculator();
            cardioWithAdvanced.SetCalculator(customCalculator);
            Console.WriteLine("Кардио переключен на калькулятор Харриса-Бенедикта");

            ICalorieCalculator linearCalculator = CustomCalorieCalculator.CreateLinearCalculator(15.5, 50);
            strengthWithAdvanced.SetCalculator(linearCalculator);
            Console.WriteLine("Силовые переключены на линейный калькулятор");

            Console.WriteLine($"Кардио с калькулятором Харриса-Бенедикта: {cardioWithAdvanced.EstimateCalories(10)} калорий");
            Console.WriteLine($"Силовые с линейным калькулятором: {strengthWithAdvanced.EstimateCalories(10)} калорий");

            // Демонстрация разных калькуляторов для одной активности
            Console.WriteLine("\nСравнение калькуляторов для одной активности:");
            Activity testActivity = new CardioActivity(5.0);
            int duration = 15;

            testActivity.SetCalculator(new BasicCalorieCalculator());
            int basicResult = testActivity.EstimateCalories(duration);

            testActivity.SetCalculator(new AdvancedCalorieCalculator());
            int advancedResult = testActivity.EstimateCalories(duration);

            testActivity.SetCalculator(CustomCalorieCalculator.CreateLinearCalculator(12.0, 20));
            int customResult = testActivity.EstimateCalories(duration);

            Console.WriteLine($"Базовый калькулятор: {basicResult} калорий");
            Console.WriteLine($"Продвинутый калькулятор: {advancedResult} калорий");
            Console.WriteLine($"Пользовательский калькулятор: {customResult} калорий");

   
        }
    }
}
