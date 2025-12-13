#ifndef STL_HPP
#define STL_HPP

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <array>
#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include "Activity.hpp"
#include "StrengthActivity.hpp"
#include "CardioActivity.hpp"
#include "ProfileManager.hpp"

/*
  Класс для демонстрации STL контейнеров и алгоритмов
 */
class STL_Demo {
public:
    void demonstrateVectorUsage() {
        std::cout << "\n=== std::vector с сортировкой ===\n";

        std::vector<std::unique_ptr<Activity>> activities;

        // Добавляем объекты базового и производного классов
        activities.push_back(std::unique_ptr<Activity>(new StrengthActivity(
            "bench_press", "Жим лежа", { Activity::MuscleGroup::CHEST },
            { ProfileManager::Equipment::DUMBBELLS }, ProfileManager::Level::INTERMEDIATE,
            "Жим лежа", 3, 10, 50.0, StrengthActivity::ExecutionType::STANDARD)));

        activities.push_back(std::unique_ptr<Activity>(new CardioActivity(5.0)));
        activities.push_back(std::unique_ptr<Activity>(new StrengthActivity(
            "squats", "Приседания", { Activity::MuscleGroup::LEGS },
            { ProfileManager::Equipment::BARBELL }, ProfileManager::Level::BEGINNER,
            "Приседания", 4, 12, 60.0, StrengthActivity::ExecutionType::STANDARD)));

        // std::sort - сортировка по названию
        std::sort(activities.begin(), activities.end(),
            [](const std::unique_ptr<Activity>& a, const std::unique_ptr<Activity>& b) {
                return a->getTitle() < b->getTitle();
            });

        std::cout << "Отсортированные активности:\n";
        for (const auto& activity : activities) {
            std::cout << "- " << activity->getTitle() << std::endl;
        }
    }

    void demonstrateListUsage() {
        std::cout << "\n=== std::list с поиском ===\n";

        std::list<std::unique_ptr<Activity>> activityList;

        activityList.push_back(std::unique_ptr<Activity>(new StrengthActivity(
            "deadlift", "Становая тяга", { Activity::MuscleGroup::BACK },
            { ProfileManager::Equipment::BARBELL }, ProfileManager::Level::ADVANCED,
            "Становая тяга", 3, 8, 80.0, StrengthActivity::ExecutionType::STANDARD)));

        activityList.push_back(std::unique_ptr<Activity>(new CardioActivity(3.0)));

        // std::find_if - поиск кардио активности
        auto it = std::find_if(activityList.begin(), activityList.end(),
            [](const std::unique_ptr<Activity>& activity) {
                return dynamic_cast<CardioActivity*>(activity.get()) != nullptr;
            });

        if (it != activityList.end()) {
            std::cout << "Найдена кардио-активность: " << (*it)->getTitle() << std::endl;
        }
    }

    void demonstrateMapUsage() {
        std::cout << "\n=== std::map с копированием ===\n";

        std::map<std::string, std::unique_ptr<Activity>> activityMap;

        activityMap["strength"] = std::unique_ptr<Activity>(new StrengthActivity(
            "pull_ups", "Подтягивания", { Activity::MuscleGroup::BACK },
            { ProfileManager::Equipment::DUMBBELLS }, ProfileManager::Level::INTERMEDIATE,
            "Подтягивания", 3, 8, 0.0, StrengthActivity::ExecutionType::STANDARD));

        activityMap["cardio"] = std::unique_ptr<Activity>(new CardioActivity(10.0));

        
        std::vector<std::unique_ptr<Activity>> strengthActivities;
        for (const auto& pair : activityMap) {
            if (dynamic_cast<StrengthActivity*>(pair.second.get()) != nullptr) {
                strengthActivities.push_back(pair.second->clone());
            }
        }

        std::cout << "Скопировано силовых активностей: " << strengthActivities.size() << std::endl;
    }

