using System;

namespace FitnessApp2
{
    // Реализации стратегий выполнения
    public class StandardExecutionStrategy : IExecutionStrategy
    {
        public void Execute(Activity activity)
        {
            Console.WriteLine($"Выполнение стандартной тренировки: {activity.Title}");
        }

        public string GetDescription() => "Стандартная стратегия выполнения";
    }

    public class ProgressiveOverloadStrategy : IExecutionStrategy
    {
        public void Execute(Activity activity)
        {
            Console.WriteLine($"Выполнение с прогрессивной перегрузкой: {activity.Title}");
        }

        public string GetDescription() => "Стратегия прогрессивной перегрузки";
    }
}
