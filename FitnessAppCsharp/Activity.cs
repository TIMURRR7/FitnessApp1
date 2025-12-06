// Activity.cs
using System;
using System.Collections.Generic;
using System.Linq;

namespace FitnessApp2
{
    public class Activity : ICloneable
    {
        public enum MuscleGroup { CHEST, BACK, LEGS, SHOULDERS, ARMS, CORE }
        public enum ActivityType { STRENGTH, CARDIO, FLEXIBILITY, BALANCE }
        public enum Level { BEGINNER, INTERMEDIATE, ADVANCED }

        private static int activityCount = 0;
        public static int GetActivityCount() => activityCount;

        private string id;
        private string title;
        private HashSet<MuscleGroup> targetMuscles = new HashSet<MuscleGroup>();
        private ActivityType category;
        private HashSet<ProfileManager.Equipment> requiredEquipment = new HashSet<ProfileManager.Equipment>();
        private Level complexity;
        private string description;

        protected int baseCaloriesPerMin = 6;

        public Activity(string id, string title,
            IEnumerable<MuscleGroup> targetedMuscles = null,
            ActivityType category = ActivityType.STRENGTH,
            IEnumerable<ProfileManager.Equipment> requiredEquipment = null,
            Level complexity = Level.BEGINNER,
            string description = "")
        {
            this.id = id;
            this.title = title;
            this.category = category;
            this.complexity = complexity;
            this.description = description ?? "";

            if (targetedMuscles != null)
                this.targetMuscles = new HashSet<MuscleGroup>(targetedMuscles);
            if (requiredEquipment != null)
                this.requiredEquipment = new HashSet<ProfileManager.Equipment>(requiredEquipment);

            activityCount++;
        }

        public virtual int EstimateCalories(int durationMinutes)
        {
            return baseCaloriesPerMin * durationMinutes;
        }

        public List<Activity> FindSimilar(ActivityType type)
        {
            return new List<Activity>();
        }

        public bool IsCompatible(ProfileManager user)
        {
            if (user == null) return false;
            try
            {
                if ((int)this.complexity > (int)user.FitnessLevel) return false;
                return requiredEquipment.All(eq => user.GetAvailableEquipment().Contains(eq));
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при проверке совместимости: {ex.Message}");
                return false;
            }
        }

        public object Clone()
        {
            return this.MemberwiseClone();
        }

        public Activity DeepClone()
        {
            Activity clone = (Activity)this.MemberwiseClone();
            clone.targetMuscles = new HashSet<MuscleGroup>(this.targetMuscles);
            clone.requiredEquipment = new HashSet<ProfileManager.Equipment>(this.requiredEquipment);
            return clone;
        }

        public string Id => id;
        public string Title => title;
        public ActivityType Category => category;
        public Level Complexity => complexity;
    }
}
