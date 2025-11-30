#ifndef PROFILEMANAGER_HPP
#define PROFILEMANAGER_HPP

#include <string>
#include <set>
#include <list>
#include <memory>
#include <iostream>

// Класс ProfileManager: Управляет профилем пользователя
class ProfileManager {
public:
    // Перечисления для пола, целей, уровней, дней недели и оборудования
    enum class Gender { MALE, FEMALE }; // Пол пользователя
    enum class Goal { LOSE_WEIGHT, GAIN_MASS, HEALTH }; // Цели (похудение, набор массы, здоровье)
    enum class Level { BEGINNER, INTERMEDIATE, ADVANCED }; // Уровень подготовки
    enum class Weekday { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY }; // Дни недели
    enum class Equipment { DUMBBELLS, BARBELL, BENCH }; // Оборудование

    // Дружественная функция
    friend bool operator<(Equipment lhs, Equipment rhs) {
        return static_cast<int>(lhs) < static_cast<int>(rhs);
    }

    // Дружественная функция для вывода
    friend std::ostream& operator<<(std::ostream& os, const ProfileManager& profile);

    // Конструктор: Инициализирует профиль пользователя
    ProfileManager(const std::string& id, const std::string& username, int age, Gender gender, int heightCm,
        double currentWeightKg, Goal targetGoal, Level fitnessLevel,
        const std::list<Weekday>& workoutDaysPref, const std::set<Equipment>& availableEquipment,
        bool alertsEnabled);

    // Конструктор копирования
    ProfileManager(const ProfileManager& other);

    // Деструктор: Освобождает ресурсы
    ~ProfileManager();

    // Метод: Обновляет вес пользователя
    void changeWeight(double newWeight);

    // Метод: Изменяет цель пользователя
    void updateGoal(Goal newGoal);

    // Метод: Рассчитывает индекс массы тела (BMI)
    double calculateBMI() const;

    
    const std::set<Equipment>& getAvailableEquipment() const { return availableEquipment; }

    // Перегрузка оператора ==
    bool operator==(const ProfileManager& other) const;

    // Перегрузка оператора <
    bool operator<(const ProfileManager& other) const;

    // Использование this
    ProfileManager& setUsername(const std::string& username) {
        this->username = username;
        return *this;
    }

    // Статическое поле и метод
    static int getTotalProfiles() { return totalProfiles; }

private:
    std::string id; // Уникальный идентификатор
    std::string username; // Имя пользователя
    int age; // Возраст
    Gender gender; // Пол
    int heightCm; // Рост в см
    double currentWeightKg; // Текущий вес в кг
    Goal targetGoal; // Цель
    Level fitnessLevel; // Уровень подготовки
    std::list<Weekday> workoutDaysPref; // Предпочитаемые дни тренировок
    std::set<Equipment> availableEquipment; // Доступное оборудование
    bool alertsEnabled; // Включены ли уведомления

    // Статическое поле
    static int totalProfiles;
};

#endif
