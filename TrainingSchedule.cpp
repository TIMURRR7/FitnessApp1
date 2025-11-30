#include "TrainingSchedule.hpp"
#include "ProfileManager.hpp"
#include "FitnessDatabase.hpp"
#include <stdexcept>

// Инициализация статического поля
int TrainingSchedule::totalSchedules = 0;

// Default-конструктор: Инициализирует пустыми значениями
TrainingSchedule::TrainingSchedule() : id(""), ownerUserId(""), startDate(""), endDate(""), sessions({}) {
    totalSchedules++;
}

// Конструктор: Инициализирует все поля
TrainingSchedule::TrainingSchedule(const std::string& id, const std::string& ownerUserId, const std::string& startDate,
    const std::string& endDate, const std::list<TrainingSession>& sessions)
    : id(id), ownerUserId(ownerUserId), startDate(startDate), endDate(endDate), sessions(sessions) {
    totalSchedules++;
}

// Конструктор копирования
TrainingSchedule::TrainingSchedule(const TrainingSchedule& other)
    : id(other.id), ownerUserId(other.ownerUserId), startDate(other.startDate),
    endDate(other.endDate), sessions(other.sessions) {
    totalSchedules++;
}

// Деструктор: Пустой
TrainingSchedule::~TrainingSchedule() {
    totalSchedules--;
}

// Метод: Генерирует план (заглушка, возвращает копию текущего)
TrainingSchedule TrainingSchedule::createPlan(const ProfileManager& user, const FitnessDatabase& library) {
    // Генерация плана
    return *this; // Пример
}

// Метод: Корректировка(заглушка)
void TrainingSchedule::adjustFromFeedback(const std::string& userFeedback) {
    try {
        if (userFeedback.empty()) {
            throw std::invalid_argument("Отзыв не может быть пустым");
        }
        // Корректировка
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Метод: Возвращает предстоящие сессии (заглушка)
std::list<TrainingSession> TrainingSchedule::listNextSessions(int count) const {
    std::list<TrainingSession> result;
    return result;
}

// Перегрузка оператора +
TrainingSchedule TrainingSchedule::operator+(const TrainingSession& session) const {
    TrainingSchedule newSchedule = *this;
    newSchedule.sessions.push_back(session);
    return newSchedule;
}
