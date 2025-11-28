using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace FitnessApp2
{
    class Program
    {
        static void Main()
        {
            // Установка кодировки для корректного отображения русского текста
            Console.OutputEncoding = Encoding.UTF8;

            // Демонстрация using для работы с disposable объектами 
            using (var writer = new StreamWriter("log.txt", false, Encoding.UTF8))
                writer.WriteLine("Начало демонстрации");

            // Демонстрация статического поля и метода в ProfileManager
            Console.WriteLine("Демонстрация статического поля и метода в ProfileManager");
            var days = new List<ProfileManager.Weekday>();
            var equip = new List<ProfileManager.Equipment> { ProfileManager.Equipment.Dumbbells };

            var user1 = new ProfileManager("1", "user1", 25, ProfileManager.Gender.Male, 190, 90.0,
                ProfileManager.Goal.LoseWeight, ProfileManager.Level.Beginner, days, equip, true);
            var user2 = new ProfileManager("2", "user2", 30, ProfileManager.Gender.Female, 165, 60.0,
                ProfileManager.Goal.Health, ProfileManager.Level.Intermediate, days, equip, true);

            Console.WriteLine($"Общее количество профилей: {ProfileManager.GetProfileCount()} (ожидается 2)\n");

            // Демонстрация свойств (get/set) в ProfileManager
            Console.WriteLine("Демонстрация свойств в ProfileManager");
            Console.WriteLine($"Имя user1: {user1.Username}"); 
            user1.Username = "updatedUser1"; 
            Console.WriteLine($"Обновленное имя user1: {user1.Username}\n");

            // Демонстрация try-catch и throw в ChangeWeight
            Console.WriteLine("Демонстрация try-catch и throw в ProfileManager.ChangeWeight");
            Console.WriteLine("Входные данные для изменения веса: новый вес 85.5 кг");
            user1.ChangeWeight(85.5); 
            Console.WriteLine($"Новый вес user1: {user1.GetCurrentWeightKg()} кг");

            Console.WriteLine("Входные данные для изменения веса: новый вес -10 кг");
            user1.ChangeWeight(-10);
            Console.WriteLine();

            //  Демонстрация CalculateBMI с обработкой исключений
            Console.WriteLine("Демонстрация CalculateBMI с обработкой исключений");
            Console.WriteLine($"Входные данные для BMI user1: рост {user1.GetHeightCm()} см, вес {user1.GetCurrentWeightKg()} кг");
            Console.WriteLine($"BMI user1: {user1.CalculateBMI()}");

            // Создание пользователя с нулевым ростом для демонстрации исключения
            var badUser = new ProfileManager("bad", "bad", 20, ProfileManager.Gender.Male, 0, 85.5,
                ProfileManager.Goal.Health, ProfileManager.Level.Beginner, days, equip, false);
            Console.WriteLine($"Входные данные для BMI с нулевым ростом: рост 0 см, вес 85,5 кг");
            Console.WriteLine($"BMI с нулевым ростом: {badUser.CalculateBMI()}\n");

            // Демонстрация статического поля и метода в Activity
            Console.WriteLine("Демонстрация статического поля и метода в Activity");
            var muscles = new List<Activity.MuscleGroup> { Activity.MuscleGroup.LEGS };
            var reqEquip = new List<ProfileManager.Equipment> { ProfileManager.Equipment.Dumbbells };
            var act1 = new Activity("1", "Приседания", muscles, Activity.ActivityType.STRENGTH, reqEquip, ProfileManager.Level.Beginner, "");
            var act2 = new Activity("2", "Отжимания", muscles, Activity.ActivityType.STRENGTH, new List<ProfileManager.Equipment>(), ProfileManager.Level.Intermediate, "");
            Console.WriteLine($"Общее количество активностей: {Activity.GetActivityCount()} (ожидается 2)\n");

            // Демонстрация MatchesUser с try-catch
            Console.WriteLine("Демонстрация MatchesUser в Activity");
            Console.WriteLine($"Activity1 подходит user1: {act1.MatchesUser(user1)}\n");

            //  Демонстрация статического метода в DietProgram
            Console.WriteLine("Демонстрация статического метода в DietProgram");
            DietProgram.AddFoodToDatabase("Новый продукт", 100); 
            var meals = new List<string> { "Курица", "Рис", "Новый продукт" };
            var diet = new DietProgram("d1", "1", "2025-11-28", meals, "2000 ккал");
            Console.WriteLine(diet.CalcDailySummary());

            // Демонстрация SwapDish с обработкой исключений
            Console.WriteLine("\nДемонстрация SwapDish с обработкой исключений");
            diet.SwapDish("Рис", "Гречка 100г"); // Успешно
            Console.WriteLine(diet.CalcDailySummary());
            diet.SwapDish("Несуществующее блюдо", "Замена"); // Вызовет исключение

            // Демонстрация using для чтения файла
            Console.WriteLine("\nСодержимое log.txt:");
            using (var reader = new StreamReader("log.txt", Encoding.UTF8))
                Console.WriteLine(reader.ReadToEnd());

            Console.WriteLine("\nДемонстрация завершена!");
            Console.ReadKey();
        }
    }
}
