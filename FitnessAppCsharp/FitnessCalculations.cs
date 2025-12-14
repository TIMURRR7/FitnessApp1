using System;
using System.Collections.Generic;

namespace FitnessApp2
{
    // Обобщенные функции вне классов с ограничениями типов
    public static class FitnessCalculations
    {
        // Шаблонная функция для расчета BMI (индекс массы тела)
        // Ограничение: T должен быть числовым типом
        public static T CalculateBMI<T>(T weightKg, T heightM) where T : struct, IComparable<T>, IConvertible
        {
            if (Convert.ToDouble(heightM) <= 0)
                throw new ArgumentException("Рост должен быть положительным!");

            double weight = Convert.ToDouble(weightKg);
            double height = Convert.ToDouble(heightM);
            return (T)Convert.ChangeType(weight / (height * height), typeof(T));
        }

        // Шаблонная функция для расчета тренировочного объема
        // Ограничение: T должен быть числовым типом
        public static T CalculateTrainingVolume<T>(IEnumerable<T> sets, IEnumerable<T> reps, IEnumerable<T> weights)
            where T : struct, IComparable<T>, IConvertible
        {
            T totalVolume = default(T);
            using (var setsEnum = sets.GetEnumerator())
            using (var repsEnum = reps.GetEnumerator())
            using (var weightsEnum = weights.GetEnumerator())
            {
                while (setsEnum.MoveNext() && repsEnum.MoveNext() && weightsEnum.MoveNext())
                {
                    double setVal = Convert.ToDouble(setsEnum.Current);
                    double repVal = Convert.ToDouble(repsEnum.Current);
                    double weightVal = Convert.ToDouble(weightsEnum.Current);
                    totalVolume = (T)Convert.ChangeType(
                        Convert.ToDouble(totalVolume) + (setVal * repVal * weightVal), typeof(T));
                }
            }
            return totalVolume;
        }

        // Шаблонная функция для расчета интенсивности упражнения
        // Ограничение: T должен быть числовым типом
        public static T CalculateIntensityPercentage<T>(T currentWeight, T maxWeight) where T : struct, IComparable<T>, IConvertible
        {
            double current = Convert.ToDouble(currentWeight);
            double max = Convert.ToDouble(maxWeight);

            if (max <= 0)
                throw new ArgumentException("Максимальный вес должен быть положительным!");

            return (T)Convert.ChangeType((current / max) * 100.0, typeof(T));
        }
    }
}
