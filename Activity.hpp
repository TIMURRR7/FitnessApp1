#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <string>
#include <set>
#include <vector>
#include "ProfileManager.hpp"

class Activity {
public:
    enum class MuscleGroup { CHEST, BACK, LEGS, SHOULDERS, ARMS, CORE };
    enum class ActivityType { STRENGTH, CARDIO, FLEXIBILITY, BALANCE };

    Activity() = default;
    Activity(const std::string& id, const std::string& title,
        const std::set<MuscleGroup>& targetedMuscles = {},
        ActivityType type = ActivityType::STRENGTH,
        const std::set<ProfileManager::Equipment>& equipment = {},
        ProfileManager::Level level = ProfileManager::Level::BEGINNER,
        const std::string& description = "");

    Activity(const Activity& other) = default;
    virtual ~Activity() = default;

    virtual int estimateCalories(int durationMinutes) const;

    std::vector<Activity> findSimilar(ActivityType type) const;
    bool isCompatible(const ProfileManager& user) const;

    Activity deepClone() const;

    bool operator==(const Activity& other) const { return id == other.id; }

    const std::string& getTitle() const { return title; }

protected:
    int baseCaloriesPerMin = 6;

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
