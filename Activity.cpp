#include "Activity.hpp"
#include <algorithm>
#include <stdexcept>

// Конструктор: Инициализирует все поля
Activity::Activity(const std::string& id, const std::string& title, const std::set<MuscleGroup>& targetedMuscles,
    ActivityType category, const std::set<ProfileManager::Equipment>& requiredEquipment,
    ProfileManager::Level complexity, const std::string& description)
    : id(id), title(title), targetedMuscles(targetedMuscles), category(category),
    requiredEquipment(requiredEquipment), complexity(complexity), description(description) {}

// Конструктор копирования
Activity::Activity(const Activity& other)
    : id(other.id), title(other.title), targetedMuscles(other.targetedMuscles), category(other.category),
    requiredEquipment(other.requiredEquipment), complexity(other.complexity), description(other.description) {}

// Деструктор
Activity::~Activity() {}

// Метод: Проверяет наличие оборудования у пользователя
bool Activity::matchesUser(const ProfileManager& user) const {
    try {
        return std::includes(user.getAvailableEquipment().begin(), user.getAvailableEquipment().end(),
            requiredEquipment.begin(), requiredEquipment.end());
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Метод: Возвращает фиксированную оценку длительности (заглушка)
int Activity::getDurationEstimate() const {
    return 10; // Примерное значение
}

// Перегрузка оператора ==
bool Activity::operator==(const Activity& other) const {
    return this->id == other.id;
}

// Перегрузка оператора +
Activity Activity::operator+(const Activity& other) const {
    // Создаем комбинированное упражнение
    Activity combined = *this;
    combined.title = this->title + " & " + other.title;

    // Объединяем мышечные группы
    for (const auto& muscle : other.targetedMuscles) {
        combined.targetedMuscles.insert(muscle);
    }

    // Объединяем оборудование
    for (const auto& equipment : other.requiredEquipment) {
        combined.requiredEquipment.insert(equipment);
    }

    if (static_cast<int>(other.complexity) > static_cast<int>(this->complexity)) {
        combined.complexity = other.complexity;
    }

    return combined;
}
