#include <iostream>
#include <vector>
#include <windows.h>
#include <list>
#include <set>
#include "ProfileManager.hpp"
#include "Activity.hpp"
#include "FitnessDatabase.hpp"
#include "TrainingSession.hpp"
#include "TrainingSchedule.hpp"
#include "DietProgram.hpp"
#include "MealFormula.hpp"
#include "EventPlanner.hpp"
#include "ProgressTracker.hpp"
#include "FunMascot.hpp"

int main() {
    SetConsoleOutputCP(1251);
    // 1. Статическая инициализация объектов
    std::cout << "Тест 1: Статическая инициализация\n";
    std::list<ProfileManager::Weekday> days;
    std::set<ProfileManager::Equipment> equip = { ProfileManager::Equipment::DUMBBELLS };
    ProfileManager staticUser("1", "user1", 25, ProfileManager::Gender::MALE, 190, 90.0, ProfileManager::Goal::LOSE_WEIGHT, ProfileManager::Level::BEGINNER, days, equip, true);
    std::cout << "  Статический ProfileManager создан, BMI: " << staticUser.calculateBMI() << " (ожидается ~24.93)\n";

    // 2. Динамическая инициализация с new/delete
    std::cout << "\nТест 2: Динамическая инициализация\n";
    std::set<Activity::MuscleGroup> muscles = { Activity::MuscleGroup::LEGS };
    std::set<ProfileManager::Equipment> reqEquip = { ProfileManager::Equipment::DUMBBELLS }; // Используем ProfileManager::Equipment
    Activity* dynamicActivity = new Activity("act1", "Приседания", muscles, Activity::ActivityType::STRENGTH, reqEquip, ProfileManager::Level::BEGINNER, "Описание техники");
    std::cout << "  Динамический Activity создан, оценка длительности: " << dynamicActivity->getDurationEstimate() << " (ожидается 10)\n";
    std::cout << "  Подходит ли упражнение пользователю: " << dynamicActivity->matchesUser(staticUser) << " (ожидается 1)\n";
    delete dynamicActivity; // Освобождение памяти
    std::cout << "  Динамический объект удалён\n";

    // 3. Работа с ссылками
    std::cout << "\nТест 3: Работа с ссылками\n";
    FitnessDatabase db;
    FitnessDatabase& dbRef = db; // Ссылка на объект
    Activity act("act2", "Отжимания", muscles, Activity::ActivityType::STRENGTH, reqEquip, ProfileManager::Level::INTERMEDIATE, "Описание");
    dbRef.addActivity(act);
    std::cout << "  Ссылка на FitnessDatabase: упражнение добавлено\n";

    // 4. Работа с указателями
    std::cout << "\nТест 4: Работа с указателями\n";
    std::list<std::string> events;
    EventPlanner reminderSystem(events, "Ежедневные напоминания");
    EventPlanner* reminderPtr = &reminderSystem;
    std::list<std::string> blocks = { "Блок 1", "Блок 2" };
    TrainingSession session("sess1", "2025-10-27", 60, "Тренировка", blocks, TrainingSession::WorkoutStatus::PLANNED);
    reminderPtr->addToSchedule(session);
    std::cout << "  Указатель на EventPlanner: расписание добавлено\n";
    reminderPtr->delayNotification("sess1", 10);
    std::cout << "  Указатель на EventPlanner: уведомление отложено\n";

    // 5. Динамический массив объектов
    std::cout << "\nТест 5: Динамический массив объектов\n";
    std::list<TrainingSession> sessions = { session };
    TrainingSchedule* scheduleArray = new TrainingSchedule[2]; // Динамический массив из 2 планов
    scheduleArray[0] = TrainingSchedule("plan1", "1", "2025-10-01", "2025-12-31", sessions);
    std::cout << "  Динамический массив TrainingSchedule: план 1 создан\n";
    scheduleArray[1] = TrainingSchedule("plan2", "1", "2026-01-01", "2026-03-31", sessions);
    std::cout << "  Динамический массив TrainingSchedule: план 2 создан\n";
    delete[] scheduleArray;
    std::cout << "  Динамический массив удалён\n";

    // 6. Массив динамических объектов

    std::cout << "\nТест 6: Массив динамических объектов\n";
    std::vector<DietProgram*> dietVector;
    std::list<std::string> meal1 = { "Яблоко" };
    std::list<std::string> meal2 = { "Апельсин" };
    dietVector.push_back(new DietProgram("diet1", "1", "2025-10-27", meal1, "150 г"));
    dietVector.push_back(new DietProgram("diet2", "1", "2025-10-28", meal2, "150 г"));
    std::cout << "  Массив DietProgram: добавлено " << dietVector.size() << " объекта\n";
    for (auto* item : dietVector) {
        std::string summary = item->calcDailySummary();
        std::cout << "  " << summary << "\n";
        delete item;
    }
    std::cout << "  Массив динамических объектов очищен\n";
    return 0;
}
