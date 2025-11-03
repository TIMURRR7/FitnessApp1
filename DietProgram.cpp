#include "DietProgram.hpp"

// Конструктор: Инициализирует все поля
DietProgram::DietProgram(const std::string& id, const std::string& ownerUserId, const std::string& planDate,
    const std::list<std::string>& dailyMeals, const std::string& dailyTargets)
    : id(id), ownerUserId(ownerUserId), planDate(planDate), dailyMeals(dailyMeals), dailyTargets(dailyTargets) {}

// Деструктор
DietProgram::~DietProgram() {}

// Метод: Обновляет по весу (заглушка)
void DietProgram::updateForWeightShift(double weightDelta) {
    // Изменение калорийности
}

// Метод: Возвращает суммарные нутриенты (заглушка)
std::string DietProgram::calcDailySummary() const {
    return "Summary"; // Пример
}

// Метод: Заменяет блюдо (заглушка)
void DietProgram::swapDish(const std::string& mealTime, const std::string& replacement) {
    // Замена
}
