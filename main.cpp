#include <iostream>
#include <memory>
#include <stdexcept>
#include <windows.h>

#include "ProfileManager.hpp"
#include "SimpleUser.hpp"
#include "Activity.hpp"
#include "CardioActivity.hpp"
#include "StrengthActivity.hpp"
#include "FitnessComponent.hpp"

int main() {
    SetConsoleOutputCP(1251);

    // Демонстрация для лабораторной
    // Производные классы
    SimpleUser du("1", "du", "email", "2000-01-01", ProfileManager::Gender::MALE, 180, 80.0,
        ProfileManager::Goal::GAIN_MASS, ProfileManager::Level::INTERMEDIATE, "info");
    std::cout << "Инфо simple: " << du.getAdditionalInfo() << std::endl;

    CardioActivity cardio(5.0); 
    std::cout << "Калории кардио (protected): " << cardio.estimateCalories(10) << std::endl;

    StrengthActivity strength("s1", "Приседания", { Activity::MuscleGroup::LEGS },
        { ProfileManager::Equipment::DUMBBELLS }, ProfileManager::Level::INTERMEDIATE,
        "Силовое", 4, 12, 100.0);
    std::cout << "Калории strength (с base): " << strength.estimateCalories(10) << std::endl;
    std::cout << "Калории cardio (без base): " << cardio.estimateCalories(10) << std::endl;

    // Виртуальные функции
    FitnessComponent* ent = new SimpleUser("5", "du2", "email2", "1995-05-05", ProfileManager::Gender::MALE, 175, 70.0,
        ProfileManager::Goal::LOSE_WEIGHT, ProfileManager::Level::ADVANCED, "info2");
    ent->callVirtual();
    std::cout << "Полиморфизм: " << ent->calculateSomething() << std::endl;

    // Без virtual calculateSomething: вызовет base версию (0.0)
    delete ent; 

    // Клонирование
    Activity original("orig", "Бег", { Activity::MuscleGroup::LEGS }, Activity::ActivityType::CARDIO,
        {}, ProfileManager::Level::BEGINNER, "Пробежка");
    Activity shallow = original;
    Activity deep = original.deepClone();  // deepClone() возвращает Activity 
    std::cout << "Клоны созданы" << std::endl;

    // Абстрактный класс
    // FitnessComponent* absEnt = new FitnessComponent();

    ProfileManager baseUser("6", "base", 28, ProfileManager::Gender::FEMALE, 165, 58.0,
        ProfileManager::Goal::LOSE_WEIGHT, ProfileManager::Level::BEGINNER,
        { ProfileManager::Weekday::MONDAY }, { ProfileManager::Equipment::DUMBBELLS }, true);
    du = baseUser;
    std::cout << "Присваивание от base: " << du.getAdditionalInfo() << std::endl;

    return 0;
}
