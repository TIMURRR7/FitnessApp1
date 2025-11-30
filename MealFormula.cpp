#include "MealFormula.hpp"
#include <stdexcept>

// Конструктор: Инициализирует поля
MealFormula::MealFormula(const std::string& id, const std::string& dishName, const std::list<std::string>& componentList,
    const std::string& nutritionPerPortion, int prepTimeMin)
    : id(id), dishName(dishName), componentList(componentList), nutritionPerPortion(nutritionPerPortion),
    prepTimeMin(prepTimeMin) {}

// Конструктор копирования
MealFormula::MealFormula(const MealFormula& other)
    : id(other.id), dishName(other.dishName), componentList(other.componentList),
    nutritionPerPortion(other.nutritionPerPortion), prepTimeMin(other.prepTimeMin) {}

// Деструктор: Пустой
MealFormula::~MealFormula() {}

// Метод: Пересчёт порций
std::string MealFormula::adjustPortions(double portionFactor) const {
    try {
        if (portionFactor <= 0) {
            throw std::invalid_argument("Коэффициент калорий должен быть положительным");
        }
        return "Скорректированное питание для " + std::to_string(portionFactor) + " калорий";
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Метод: Проверка предпочтений
bool MealFormula::fitsUserPrefs(const ProfileManager& user) const {
    // Пример логики проверки
    return prepTimeMin <= 30; // Например, подходит если готовится до 30 минут
}
