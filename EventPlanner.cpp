#include "EventPlanner.hpp"

// Конструктор: Инициализирует поля
EventPlanner::EventPlanner(const std::list<std::string>& plannedEvents, const std::string& notifyRules)
    : plannedEvents(plannedEvents), notifyRules(notifyRules) {}

// Деструктор
EventPlanner::~EventPlanner() {}

// Метод: Добавляет в расписание (заглушка)
std::string EventPlanner::addToSchedule(const TrainingSession& session) {
    return "Scheduled"; // Пример
}

// Метод: Откладывает уведомление (заглушка)
void EventPlanner::delayNotification(const std::string& eventId, int delayMin) {
    // Отложить
}

// Метод: Переносит пропущенные занятия (заглушка)
void EventPlanner::rescheduleMissed() {
    // Перенос
}
