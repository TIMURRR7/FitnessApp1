#include "DietProgram.hpp"
#include <stdexcept>


int DietProgram::totalPrograms = 0;

// Конструктор: Инициализирует все поля
DietProgram::DietProgram(const std::string& id, const std::string& ownerUserId, const std::string& planDate,
    const std::list<std::string>& dailyMeals, const std::string& dailyTargets)
    : id(id), ownerUserId(ownerUserId), planDate(planDate), dailyMeals(dailyMeals), dailyTargets(dailyTargets) {
    totalPrograms++;
}

// Конструктор копирования
DietProgram::DietProgram(const DietProgram& other)
    : id(other.id), ownerUserId(other.ownerUserId), planDate(other.planDate),
    dailyMeals(other.dailyMeals), dailyTargets(other.dailyTargets) {
    totalPrograms++;
}

// Деструктор
DietProgram::~DietProgram() {
    totalPrograms--;
}

// Метод: Обновляет по весу (заглушка)
void DietProgram::updateForWeightShift(double weightDelta) {
    try {
        // Изменение калорийности
        if (weightDelta == 0) {
            throw std::invalid_argument("Изменение не может быть нулевым");
        }
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Метод: Возвращает суммарные нутриенты (заглушка)
std::string DietProgram::calcDailySummary() const {
    return "Суммарные нутриенты: 2000 ккал"; // Пример
}

// Метод: Заменяет блюдо (заглушка)
void DietProgram::swapDish(const std::string& mealTime, const std::string& replacement) {
    try {
        if (mealTime.empty() || replacement.empty()) {
            throw std::invalid_argument("Время приема пищи и замена не могут быть пустыми");
        }
        // Замена
    }
    catch (const std::exception& e) {
        throw;
    }
}


bool DietProgram::operator==(const DietProgram& other) const {
    return this->id == other.id && this->ownerUserId == other.ownerUserId;
}
DietProgram& DietProgram::operator+=(const std::string& meal) {
    this->dailyMeals.push_back(meal);
    return *this;
}
