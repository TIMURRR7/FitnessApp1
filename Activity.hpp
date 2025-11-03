#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <string>
#include <set>
#include "ProfileManager.hpp" 

// Класс Activity: Описание упражнения
class Activity {
public:
    enum class MuscleGroup { CHEST, BACK, LEGS }; // Мышечные группы 
    enum class ActivityType { STRENGTH, CARDIO }; // Тип активности

    // Конструктор: Инициализирует упражнение
    Activity(const std::string& id, const std::string& title, const std::set<MuscleGroup>& targetedMuscles,
        ActivityType category, const std::set<ProfileManager::Equipment>& requiredEquipment, ProfileManager::Level complexity,
        const std::string& description);

    // Деструктор
    ~Activity();

    // Метод: Проверяет, подходит ли упражнение пользователю
    bool matchesUser(const ProfileManager& user) const;

    // Метод: Возвращает оценку длительности
    int getDurationEstimate() const;

private:
    std::string id; // Идентификатор
    std::string title; // Название
    std::set<MuscleGroup> targetedMuscles; // Задействованные мышцы
    ActivityType category; // Тип
    std::set<ProfileManager::Equipment> requiredEquipment; // Необходимое оборудование
    ProfileManager::Level complexity; // Сложность
    std::string description; // Описание
};

#endif
