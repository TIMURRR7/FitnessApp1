using System;

namespace FitnessApp2
{
    public class FlexibilityActivity : Activity
    {
        private int stretchDuration; 

        public FlexibilityActivity(int stretchDuration)
            : base("flex_id", "Гибкость", new[] { MuscleGroup.LEGS, MuscleGroup.ARMS }, ActivityType.FLEXIBILITY,
                   null, Activity.Level.BEGINNER, "Упражнения на растяжку")
        {
            this.stretchDuration = stretchDuration;
            baseCaloriesPerMin = 4; 
        }

        public override int EstimateCalories(int durationMinutes)
        {
           
            return base.EstimateCalories(durationMinutes) - 2;
        }

        public int GetStretchDuration() => stretchDuration;

        protected void AdjustStretchDuration(int adjustment)
        {
            stretchDuration += adjustment;
        }
    }
}
