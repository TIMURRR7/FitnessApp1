using System;
using System.Collections.Generic;
using System.Linq;

namespace FitnessApp2
{
    // Класс FitnessTracker с использованием интерфейса IExecutionStrategy
    public class FitnessTracker
    {
        private List<Activity> activities = new List<Activity>();
        private IExecutionStrategy currentStrategy;
        private string userName;
        private int totalSessions;

        public FitnessTracker(string userName, IExecutionStrategy strategy)
        {
            this.userName = userName;
            this.currentStrategy = strategy;
            this.totalSessions = 0;
        }

        // Нешаблонные методы
        public string GetUserName() => userName;

        public int GetTotalSessions() => totalSessions;

        public void SetStrategy(IExecutionStrategy strategy)
        {
            currentStrategy = strategy;
        }

        public IExecutionStrategy GetCurrentStrategy() => currentStrategy;

        public void PrintStatistics()
        {
            Console.WriteLine($"Пользователь: {userName}");
            Console.WriteLine($"Всего активностей: {activities.Count}");
            Console.WriteLine($"Всего сессий: {totalSessions}");
            Console.WriteLine($"Текущая стратегия: {currentStrategy.GetDescription()}");
        }

        // Шаблонные методы
        public void AddActivity<ActivityType>(ActivityType activity) where ActivityType : Activity
        {
            activities.Add(activity);
            Console.WriteLine($"Добавлена активность: {activity.Title}");
        }

        // Выполнение активности с текущей стратегией
        public void ExecuteWithStrategy(Activity activity)
        {
            currentStrategy.Execute(activity);
            totalSessions++;
        }

        // Перегруженная версия executeWithStrategy с передачей стратегии 
        public void ExecuteWithStrategy(Activity activity, IExecutionStrategy execStrategy)
        {
            Console.WriteLine($"Выполнение {activity.Title} со стратегией");
            execStrategy.Execute(activity);
            totalSessions++;
        }

        public IEnumerable<Activity> FilterActivities(Func<Activity, bool> predicate)
        {
            return activities.Where(predicate);
        }

        public List<Activity> GetActivities() => new List<Activity>(activities);
    }
}

