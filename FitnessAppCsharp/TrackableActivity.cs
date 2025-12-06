// TrackableActivity.cs
using System;
using System.Collections.Generic;

namespace FitnessApp2
{
    public class TrackableActivity : Activity, ITrackable, ICustomizable
    {
        private List<DateTime> completionDates = new List<DateTime>();
        private List<string> modifications = new List<string>();
        private bool isCompleted;

        public TrackableActivity(string id, string title, IEnumerable<MuscleGroup> targetedMuscles,
            ActivityType category, IEnumerable<ProfileManager.Equipment> requiredEquipment = null,
            Activity.Level complexity = Activity.Level.BEGINNER, string description = "")
            : base(id, title, targetedMuscles, category, requiredEquipment, complexity, description)
        {
            
        }

     
        public string GetTrackingInfo()
        {
            return $"Activity: {Title}, Completed {completionDates.Count} times, Status: {(isCompleted ? "Completed" : "In Progress")}";
        }

        public void LogProgress(DateTime date)
        {
            completionDates.Add(date);
            if (completionDates.Count >= 3) 
                isCompleted = true;
        }

        public bool IsCompleted() => isCompleted;

       
        public void AddCustomModification(string modification)
        {
            modifications.Add(modification);
        }

        public List<string> GetModifications() => new List<string>(modifications);

        public void ResetToDefault()
        {
            modifications.Clear();
            completionDates.Clear();
            isCompleted = false;
        }

    
        public override int EstimateCalories(int durationMinutes)
        {
            int baseCalories = base.EstimateCalories(durationMinutes);
       
            return baseCalories + modifications.Count * 2;
        }
    }
}
