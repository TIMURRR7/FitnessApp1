#include "StrengthActivity.hpp"
#include "StandardExecutionStrategy.hpp"
#include "ProgressiveOverloadStrategy.hpp"
#include "PyramidStrategy.hpp"
#include "ProfileManager.hpp"
#include "Activity.hpp"
#include <iostream>
#include <set>
#include <stdexcept>
#include <windows.h>
#include <memory>

int main() {
    SetConsoleOutputCP(1251);
    std::cout << "=== Демонстрация паттерна делегирования ===\n" << std::endl;

    // Создаем наборы данных для упражнения
    std::set<Activity::MuscleGroup> muscles = { Activity::MuscleGroup::CHEST };
    std::set<ProfileManager::Equipment> equipment = { ProfileManager::Equipment::DUMBBELLS };

    // 1. СТАТИЧЕСКОЕ КОНФИГУРИРОВАНИЕ
    std::cout << "1. Статическое конфигурирование стратегий:" << std::endl;
    std::cout << "==========================================" << std::endl;

    StrengthActivity standardExercise("bench_press_std", "Жим лежа (стандартный)",
        muscles, equipment, ProfileManager::Level::INTERMEDIATE, "Классический жим лежа",
        3, 10, 50.0, StrengthActivity::ExecutionType::STANDARD);

    StrengthActivity progressiveExercise("bench_press_prog", "Жим лежа (прогрессивная перегрузка)",
        muscles, equipment, ProfileManager::Level::INTERMEDIATE, "Жим с постепенным увеличением веса",
        3, 8, 45.0, StrengthActivity::ExecutionType::PROGRESSIVE_OVERLOAD);

    StrengthActivity pyramidExercise("bench_press_pyr", "Жим лежа (пирамида)",
        muscles, equipment, ProfileManager::Level::ADVANCED, "Пирамидальная тренировка",
        4, 12, 40.0, StrengthActivity::ExecutionType::PYRAMID);

    std::cout << "\n--- Выполнение стандартного упражнения ---" << std::endl;
    std::cout << "Стратегия: " << standardExercise.getExecutionStrategyDescription() << std::endl;
    standardExercise.execute();

    std::cout << "\n--- Выполнение с прогрессивной перегрузкой ---" << std::endl;
    std::cout << "Стратегия: " << progressiveExercise.getExecutionStrategyDescription() << std::endl;
    progressiveExercise.execute();

    std::cout << "\n--- Выполнение пирамидального упражнения ---" << std::endl;
    std::cout << "Стратегия: " << pyramidExercise.getExecutionStrategyDescription() << std::endl;
    pyramidExercise.execute();

    // 2. ДИНАМИЧЕСКОЕ КОНФИГУРИРОВАНИЕ
    std::cout << "\n\n2. Динамическое конфигурирование стратегий:" << std::endl;
    std::cout << "==============================================" << std::endl;

    StrengthActivity dynamicExercise("squat_dyn", "Приседания (динамическая стратегия)",
        { Activity::MuscleGroup::LEGS }, { ProfileManager::Equipment::BARBELL },
        ProfileManager::Level::BEGINNER, "Приседания со штангой", 3, 12, 60.0);

    std::cout << "\n--- Исходная стратегия ---" << std::endl;
    std::cout << "Стратегия: " << dynamicExercise.getExecutionStrategyDescription() << std::endl;
    dynamicExercise.execute();

    std::cout << "\n--- Смена стратегии на прогрессивную перегрузку ---" << std::endl;
    dynamicExercise.setExecutionStrategy(std::make_unique<ProgressiveOverloadStrategy>(5.0));
    std::cout << "Новая стратегия: " << dynamicExercise.getExecutionStrategyDescription() << std::endl;
    dynamicExercise.execute();

    std::cout << "\n--- Смена стратегии на пирамидальную ---" << std::endl;
    dynamicExercise.setExecutionStrategy(std::make_unique<PyramidStrategy>(10.0, 3));
    std::cout << "Новая стратегия: " << dynamicExercise.getExecutionStrategyDescription() << std::endl;
    dynamicExercise.execute();

   
    return 0;
}