    void demonstrateArrayUsage() {
        std::cout << "\n=== std::array с трансформацией ===\n";

        const size_t SIZE = 3;
        std::array<std::unique_ptr<Activity>, SIZE> activityArray;

        activityArray[0] = std::unique_ptr<Activity>(new StrengthActivity(
            "curls", "Сгибания рук", { Activity::MuscleGroup::CHEST },
            { ProfileManager::Equipment::DUMBBELLS }, ProfileManager::Level::BEGINNER,
            "Сгибания рук", 3, 12, 15.0, StrengthActivity::ExecutionType::STANDARD));

        activityArray[1] = std::unique_ptr<Activity>(new CardioActivity(2.5));
        activityArray[2] = std::unique_ptr<Activity>(new StrengthActivity(
            "rows", "Тяга гантели", { Activity::MuscleGroup::BACK },
            { ProfileManager::Equipment::DUMBBELLS }, ProfileManager::Level::INTERMEDIATE,
            "Тяга гантели", 3, 10, 25.0, StrengthActivity::ExecutionType::STANDARD));

        // std::transform - преобразование в названия
        std::array<std::string, SIZE> names;
        std::transform(activityArray.begin(), activityArray.end(), names.begin(),
            [](const std::unique_ptr<Activity>& activity) {
                return activity->getTitle();
            });

        std::cout << "Названия активностей:\n";
        for (const auto& name : names) {
            std::cout << "- " << name << std::endl;
        }

        // std::any_of - проверка наличия продвинутых активностей
        bool hasAdvanced = std::any_of(activityArray.begin(), activityArray.end(),
            [](const std::unique_ptr<Activity>& activity) {
                return activity->getComplexity() == ProfileManager::Level::ADVANCED;
            });

        std::cout << "Есть продвинутые активности: " << (hasAdvanced ? "Да" : "Нет") << std::endl;
    }

    void demonstrateComplexAlgorithms() {
        std::cout << "\n=== Комплексные алгоритмы STL ===\n";

        std::vector<std::unique_ptr<Activity>> activities;

        activities.push_back(std::unique_ptr<Activity>(new StrengthActivity(
            "bench_press", "Жим лежа", { Activity::MuscleGroup::CHEST },
            { ProfileManager::Equipment::DUMBBELLS }, ProfileManager::Level::INTERMEDIATE,
            "Жим лежа", 3, 10, 40.0, StrengthActivity::ExecutionType::STANDARD)));

        activities.push_back(std::unique_ptr<Activity>(new CardioActivity(8.0)));
        activities.push_back(std::unique_ptr<Activity>(new StrengthActivity(
            "squats", "Приседания", { Activity::MuscleGroup::LEGS },
            { ProfileManager::Equipment::BARBELL }, ProfileManager::Level::ADVANCED,
            "Приседания", 4, 8, 100.0, StrengthActivity::ExecutionType::STANDARD)));

        // std::min_element и std::max_element
        auto minDuration = std::min_element(activities.begin(), activities.end(),
            [](const std::unique_ptr<Activity>& a, const std::unique_ptr<Activity>& b) {
                return a->getDurationEstimate() < b->getDurationEstimate();
            });

        auto maxDuration = std::max_element(activities.begin(), activities.end(),
            [](const std::unique_ptr<Activity>& a, const std::unique_ptr<Activity>& b) {
                return a->getDurationEstimate() < b->getDurationEstimate();
            });

        std::cout << "Минимальная длительность: " << (*minDuration)->getTitle()
            << " (" << (*minDuration)->getDurationEstimate() << " мин)" << std::endl;
        std::cout << "Максимальная длительность: " << (*maxDuration)->getTitle()
            << " (" << (*maxDuration)->getDurationEstimate() << " мин)" << std::endl;

        // std::remove_if и erase
        auto removeIt = std::remove_if(activities.begin(), activities.end(),
            [](const std::unique_ptr<Activity>& activity) {
                return activity->getDurationEstimate() < 30;
            });
        activities.erase(removeIt, activities.end());

        std::cout << "После удаления коротких активностей осталось: "
            << activities.size() << " активностей\n";
    }
};

#endif 
