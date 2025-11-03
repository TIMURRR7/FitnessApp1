#ifndef FITNESSDATABASE_HPP
#define FITNESSDATABASE_HPP

#include <list>
#include <string>
#include "Activity.hpp"
#include "ProfileManager.hpp"

// Класс FitnessDatabase: Репозиторий упражнений
class FitnessDatabase {
public:
    // Конструктор: Инициализирует базу 
    FitnessDatabase();

    // Деструктор: Освобождает ресурсы
    ~FitnessDatabase();

    // Метод: Поиск упражнений по названию
    std::list<Activity> findByName(const std::string& searchQuery) const;

    // Метод: Фильтрация упражнений по цели, оборудованию и уровню
    std::list<Activity> filterActivities(ProfileManager::Goal targetGoal, const std::set<ProfileManager::Equipment>& equip, ProfileManager::Level lvl) const;

    // Метод: Добавляет новое упражнение
    void addActivity(const Activity& newActivity);

    // Метод: Обновляет всю библиотеку упражнений
    void updateLibrary(const std::list<Activity>& newActivities);

private:
    std::list<Activity> activities; // Список упражнений
    std::string updateTimestamp; // Дата последнего обновления
};

#endif
