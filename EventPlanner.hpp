#ifndef EVENTPLANNER_HPP
#define EVENTPLANNER_HPP

#include <string>
#include <list>
#include <memory>

// Класс EventPlanner: Планировщик событий и уведомлений
class EventPlanner {
public:
    // Конструктор: Инициализирует поля
    EventPlanner(const std::list<std::string>& plannedEvents, const std::string& notifyRules);

    // Конструктор копирования
    EventPlanner(const EventPlanner& other);

    // Деструктор
    ~EventPlanner();

    // Метод: Добавляет в расписание (заглушка)
    std::string addToSchedule(const TrainingSession& session);

    // Метод: Откладывает уведомление (заглушка)
    void delayNotification(const std::string& eventId, int delayMin);

    // Метод: Переносит пропущенные занятия (заглушка)
    void rescheduleMissed();


    EventPlanner& setNotifyRules(const std::string& rules) {
        this->notifyRules = rules;
        return *this;
    }

private:
    std::list<std::string> plannedEvents; // Запланированные события
    std::string notifyRules; // Правила уведомлений
};

#endif
