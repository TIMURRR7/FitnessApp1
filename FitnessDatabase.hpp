#ifndef FITNESSDATABASE_HPP
#define FITNESSDATABASE_HPP

#include <list>
#include <string>
#include <memory>
#include "Activity.hpp"
#include "ProfileManager.hpp"

// Класс FitnessDatabase: Репозиторий упражнений
class FitnessDatabase {
public:
    // Конструктор: Инициализирует базу
    FitnessDatabase();

    // Конструктор копирования
    FitnessDatabase(const FitnessDatabase& other);

    // Деструктор: Освобождает ресурсы
    ~FitnessDatabase();

    // Метод: Поиск упражнений по названию
    std::list<std::shared_ptr<Activity>> findByName(const std::string& searchQuery) const;

    // Метод: Добавляет новое упражнение
    void addActivity(std::unique_ptr<Activity> newActivity);

private:
    std::list<std::shared_ptr<Activity>> activities; // Список упражнений
    std::string updateTimestamp; // Дата последнего обновления
};

#endif
