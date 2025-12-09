namespace FitnessApp2
{
    public class StrengthActivity : Activity
    {
        public int Reps { get; set; }

        public StrengthActivity(int reps)
            : base("strength_id", "Силовое", new[] { MuscleGroup.CHEST }, ActivityType.STRENGTH,
                   new[] { ProfileManager.Equipment.Dumbbells })
        {
            Reps = reps;
        }

        public override int EstimateCalories(int duration)
        {
            // Делегирование с дополнительными параметрами (повторения для силовых)
            return _calorieCalculator.CalculateCalories(baseCaloriesPerMin, duration, Category, Reps);
        }
    }
}
