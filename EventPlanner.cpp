#include "EventPlanner.hpp"
#include "TrainingSession.hpp"
#include <stdexcept>

// Конструктор: Инициализирует поля
EventPlanner::EventPlanner(const std::list<std::string>& plannedEvents, const std::string& notifyRules)
    : plannedEvents(plannedEvents), notifyRules(notifyRules) {}

// Конструктор копирования
EventPlanner::EventPlanner(const EventPlanner& other)
    : plannedEvents(other.plannedEvents), notifyRules(other.notifyRules) {}

// Деструктор
EventPlanner::~EventPlanner() {}

// Метод: Добавляет в расписание (заглушка)
std::string EventPlanner::addToSchedule(const TrainingSession& session) {
    try {
        return "Событие добавлено в расписание"; // Пример
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Ошибка при добавлении в расписание: " + std::string(e.what()));
    }
}

// Метод: Откладывает уведомление (заглушка)
void EventPlanner::delayNotification(const std::string& eventId, int delayMin) {
    try {
        if (eventId.empty()) {
            throw std::invalid_argument("ID события не может быть пустым");
        }
        if (delayMin < 0) {
            throw std::invalid_argument("Задержка не может быть отрицательной");
        }
        // Отложить
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Метод: Переносит пропущенные занятия (заглушка)
void EventPlanner::rescheduleMissed() {
    // Перенос
}

