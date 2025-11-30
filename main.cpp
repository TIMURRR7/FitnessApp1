#include <iostream>
#include <memory>
#include <stdexcept>
#include <windows.h>
#include "ProfileManager.hpp"
#include "Activity.hpp"
#include "ProgressTracker.hpp"
#include "DietProgram.hpp"
#include "TrainingSession.hpp"
#include "FunMascot.hpp"
#include "FitnessDatabase.hpp"
#include "MealFormula.hpp"
#include "SimpleUser.hpp"

int main() {

    SetConsoleOutputCP(1251);

    try {
        std::unique_ptr<ProfileManager> uniqueUser(new ProfileManager("1", "user1", 25, ProfileManager::Gender::MALE, 180, 75.0, ProfileManager::Goal::GAIN_MASS, ProfileManager::Level::BEGINNER, { ProfileManager::Weekday::MONDAY }, { ProfileManager::Equipment::DUMBBELLS }, true));
        std::shared_ptr<ProfileManager> sharedUser(new ProfileManager(*uniqueUser));
        std::cout << "Смарт-указатели: BMI = " << sharedUser->calculateBMI() << std::endl;

        std::cout << "Статическое поле: Всего профилей = " << ProfileManager::getTotalProfiles() << std::endl;

        uniqueUser->changeWeight(-10);
    }
    catch (const std::exception& ex) {
        std::cerr << "Перехвачено исключение: " << ex.what() << std::endl;
    }

    ProfileManager user("2", "user2", 30, ProfileManager::Gender::FEMALE, 165, 60.0, ProfileManager::Goal::LOSE_WEIGHT, ProfileManager::Level::INTERMEDIATE, { ProfileManager::Weekday::TUESDAY }, { ProfileManager::Equipment::BARBELL }, false);

   
    std::cout << "Дружественная функция для вывода: " << user << std::endl;

    SimpleUser derived("3", "derived", "Доп. инфо");
    SimpleUser copyDerived(derived);
    std::cout << "Наследование: Доп. инфо = " << copyDerived.getAdditionalInfo() << std::endl;


    ProgressTracker tracker("1", { {"2024-01-01", 75.0} }, { "завершена" }, 3);
    tracker += "новая сессия";
    std::cout << "Оператор +=: Сессия добавлена" << std::endl;

    TrainingSession session("s1", "2024-01-01", 60, "Силовая тренировка", { "Отжимания", "Приседания" }, TrainingSession::WorkoutStatus::PLANNED);
    session += "Подтягивания";
    std::cout << "Оператор +=: Упражнение добавлено в сессию" << std::endl;

    DietProgram diet("d1", "1", "2024-01-01", { "Завтрак", "Обед" }, "2000 ккал");
    diet += "Ужин";
    std::cout << "Оператор +=: Прием пищи добавлен" << std::endl;

    

    FitnessDatabase database;
    std::unique_ptr<Activity> activityPtr(new Activity("a3", "Бег", { Activity::MuscleGroup::LEGS }, Activity::ActivityType::CARDIO, {}, ProfileManager::Level::BEGINNER, "Кардио"));
    database.addActivity(std::move(activityPtr));
    std::cout << "FitnessDatabase: Упражнение добавлено в базу упражнений" << std::endl;

    MealFormula recipe("r1", "Протеиновый коктейль", { "протеин", "молоко" }, "300 ккал", 5);
    std::cout << "MealFormula: " << recipe.adjustPortions(300) << std::endl;

    return 0;
}
