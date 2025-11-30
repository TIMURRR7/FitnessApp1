#include "ProgressTracker.hpp"
#include <stdexcept>

// Конструктор: Инициализирует поля
ProgressTracker::ProgressTracker(const std::string& userId, const std::list<std::pair<std::string, double>>& weightLog,
    const std::list<std::string>& sessionHistory, int activeStreak)
    : userId(userId), weightLog(weightLog), sessionHistory(sessionHistory), activeStreak(activeStreak) {}

// Конструктор копирования
ProgressTracker::ProgressTracker(const ProgressTracker& other)
    : userId(other.userId), weightLog(other.weightLog), sessionHistory(other.sessionHistory),
    activeStreak(other.activeStreak) {}

// Деструктор
ProgressTracker::~ProgressTracker() {}

// Метод: Записывает исход сессии
void ProgressTracker::logSessionOutcome(const std::string& outcome) {
    try {
        if (outcome.empty()) {
            throw std::invalid_argument("Результат не может быть пустым");
        }
        this->sessionHistory.push_back(outcome); // Использование this
    }
    catch (const std::exception& e) {
        throw;
    }
}

// Метод: Рассчитывает соблюдение плана(заглушка)
double ProgressTracker::calcCompliance(const std::string& interval) const {
    return 90.0; // Пример
}

// Перегрузка оператора +=
ProgressTracker& ProgressTracker::operator+=(const std::string& session) {
    this->sessionHistory.push_back(session);
    return *this;
}

// Перегрузка оператора []
double ProgressTracker::operator[](const std::string& date) const {
    for (const auto& entry : this->weightLog) {
        if (entry.first == date) {
            return entry.second;
        }
    }
    throw std::out_of_range("Нет данных для этой даты: " + date);
}
