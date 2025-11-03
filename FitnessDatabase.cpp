#include "FitnessDatabase.hpp"

// Конструктор: Устанавливает дату обновления по умолчанию
FitnessDatabase::FitnessDatabase() : updateTimestamp("2025-10-21") {}

// Деструктор
FitnessDatabase::~FitnessDatabase() {}

// Метод: Поиск по названию (заглушка)
std::list<Activity> FitnessDatabase::findByName(const std::string& searchQuery) const {
    std::list<Activity> result;
    return result;
}

// Метод: Фильтрация (заглушка)
std::list<Activity> FitnessDatabase::filterActivities(ProfileManager::Goal targetGoal, const std::set<ProfileManager::Equipment>& equip, ProfileManager::Level lvl) const {
    std::list<Activity> result;
    // Фильтрация
    return result;
}

// Метод: Добавляет упражнение
void FitnessDatabase::addActivity(const Activity& newActivity) {
    activities.push_back(newActivity);
}

// Метод: Обновляет библиотеку
void FitnessDatabase::updateLibrary(const std::list<Activity>& newActivities) {
    activities = newActivities;
}
