namespace FitnessApp2
{
    public class CardioActivity : Activity
    {
        private double distance;

        public CardioActivity(double distance)
            : base("cardio_id", "Кардио", new[] { MuscleGroup.LEGS }, ActivityType.CARDIO)
        {
            this.distance = distance;
            baseCaloriesPerMin = 10;
        }

        public override int EstimateCalories(int duration)
        {
            // Делегирование с дополнительными параметрами (дистанция для кардио)
            return _calorieCalculator.CalculateCalories(baseCaloriesPerMin, duration, Category, distance);
        }
    }
}
