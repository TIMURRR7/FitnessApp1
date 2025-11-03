#include "TrainingSchedule.hpp"

// Default-конструктор: Инициализирует пустыми значениями
TrainingSchedule::TrainingSchedule() : id(""), ownerUserId(""), startDate(""), endDate(""), sessions({}) {}

// Конструктор: Инициализирует все поля
TrainingSchedule::TrainingSchedule(const std::string& id, const std::string& ownerUserId, const std::string& startDate,
    const std::string& endDate, const std::list<TrainingSession>& sessions)
    : id(id), ownerUserId(ownerUserId), startDate(startDate), endDate(endDate), sessions(sessions) {}

// Деструктор: Пустой
TrainingSchedule::~TrainingSchedule() {}

// Метод: Генерирует план (заглушка, возвращает копию текущего)
TrainingSchedule TrainingSchedule::createPlan(const ProfileManager& user, const FitnessDatabase& library) {
    // Генерация плана
    return *this; // Пример
}

// Метод: Корректировка(заглушка)
void TrainingSchedule::adjustFromFeedback(const std::string& userFeedback) {
    // Корректировка
}

// Метод: Возвращает предстоящие сессии (заглушка)
std::list<TrainingSession> TrainingSchedule::listNextSessions(int count) const {
    std::list<TrainingSession> result;
    return result;
}
