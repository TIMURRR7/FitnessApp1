#include "MealFormula.hpp"

// Конструктор: Инициализирует поля
MealFormula::MealFormula(const std::string& id, const std::string& dishName, const std::list<std::string>& componentList,
    const std::string& nutritionPerPortion, int prepTimeMin)
    : id(id), dishName(dishName), componentList(componentList), nutritionPerPortion(nutritionPerPortion),
    prepTimeMin(prepTimeMin) {}

// Деструктор: Пустой
MealFormula::~MealFormula() {}

// Метод: Пересчёт порций (заглушка)
std::string MealFormula::adjustPortions(double portionFactor) const {
    return "Adjusted"; // Пример
}

// Метод: Проверка предпочтений (заглушка)
bool MealFormula::fitsUserPrefs(const ProfileManager& user) const {
    return true;
}
