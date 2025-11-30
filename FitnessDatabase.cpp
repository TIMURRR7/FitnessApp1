#include "FitnessDatabase.hpp"
#include <algorithm>
#include <stdexcept>

// Конструктор: Устанавливает дату обновления по умолчанию
FitnessDatabase::FitnessDatabase() : updateTimestamp("2025-10-21") {}

// Конструктор копирования
FitnessDatabase::FitnessDatabase(const FitnessDatabase& other)
    : activities(other.activities), updateTimestamp(other.updateTimestamp) {}

// Деструктор
FitnessDatabase::~FitnessDatabase() {}

// Метод: Поиск по названию (заглушка)
std::list<std::shared_ptr<Activity>> FitnessDatabase::findByName(const std::string& searchQuery) const {
    try {
        if (searchQuery.empty()) {
            throw std::invalid_argument("Поисковый запрос не может быть пустым");
        }
        std::list<std::shared_ptr<Activity>> result;
        return result;
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Метод: Добавляет упражнение
void FitnessDatabase::addActivity(std::unique_ptr<Activity> newActivity) {
    try {
        if (!newActivity) {
            throw std::invalid_argument("Упражнение не может быть пустым");
        }
        activities.push_back(std::shared_ptr<Activity>(std::move(newActivity)));
    }
    catch (const std::exception& e) {
        throw;
    }
}
