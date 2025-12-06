// CardioActivity.cs
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
            return (int)(duration * 10 + baseCaloriesPerMin);
        }
    }
}
