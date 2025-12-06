using System;

namespace FitnessApp2
{
    public class BalanceActivity : Activity
    {
        private int balanceDifficulty; /

        public BalanceActivity(int balanceDifficulty)
            : base("balance_id", "Баланс", new[] { MuscleGroup.CORE, MuscleGroup.LEGS }, ActivityType.BALANCE,
                   null, Activity.Level.INTERMEDIATE, "Упражнения на равновесие")
        {
            this.balanceDifficulty = Math.Clamp(balanceDifficulty, 1, 10);
            baseCaloriesPerMin = 5;
        }

        public override int EstimateCalories(int durationMinutes)
        {
            return durationMinutes * 5 + balanceDifficulty * 2;
        }

        public int GetBalanceDifficulty() => balanceDifficulty;

        protected void IncreaseDifficulty()
        {
            if (balanceDifficulty < 10)
                balanceDifficulty++;
        }
    }
}
