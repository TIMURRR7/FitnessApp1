#include "ProfileManager.hpp"
#include <cmath>

// Конструктор: Инициализирует все поля класса
ProfileManager::ProfileManager(const std::string& id, const std::string& username, int age, Gender gender, int heightCm,
    double currentWeightKg, Goal targetGoal, Level fitnessLevel,
    const std::list<Weekday>& workoutDaysPref, const std::set<Equipment>& availableEquipment,
    bool alertsEnabled)
    : id(id), username(username), age(age), gender(gender), heightCm(heightCm), currentWeightKg(currentWeightKg),
    targetGoal(targetGoal), fitnessLevel(fitnessLevel), workoutDaysPref(workoutDaysPref),
    availableEquipment(availableEquipment), alertsEnabled(alertsEnabled) {}

// Деструктор
ProfileManager::~ProfileManager() {}

// Метод: Обновляет текущий вес
void ProfileManager::changeWeight(double newWeight) {
    currentWeightKg = newWeight;
}

// Метод: Обновляет цель
void ProfileManager::updateGoal(Goal newGoal) {
    targetGoal = newGoal;
}

// Метод: Рассчитывает BMI по формуле вес / (рост^2)
double ProfileManager::calculateBMI() const {
    double heightM = heightCm / 100.0;
    return currentWeightKg / (heightM * heightM);
}
