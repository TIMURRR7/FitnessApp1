#include "ProfileManager.hpp"
#include <cmath>
#include <stdexcept>

// Инициализация статического поля
int ProfileManager::totalProfiles = 0;

// Конструктор: Инициализирует все поля класса
ProfileManager::ProfileManager(const std::string& id, const std::string& username, int age, Gender gender, int heightCm,
    double currentWeightKg, Goal targetGoal, Level fitnessLevel,
    const std::list<Weekday>& workoutDaysPref, const std::set<Equipment>& availableEquipment,
    bool alertsEnabled)
    : id(id), username(username), age(age), gender(gender), heightCm(heightCm), currentWeightKg(currentWeightKg),
    targetGoal(targetGoal), fitnessLevel(fitnessLevel), workoutDaysPref(workoutDaysPref),
    availableEquipment(availableEquipment), alertsEnabled(alertsEnabled) {
    totalProfiles++;
}

// Конструктор копирования
ProfileManager::ProfileManager(const ProfileManager& other)
    : id(other.id), username(other.username), age(other.age), gender(other.gender),
    heightCm(other.heightCm), currentWeightKg(other.currentWeightKg), targetGoal(other.targetGoal),
    fitnessLevel(other.fitnessLevel), workoutDaysPref(other.workoutDaysPref),
    availableEquipment(other.availableEquipment), alertsEnabled(other.alertsEnabled) {
    totalProfiles++;
}

// Деструктор
ProfileManager::~ProfileManager() {
    totalProfiles--;
}

// Метод: Обновляет текущий вес
void ProfileManager::changeWeight(double newWeight) {
    if (newWeight <= 0) {
        throw std::invalid_argument("Вес должен быть положительным");
    }
    currentWeightKg = newWeight;
}

// Метод: Обновляет цель
void ProfileManager::updateGoal(Goal newGoal) {
    targetGoal = newGoal;
}

// Метод: Рассчитывает BMI по формуле вес / (рост^2)
double ProfileManager::calculateBMI() const {
    try {
        if (heightCm <= 0) {
            throw std::runtime_error("Рост должен быть положительным");
        }
        double heightM = heightCm / 100.0;
        return currentWeightKg / (heightM * heightM);
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Перегрузка оператора ==
bool ProfileManager::operator==(const ProfileManager& other) const {
    return this->id == other.id && this->username == other.username;
}

// Перегрузка оператора <
bool ProfileManager::operator<(const ProfileManager& other) const {
    return this->username < other.username;
}

// Дружественная функция
std::ostream& operator<<(std::ostream& os, const ProfileManager& profile) {
    os << "Профиль: " << profile.username << " (ID: " << profile.id << ")";
    return os;
}
