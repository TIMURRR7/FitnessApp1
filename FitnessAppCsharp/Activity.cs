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

        // Статическая конфигурация - калькулятор по умолчанию для всех активностей
        private static ICalorieCalculator _defaultCalculator = new BasicCalorieCalculator();
        public static ICalorieCalculator DefaultCalculator
        {
            get => _defaultCalculator;
            set => _defaultCalculator = value ?? throw new ArgumentNullException(nameof(value));
        }

        private string id;
        private string title;
        private HashSet<MuscleGroup> targetMuscles = new HashSet<MuscleGroup>();
        private ActivityType category;
        private HashSet<ProfileManager.Equipment> requiredEquipment = new HashSet<ProfileManager.Equipment>();
        private Level complexity;
        private string description;

        protected int baseCaloriesPerMin = 6;

        // Делегирование поведения расчета калорий
        protected ICalorieCalculator _calorieCalculator;

        public Activity(string id, string title,
            IEnumerable<MuscleGroup> targetedMuscles = null,
            ActivityType category = ActivityType.STRENGTH,
            IEnumerable<ProfileManager.Equipment> requiredEquipment = null,
            Level complexity = Level.BEGINNER,
            string description = "",
            ICalorieCalculator calculator = null)
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

            // Делегирование: используем переданный калькулятор или калькулятор по умолчанию
            _calorieCalculator = calculator ?? _defaultCalculator;

            activityCount++;
        }

        public virtual int EstimateCalories(int durationMinutes)
        {
            // Делегирование расчета калорий калькулятору
            return _calorieCalculator.CalculateCalories(baseCaloriesPerMin, durationMinutes, category);
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
            Activity clone = (Activity)this.MemberwiseClone();
     
            return clone;
        }

        public Activity DeepClone()
        {
            Activity clone = (Activity)this.MemberwiseClone();
            clone.targetMuscles = new HashSet<MuscleGroup>(this.targetMuscles);
            clone.requiredEquipment = new HashSet<ProfileManager.Equipment>(this.requiredEquipment);        
            return clone;
        }

        
        // Динамическая конфигурация: смена калькулятора во время выполнения
      
        public void SetCalculator(ICalorieCalculator calculator)
        {
            _calorieCalculator = calculator ?? throw new ArgumentNullException(nameof(calculator));
        }

        // Получить текущий калькулятор 
        public ICalorieCalculator GetCalculator() => _calorieCalculator;

        public string Id => id;
        public string Title => title;
        public ActivityType Category => category;
        public Level Complexity => complexity;
    }
}
