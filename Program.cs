using System;
using System.Collections.Generic;
using FitnessApp2;

class Program
{
    static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8; // Русский текст в консоли


        // 1. Статическая инициализация объектов
        Console.WriteLine("1. Статическая инициализация объектов");
        var days = new List<ProfileManager.Weekday>();
        var equip = new List<ProfileManager.Equipment> { ProfileManager.Equipment.Dumbbells };

        var staticUser = new ProfileManager("1", "user1", 25, ProfileManager.Gender.Male, 190, 90.0,
            ProfileManager.Goal.LoseWeight, ProfileManager.Level.Beginner, days, equip, true);

        Console.WriteLine($"   Создан статический профиль: {staticUser.GetUsername()}");
        Console.WriteLine($"   BMI: {staticUser.CalculateBMI():F2} (ожидается ~24.93)\n");

        // 2. Динамическая инициализация с new
        Console.WriteLine("2. Динамическая инициализация (new)");
        var muscles = new List<Activity.MuscleGroup> { Activity.MuscleGroup.LEGS };
        var reqEquip = new List<ProfileManager.Equipment> { ProfileManager.Equipment.Dumbbells };

        var dynamicActivity = new Activity("act1", "Приседания", muscles, Activity.ActivityType.STRENGTH,
            reqEquip, ProfileManager.Level.Beginner, "Классические приседания");

        Console.WriteLine($"   Динамически создан Activity: {dynamicActivity.GetTitle()}");
        Console.WriteLine($"   Длительность: {dynamicActivity.GetDurationEstimate()} мин");
        Console.WriteLine($"   Подходит пользователю: {dynamicActivity.MatchesUser(staticUser)} (ожидается True)\n");

        // 3. Работа по ссылкам 
        Console.WriteLine("3. Работа по ссылкам");
        var db = new FitnessDatabase();
        FitnessDatabase dbRef = db; 

        var pushUps = new Activity("act2", "Отжимания", muscles, Activity.ActivityType.STRENGTH,
            new List<ProfileManager.Equipment>(), ProfileManager.Level.Intermediate, "От пола");

        dbRef.AddActivity(pushUps);
        Console.WriteLine("   Упражнение добавлено через ссылку на FitnessDatabase\n");

        // 4. Работа с указателями 
        Console.WriteLine("4. Работа с указателями (ссылки на объекты)");
        var events = new List<string>();
        var reminder = new EventPlanner(events, "Ежедневно в 8:00");

        EventPlanner reminderPtr = reminder; 

        var blocks = new List<string> { "Разминка", "Основная часть" };
        var session = new TrainingSession("sess1", "2025-10-27 18:00", 60, "Тренировка ног", blocks,
            TrainingSession.WorkoutStatus.PLANNED);

        reminderPtr.AddToSchedule(session);
        reminderPtr.DelayNotification("sess1", 15);
        Console.WriteLine("   Тренировка добавлена и уведомление отложено через ссылку\n");

        // 5. Динамический массив объектов
        Console.WriteLine("5. Динамический массив объектов");
        var sessionsList = new List<TrainingSession> { session };

        var scheduleArray = new TrainingSchedule[2];
        scheduleArray[0] = new TrainingSchedule("plan1", "1", "2025-10-01", "2025-12-31", sessionsList);
        scheduleArray[1] = new TrainingSchedule("plan2", "1", "2026-01-01", "2026-03-31", sessionsList);

        Console.WriteLine("   Создан массив из 2 планов тренировок\n");
      

        // 6. Массив динамических объектов (List<T>)
        Console.WriteLine("6. Массив динамических объектов (List<T>)");
        var dietList = new List<DietProgram>();

        var ingredients1 = new List<string> { "Курица", "Рис", "Овощи" };
        var ingredients2 = new List<string> { "Яйца", "Овсянка", "Банан" };

        dietList.Add(new DietProgram("diet1", "1", "2025-10-27", ingredients1, "600 ккал"));
        dietList.Add(new DietProgram("diet2", "1", "2025-10-28", ingredients2, "550 ккал"));

        Console.WriteLine($"   Добавлено {dietList.Count} плана питания");

        foreach (var diet in dietList)
        {
            Console.WriteLine($"   {diet.calcDailySummary()}");
        }

        
    }
}