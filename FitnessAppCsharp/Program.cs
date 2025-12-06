using System;
using System.Text;
using System.Collections.Generic;

namespace FitnessApp2
{
    class Program
    {
        static void Main()
        {
            Console.OutputEncoding = Encoding.UTF8;


            // 1. Производные классы и наследование
            Console.WriteLine("Производные классы:");
            CardioActivity cardio = new CardioActivity(5.0);
            StrengthActivity strength = new StrengthActivity(10);
            FlexibilityActivity flexibility = new FlexibilityActivity(30);
            BalanceActivity balance = new BalanceActivity(7);

            Console.WriteLine($"Кардио активность: {cardio.Title}");
            Console.WriteLine($"Силовая активность: {strength.Title}");
            Console.WriteLine($"Гибкость: {flexibility.Title}");
            Console.WriteLine($"Баланс: {balance.Title}\n");

            // 2. Protected модификатор (доступ к baseCaloriesPerMin)
            Console.WriteLine("Protected модификатор:");
            Console.WriteLine($"Базовые калории в минуту (protected): {cardio.GetType().GetField("baseCaloriesPerMin", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance)?.GetValue(cardio)}");
            Console.WriteLine($"Калории кардио: {cardio.EstimateCalories(10)}");
            Console.WriteLine($"Калории силовые: {strength.EstimateCalories(10)}");
            Console.WriteLine($"Калории гибкость: {flexibility.EstimateCalories(10)}");
            Console.WriteLine($"Калории баланс: {balance.EstimateCalories(10)}\n");

            // 3. Перегрузка методов (с вызовом base и без)
            Console.WriteLine("Перегрузка методов:");
            Console.WriteLine($"Силовые (с вызовом base): {strength.EstimateCalories(10)}");
            Console.WriteLine($"Баланс (без вызова base): {balance.EstimateCalories(10)}\n");

            // 4. Виртуальные функции и полиморфизм
            Console.WriteLine("Виртуальные функции:");
            FitnessComponent profile = new ProfileManager("1", "user", 25, ProfileManager.Gender.Male, 180, 75.0,
                ProfileManager.Goal.GainMass, ProfileManager.Level.Intermediate);

            profile.CallVirtual(); // Вызов невиртуальной функцией
            Console.WriteLine($"Полиморфизм через базовый класс: {profile.CalculateSomething()}");

            // Демонстрация через указатели
            Activity activityRef = cardio;
            Console.WriteLine($"Через указатель на базовый класс: {activityRef.EstimateCalories(10)}");

            activityRef = strength;
            Console.WriteLine($"Через указатель на производный класс: {activityRef.EstimateCalories(10)}\n");

            // 5. Клонирование (поверхностное и глубокое)
            Console.WriteLine("Клонирование:");
            Activity original = new CardioActivity(10.0);
            Activity shallowClone = (Activity)original.Clone();
            Activity deepClone = original.DeepClone();

            Console.WriteLine("Оригинал, поверхностный и глубокий клоны созданы");
            Console.WriteLine($"Оригинал калории: {original.EstimateCalories(10)}");
            Console.WriteLine($"Поверхностный клон калории: {shallowClone.EstimateCalories(10)}");
            Console.WriteLine($"Глубокий клон калории: {deepClone.EstimateCalories(10)}\n");

            // 6. Конструкторы производных классов
            Console.WriteLine("Конструкторы производных классов:");
            TrackableActivity trackable = new TrackableActivity("track_1", "Отслеживаемая активность",
                new[] { Activity.MuscleGroup.CHEST, Activity.MuscleGroup.ARMS }, Activity.ActivityType.STRENGTH,
                new[] { ProfileManager.Equipment.Dumbbells }, Activity.Level.INTERMEDIATE, "Отслеживаемое упражнение");
            Console.WriteLine($"Trackable активность создана: {trackable.Title}\n");

            // 7. Абстрактные классы
            Console.WriteLine($"Абстрактный метод GetInfo: {profile.GetInfo()}");
            FitnessComponent clonedProfile = profile.Clone();
            Console.WriteLine($"Клонированный объект: {clonedProfile.GetInfo()}\n");

            // 8. Интерфейсы
            Console.WriteLine("Интерфейсы:");
            ITrackable trackableInterface = trackable;
            ICustomizable customizableInterface = trackable;

            trackableInterface.LogProgress(DateTime.Now);
            trackableInterface.LogProgress(DateTime.Now.AddDays(1));
            Console.WriteLine($"Отслеживание: {trackableInterface.GetTrackingInfo()}");

            customizableInterface.AddCustomModification("Увеличить вес");
            customizableInterface.AddCustomModification("Добавить подходы");
            Console.WriteLine($"Модификации: {string.Join(", ", customizableInterface.GetModifications())}");

            // Множественное наследование (абстрактный класс + интерфейсы)
            Console.WriteLine($"Множественное наследование - калории баланс с модификациями: {trackable.EstimateCalories(10)}\n");

        }
    }
}
