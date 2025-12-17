#pragma once
#include <iostream>


extern constinit int FITNESS_CONSTANTS[4];

// Простой класс для демонстрации compile-time вычислений
class CompileTimeDemo {
public:
   
    constexpr CompileTimeDemo(int val) : value(val) {}

    
    constexpr int getValue() const {
        return value * 2;
    }

    int value;
};

// consteval функция - расчет тренировочной прогрессии 
consteval int calculateTrainingProgression(int startWeight, int weeks, int weeklyIncrease) {
    int currentWeight = startWeight;
    for (int week = 0; week < weeks; ++week) {
        currentWeight += weeklyIncrease;
    }
    return currentWeight;
}

// constexpr функция - расчет потребления калорий при активности
constexpr int calculateCaloriesBurned(int baseCalories, int intensityMultiplier, int duration) {
    int totalCalories = baseCalories;
    for (int minute = 0; minute < duration; ++minute) {
        totalCalories += intensityMultiplier;
    }
    return totalCalories;
}

// Функция для демонстрации
void demonstrateCompileTimeFeatures();
