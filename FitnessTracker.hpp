#ifndef FITNESS_TRACKER_HPP
#define FITNESS_TRACKER_HPP

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include "IExecutionStrategy.hpp"
#include "Activity.hpp"

/*
  Шаблонный класс FitnessTracker
  T - тип стратегии выполнения (наследник IExecutionStrategy)
 */
template<typename T>
class FitnessTracker {
private:
    std::string userName;
    std::vector<std::unique_ptr<Activity>> activities;
    std::unique_ptr<T> strategy;
    int totalSessions;

public:
    // Конструктор
    FitnessTracker(const std::string& name)
        : userName(name), totalSessions(0) {}

    // Нешаблонный метод: получение имени пользователя
    const std::string& getUserName() const {
        return userName;
    }

    // Нешаблонный метод: получение количества сессий
    int getTotalSessions() const {
        return totalSessions;
    }

    // Нешаблонный метод: установка стратегии
    void setStrategy(std::unique_ptr<T> newStrategy) {
        strategy = std::move(newStrategy);
    }

    // Шаблонный метод: добавление активности определенного типа
    template<typename ActivityType>
    void addActivity(std::unique_ptr<ActivityType> activity) {
        activities.push_back(std::move(activity));
        totalSessions++;
    }

    // Шаблонный метод: выполнение активности с заданной стратегией
    template<typename StrategyType>
    void executeWithStrategy(const Activity& activity, StrategyType* execStrategy) {
        std::cout << "Выполнение " << activity.getTitle() << " со стратегией" << std::endl;

        if (auto strengthActivity = dynamic_cast<const StrengthActivity*>(&activity)) {
            execStrategy->execute(strengthActivity->getSets(),
                strengthActivity->getReps(),
                strengthActivity->getWeightKg());
        }
        else {
            activity.generateReport();
        }
    }

    // Нешаблонный метод: вывод статистики
    void printStatistics() const {
        std::cout << "Пользователь: " << userName << std::endl;
        std::cout << "Всего активностей: " << activities.size() << std::endl;
        std::cout << "Всего сессий: " << totalSessions << std::endl;
    }

    // Шаблонный метод: фильтрация активностей
    template<typename Predicate>
    std::vector<const Activity*> filterActivities(Predicate pred) const {
        std::vector<const Activity*> result;
        for (const auto& activity : activities) {
            if (pred(*activity)) {
                result.push_back(activity.get());
            }
        }
        return result;
    }

    // Нешаблонный метод: получение активностей (для демонстрации)
    const std::vector<std::unique_ptr<Activity>>& getActivities() const {
        return activities;
    }
};

/*
  Демонстрационная функция для шаблонного класса
 */
void demonstrateTemplateClass() {
    std::cout << "\n=== Шаблонный класс FitnessTracker ===\n";

    // Создаем трекер с StandardExecutionStrategy
    FitnessTracker<StandardExecutionStrategy> tracker("Алексей");

    // Добавляем активности разных типов
    tracker.addActivity(std::unique_ptr<Activity>(new StrengthActivity(
        "bench_press", "Жим лежа", { Activity::MuscleGroup::CHEST },
        { ProfileManager::Equipment::DUMBBELLS }, ProfileManager::Level::INTERMEDIATE,
        "Жим лежа", 3, 10, 50.0, StrengthActivity::ExecutionType::STANDARD)));

    tracker.addActivity(std::unique_ptr<Activity>(new CardioActivity(5.0)));

    // Устанавливаем стратегию
    tracker.setStrategy(std::make_unique<StandardExecutionStrategy>());

    // Выводим статистику
    tracker.printStatistics();

    // Фильтруем силовые активности
    auto strengthActivities = tracker.filterActivities(
        [](const Activity& activity) {
            return dynamic_cast<const StrengthActivity*>(&activity) != nullptr;
        });

    std::cout << "Силовых активностей: " << strengthActivities.size() << std::endl;

    // Выполняем активность со стратегией
    const auto& activities = tracker.getActivities();
    if (!activities.empty()) {
        StandardExecutionStrategy strategy;
        tracker.executeWithStrategy(*activities[0], &strategy);
    }
}

#endif 
