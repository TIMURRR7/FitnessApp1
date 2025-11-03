#ifndef EVENTPLANNER_HPP
#define EVENTPLANNER_HPP

#include <list>
#include <string>
#include "TrainingSession.hpp"

// Класс EventPlanner: Управление календарем и напоминаниями
class EventPlanner {
public:
    // Конструктор: Инициализирует запланированные события и правила уведомлений
    EventPlanner(const std::list<std::string>& plannedEvents, const std::string& notifyRules);

    // Деструктор
    ~EventPlanner();

    // Метод: Добавляет тренировку в расписание 
    std::string addToSchedule(const TrainingSession& session);

    // Метод: Откладывает уведомление для события
    void delayNotification(const std::string& eventId, int delayMin);

    // Метод: Переносит пропущенные события
    void rescheduleMissed();

private:
    std::list<std::string> plannedEvents; // Запланированные слоты/события
    std::string notifyRules; // Правила напоминаний
};

#endif
