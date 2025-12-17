#include "FitnessCalculator.hpp"
#include <iostream>
#include <iomanip>

// Определения статических constinit членов
constinit int FitnessCalculator::MAX_HEART_RATE_BASE = 220;
constinit double FitnessCalculator::WATER_INTAKE_PER_KG = 30.0;

void FitnessCalculator::demonstrateFitnessCalculations() {
    std::cout << "\n=== ПРОСТОЙ ФИТНЕС-КАЛЬКУЛЯТОР ===\n";

    // Тестовые данные
    constexpr double weight = 75.0;    // вес в кг
    constexpr double height = 175.0;   // рост в см
    constexpr int age = 30;           // возраст
    constexpr int restingHR = 65;     // пульс в покое

    std::cout << "Тестовые данные пользователя:" << std::endl;
    std::cout << "Вес: " << weight << " кг, Рост: " << height << " см" << std::endl;
    std::cout << "Возраст: " << age << " лет, Пульс в покое: " << restingHR << " уд/мин" << std::endl;

    // 1. Расчет BMI 
    std::cout << "\n1. ИНДЕКС МАССЫ ТЕЛА (BMI):" << std::endl;
    constexpr double bmi = FitnessCalculator::calculateBMI(weight, height);
    constexpr const char* category = FitnessCalculator::getBMICategory(bmi);
    std::cout << "BMI: " << std::fixed << std::setprecision(1) << bmi << " - " << category << std::endl;

    // 2. Расчет идеального веса 
    std::cout << "\n2. ИДЕАЛЬНЫЙ ВЕС (формула Брока):" << std::endl;
    constexpr double idealWeightMale = FitnessCalculator::calculateIdealWeight(height, true);
    constexpr double idealWeightFemale = FitnessCalculator::calculateIdealWeight(height, false);
    std::cout << "Для мужчин: " << std::fixed << std::setprecision(1) << idealWeightMale << " кг" << std::endl;
    std::cout << "Для женщин: " << std::fixed << std::setprecision(1) << idealWeightFemale << " кг" << std::endl;

    // 3. Расчет дневной нормы воды 
    std::cout << "\n3. ДНЕВНАЯ НОРМА ВОДЫ:" << std::endl;
    constexpr double waterIntake = FitnessCalculator::calculateWaterIntake(weight);
    std::cout << "Рекомендуемая норма: " << std::fixed << std::setprecision(0) << waterIntake << " мл в день" << std::endl;

    // 4. Расчет зон пульса 
    std::cout << "\n4. ЗОНЫ ПУЛЬСА:" << std::endl;
    int zone1Min, zone1Max, zone2Min, zone2Max;
    FitnessCalculator::calculateHeartRateZones(age, restingHR, zone1Min, zone1Max, zone2Min, zone2Max);
    std::cout << "Легкая зона: " << zone1Min << "-" << zone1Max << " уд/мин" << std::endl;
    std::cout << "Интенсивная зона: " << zone2Min << "-" << zone2Max << " уд/мин" << std::endl;

    // 5. Расчет BMR 
    std::cout << "\n5. БАЗОВЫЙ МЕТАБОЛИЗМ (BMR):" << std::endl;
    constexpr double bmrMale = FitnessCalculator::calculateBMR(weight, height, age, true);
    constexpr double bmrFemale = FitnessCalculator::calculateBMR(weight, height, age, false);
    std::cout << "Для мужчин: " << std::fixed << std::setprecision(0) << bmrMale << " ккал/день" << std::endl;
    std::cout << "Для женщин: " << std::fixed << std::setprecision(0) << bmrFemale << " ккал/день" << std::endl;

    // 6. constexpr класс 
    std::cout << "\n6. constexpr класс с вычисляемыми выражениями:" << std::endl;

    // constexpr объект - все расчеты выполняются на этапе компиляции
    constexpr FitnessCalculator user(75.0, 175.0, 30, true);

    std::cout << "   BMI: " << std::fixed << std::setprecision(1) << user.getBMI()
        << " (" << user.getWeightCategory() << ")" << std::endl;
    std::cout << "   Идеальный вес: " << user.getIdealWeight() << " кг" << std::endl;
    std::cout << "   Норма воды: " << std::fixed << std::setprecision(0) << user.getWaterIntake() << " мл" << std::endl;
    std::cout << "   BMR: " << user.getBMR() << " ккал/день" << std::endl;

    // Расчет зон пульса
    int min1, max1, min2, max2;
    user.getHeartRateZones(min1, max1, min2, max2);
    std::cout << "   Зоны пульса: " << min1 << "-" << max1 << " (легкая), "
        << min2 << "-" << max2 << " (интенсивная)" << std::endl;

    std::cout << "\n=== Все расчеты выполняются на этапе компиляции! ===" << std::endl;
    
}
