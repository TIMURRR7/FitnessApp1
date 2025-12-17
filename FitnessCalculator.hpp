#pragma once
#include <iostream>
#include <string>


class FitnessCalculator {
private:
    // constinit статические члены - статическая инициализация
    static constinit int MAX_HEART_RATE_BASE;
    static constinit double WATER_INTAKE_PER_KG;

public:
    // constexpr конструктор - вычисляемые выражения в конструкторе
    constexpr FitnessCalculator(double weight, double height, int age, bool isMale)
        : weight(weight), height(height), age(age), isMale(isMale),
        bmi(calculateBMI(weight, height)),
        idealWeight(calculateIdealWeight(height, isMale)),
        waterIntake(calculateWaterIntake(weight)),
        bmr(calculateBMR(weight, height, age, isMale))
    {}

    // constexpr методы с вычисляемыми выражениями
    constexpr double getBMI() const { return bmi; }
    constexpr double getIdealWeight() const { return idealWeight; }
    constexpr double getWaterIntake() const { return waterIntake; }
    constexpr double getBMR() const { return bmr; }

    // constexpr метод для расчета зон пульса
    constexpr void getHeartRateZones(int& minZone1, int& maxZone1, int& minZone2, int& maxZone2) const {
        calculateHeartRateZones(age, 65, minZone1, maxZone1, minZone2, maxZone2);
    }

    // constexpr метод для определения категории веса
    constexpr const char* getWeightCategory() const {
        return getBMICategory(bmi);
    }

private:
    double weight, height;
    int age;
    bool isMale;

    // Вычисляемые constexpr члены - инициализируются в конструкторе
    double bmi;
    double idealWeight;
    double waterIntake;
    double bmr;

public:
    // constexpr функция для расчета идеального веса по формуле Брока
    constexpr static double calculateIdealWeight(double height, bool isMale) {
        double baseWeight = height - 100.0;
        return isMale ? baseWeight - (baseWeight * 0.1) : baseWeight - (baseWeight * 0.15);
    }

    // constexpr функция для расчета дневной нормы воды
    constexpr static double calculateWaterIntake(double weight) {
        return weight * 30.0; // 30 мл на кг веса
    }

    // constexpr функция для расчета BMI
    constexpr static double calculateBMI(double weight, double height) {
        return weight / ((height / 100.0) * (height / 100.0));
    }

    // constexpr функция для определения категории BMI
    constexpr static const char* getBMICategory(double bmi) {
        if (bmi < 18.5) return "Недостаточный вес";
        if (bmi < 25.0) return "Нормальный вес";
        if (bmi < 30.0) return "Избыточный вес";
        return "Ожирение";
    }

    // constexpr функция для расчета базового метаболизма (BMR)
    constexpr static double calculateBMR(double weight, double height, double age, bool isMale) {
        double base = 10.0 * weight + 6.25 * height - 5.0 * age;
        return isMale ? base + 5.0 : base - 161.0;
    }

    // constexpr функция для расчета зон пульса
    constexpr static void calculateHeartRateZones(int age, int restingHR,
        int& zone1Min, int& zone1Max,
        int& zone2Min, int& zone2Max) {
        int maxHR = 220 - age;
        int heartRateReserve = maxHR - restingHR;

        zone1Min = restingHR + static_cast<int>(heartRateReserve * 0.5);
        zone1Max = restingHR + static_cast<int>(heartRateReserve * 0.7);
        zone2Min = restingHR + static_cast<int>(heartRateReserve * 0.7);
        zone2Max = restingHR + static_cast<int>(heartRateReserve * 0.85);
    }

    // Функция для демонстрации расчетов
    static void demonstrateFitnessCalculations();
};
