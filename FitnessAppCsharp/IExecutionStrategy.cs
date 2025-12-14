namespace FitnessApp2
{
    // Интерфейс для стратегий выполнения тренировок
    public interface IExecutionStrategy
    {
        void Execute(Activity activity);
        string GetDescription();
    }
}
