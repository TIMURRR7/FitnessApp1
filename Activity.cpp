#include "Activity.hpp"
#include <algorithm>

Activity::Activity(const std::string& id, const std::string& title,
    const std::set<MuscleGroup>& targetedMuscles,
    ActivityType type,
    const std::set<ProfileManager::Equipment>& equipment,
    ProfileManager::Level level,
    const std::string& description)
    : id(id), title(title), targetMuscles(targetedMuscles), type(type),
    requiredEquipment(equipment), complexity(level), description(description)
{}

int Activity::estimateCalories(int durationMinutes) const {
    return baseCaloriesPerMin * durationMinutes;
}

std::vector<Activity> Activity::findSimilar(ActivityType type) const {
    return {};
}

bool Activity::isCompatible(const ProfileManager& user) const {
    return std::includes(user.getAvailableEquipment().begin(),
        user.getAvailableEquipment().end(),
        requiredEquipment.begin(),
        requiredEquipment.end());
}

Activity Activity::deepClone() const {
    return *this;
} 
