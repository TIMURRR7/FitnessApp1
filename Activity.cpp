#include "Activity.hpp"
#include <algorithm>

// Конструктор: Инициализирует все поля
Activity::Activity(const std::string& id, const std::string& title, const std::set<MuscleGroup>& targetedMuscles,
    ActivityType category, const std::set<ProfileManager::Equipment>& requiredEquipment, ProfileManager::Level complexity,
    const std::string& description)
    : id(id), title(title), targetedMuscles(targetedMuscles), category(category),
    requiredEquipment(requiredEquipment), complexity(complexity), description(description) {}

// Деструктор
Activity::~Activity() {}

// Метод: Проверяет наличие оборудования у пользователя
bool Activity::matchesUser(const ProfileManager& user) const {
    return std::includes(user.getAvailableEquipment().begin(), user.getAvailableEquipment().end(),
        requiredEquipment.begin(), requiredEquipment.end());
}

// Метод: Возвращает фиксированную оценку длительности (заглушка)
int Activity::getDurationEstimate() const {
    return 10; // Примерное значение
}
