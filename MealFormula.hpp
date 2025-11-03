#ifndef MEALFORMULA_HPP
#define MEALFORMULA_HPP

#include <string>
#include <list>
#include "ProfileManager.hpp" 

// Класс MealFormula: Рецепт блюда
class MealFormula {
public:
    // Конструктор: Инициализирует рецепт
    MealFormula(const std::string& id, const std::string& dishName, const std::list<std::string>& componentList,
        const std::string& nutritionPerPortion, int prepTimeMin);

    // Деструктор
    ~MealFormula();

    // Метод: Пересчитывает нутриенты на порции 
    std::string adjustPortions(double portionFactor) const;

    // Метод: Проверяет соответствие предпочтениям пользователя
    bool fitsUserPrefs(const ProfileManager& user) const;

private:
    std::string id; // Идентификатор
    std::string dishName; // Название блюда
    std::list<std::string> componentList; // Ингредиенты
    std::string nutritionPerPortion; // Нутриенты на порцию
    int prepTimeMin; // Время приготовления в минутах
};

#endif
