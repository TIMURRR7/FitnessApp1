#include "StrengthActivity.hpp"
#include "StandardExecutionStrategy.hpp"
#include "ProgressiveOverloadStrategy.hpp"
#include "PyramidStrategy.hpp"
#include <iostream>
#include <algorithm>

StrengthActivity::StrengthActivity(const std::string& id, const std::string& title,
    const std::set<MuscleGroup>& targetedMuscles,
    const std::set<ProfileManager::Equipment>& requiredEquipment,
    ProfileManager::Level complexity, const std::string& description,
    int sets, int reps, double weightKg, ExecutionType execType)
    : Activity(id, title, targetedMuscles, ActivityType::STRENGTH, requiredEquipment, complexity, description),
    sets(sets), reps(reps), weightKg(weightKg), executionStrategy(createStrategy(execType)) {}

StrengthActivity::StrengthActivity(const StrengthActivity& other)
    : Activity(other), sets(other.sets), reps(other.reps), weightKg(other.weightKg) {}


StrengthActivity& StrengthActivity::operator=(const Activity& other) {
    if (this != &other) {
        Activity::operator=(other);
        sets = 3;
        reps = 10; 
        weightKg = 10.0; 
    }
    return *this;
}

// Переопределенный метод: Возвращает оценку длительности (с вызовом базового метода)
int StrengthActivity::getDurationEstimate() const {
    int baseDuration = Activity::getDurationEstimate(); // Вызов метода базового класса
    // Для силовых упражнений время = базовое время * количество подходов
    return baseDuration * sets;
}

// Переопределенный метод: Проверяет пользователя 
bool StrengthActivity::matchesUser(const ProfileManager& user) const {
    // Для силовых упражнений проверяем наличие необходимого оборудования
    const auto& reqEquipment = getRequiredEquipment();
    if (!reqEquipment.empty()) {
        const auto& userEquipment = user.getAvailableEquipment();
        for (const auto& reqItem : reqEquipment) {
            if (userEquipment.find(reqItem) == userEquipment.end()) {
                return false;
            }
        }
    }
    return true;
}

// Переопределенная виртуальная функция
void StrengthActivity::generateReport() const {
    Activity::generateReport(); // Вызов базового метода
    std::cout << "Тип: Силовое упражнение" << std::endl;
    std::cout << "Подходы: " << sets << std::endl;
    std::cout << "Повторения: " << reps << std::endl;
    std::cout << "Вес: " << weightKg << " кг" << std::endl;
    std::cout << "Общий объем: " << (sets * reps * weightKg) << " кг" << std::endl;
}


std::unique_ptr<Activity> StrengthActivity::clone() const {
    return std::make_unique<StrengthActivity>(*this); 
}

// Реализация паттерна делегирования: выполнение упражнения через стратегию
void StrengthActivity::execute() const {
    if (executionStrategy) {
        std::cout << "Выполнение упражнения: " << getTitle() << std::endl;
        executionStrategy->execute(sets, reps, weightKg);
    }
    else {
        std::cout << "Ошибка: стратегия выполнения не установлена!" << std::endl;
    }
}

// Установка стратегии выполнения (динамическое конфигурирование)
void StrengthActivity::setExecutionStrategy(std::unique_ptr<IExecutionStrategy> strategy) {
    executionStrategy = std::move(strategy);
}

// Получение описания стратегии выполнения
std::string StrengthActivity::getExecutionStrategyDescription() const {
    if (executionStrategy) {
        return executionStrategy->getDescription();
    }
    return "Стратегия не установлена";
}

// Приватный метод создания стратегии по типу (статическое конфигурирование)
std::unique_ptr<IExecutionStrategy> StrengthActivity::createStrategy(ExecutionType type) const {
    switch (type) {
    case ExecutionType::STANDARD:
        return std::make_unique<StandardExecutionStrategy>();
    case ExecutionType::PROGRESSIVE_OVERLOAD:
        return std::make_unique<ProgressiveOverloadStrategy>();
    case ExecutionType::PYRAMID:
        return std::make_unique<PyramidStrategy>();
    default:
        return std::make_unique<StandardExecutionStrategy>(); // По умолчанию стандартная стратегия
    }
}


