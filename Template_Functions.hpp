#ifndef TEMPLATE_FUNCTIONS_HPP
#define TEMPLATE_FUNCTIONS_HPP

#include <iostream>
#include <type_traits>
#include <stdexcept>

/*
  Шаблонная функция для расчета BMI (индекс массы тела)
  Функция вычисляет значимые данные и имеет ограничения типов
 */
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
calculateBMI(T weightKg, T heightM) {
    if (heightM <= 0) {
        throw std::invalid_argument("Вес должен быть положительным!");
    }
    return weightKg / (heightM * heightM);
}

/*
  Шаблонная функция для расчета тренировочного объема
  Ограничения: T должен быть арифметическим типом
 */
template<typename T, typename Container>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
calculateTrainingVolume(const Container& sets, const Container& reps, const Container& weights) {
    T totalVolume = T{ 0 };
    auto setsIt = sets.begin();
    auto repsIt = reps.begin();
    auto weightsIt = weights.begin();

    for (; setsIt != sets.end() && repsIt != reps.end() && weightsIt != weights.end();
        ++setsIt, ++repsIt, ++weightsIt) {
        totalVolume += (*setsIt) * (*repsIt) * (*weightsIt);
    }

    return totalVolume;
}

/*
  Демонстрационная функция
 */
void demonstrateTemplateFunctions() {
    std::cout << "\n=== Шаблонные функции ===\n";

    try {
        // Демонстрация calculateBMI
        double bmi = calculateBMI(70.0, 1.75);
        std::cout << "BMI для веса 70kg и роста 1.75m: " << bmi << std::endl;

        // Демонстрация calculateTrainingVolume
        std::vector<double> sets = { 3, 4, 3 };
        std::vector<double> reps = { 10, 8, 12 };
        std::vector<double> weights = { 50.0, 60.0, 40.0 };

        double volume = calculateTrainingVolume<double>(sets, reps, weights);
        std::cout << "Тренировочный объем: " << volume << " кг" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

#endif 
