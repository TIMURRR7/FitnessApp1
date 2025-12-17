#include "CompileTimeDemo.hpp"
#include <iostream>

// constinit переменная - определение
constinit int FITNESS_CONSTANTS[4] = { 30, 220, 88, 447 }; // вода/мл, макс.пульс, константы BMR

void demonstrateCompileTimeFeatures() {
    std::cout << "\n=== Демонстрация constexpr, consteval и constinit в фитнес-контексте ===\n";

    // 0. constinit переменная - статическая инициализация констант
    std::cout << "\n0. constinit переменные - константы фитнес-расчетов:" << std::endl;
    std::cout << "   Ежедневная норма воды: " << FITNESS_CONSTANTS[0] << " мл/кг" << std::endl;
    std::cout << "   Формула максимального пульса: возраст вычитаем из " << FITNESS_CONSTANTS[1] << std::endl;
    std::cout << "   Константы BMR: " << FITNESS_CONSTANTS[2] << " (муж) и " << FITNESS_CONSTANTS[3] << " (жен)" << std::endl;

    // 1. consteval функция - расчет прогрессии весов в тренировках
    std::cout << "\n1. consteval функция - прогрессия тренировочных весов:" << std::endl;
    std::cout << "   Начальный вес: 50 кг, 8 недель, +2 кг в неделю" << std::endl;
    constexpr int finalWeight = calculateTrainingProgression(50, 8, 2); 
    std::cout << "   Финальный вес через 8 недель: " << finalWeight << " кг" << std::endl;

    // 2. constexpr функция - расчет сжигаемых калорий
    std::cout << "\n2. constexpr функция - расчет калорий:" << std::endl;

    // Вычисление на этапе компиляции
    constexpr int compileTimeCalories = calculateCaloriesBurned(300, 5, 30); // базовые 300 + 5*30
    std::cout << "   На этапе компиляции: 30 мин бега = " << compileTimeCalories << " ккал" << std::endl;

    // Вычисление во время выполнения
    int baseCalories = 200, intensity = 8;
    int runtimeCalories = calculateCaloriesBurned(baseCalories, intensity, 45);
    std::cout << "   Во время выполнения: 45 мин плавания = " << runtimeCalories << " ккал" << std::endl;

    // 3. constexpr объект - тренировочная программа
    std::cout << "\n3. constexpr объект - тренировочная сессия:" << std::endl;

    // constexpr объект - создается на этапе компиляции
    constexpr CompileTimeDemo workoutSession(12); // 12 упражнений
    constexpr int totalSets = workoutSession.getValue(); // 24 подхода (12*2)

    std::cout << "   constexpr сессия: " << workoutSession.value << " упражнений = " << totalSets << " подходов" << std::endl;

    
    CompileTimeDemo runtimeSession(8);
    int runtimeSets = runtimeSession.getValue();
    std::cout << "   Обычная сессия: " << runtimeSession.value << " упражнений = " << runtimeSets << " подходов" << std::endl;

    std::cout << "\n=== Применение в фитнесе ===" << std::endl;
    std::cout << "• constinit: статические константы (нормы воды, формулы пульса)" << std::endl;
    std::cout << "• consteval: планирование тренировок, расчет прогрессии" << std::endl;
    std::cout << "• constexpr: подсчет калорий, расчет нагрузки" << std::endl;
}
