#include "ProgressTracker.hpp"

// Конструктор: Инициализирует поля
ProgressTracker::ProgressTracker(const std::string& userId, const std::list<std::pair<std::string, double>>& weightLog,
    const std::list<std::string>& sessionHistory, int activeStreak)
    : userId(userId), weightLog(weightLog), sessionHistory(sessionHistory), activeStreak(activeStreak) {}

// Деструктор
ProgressTracker::~ProgressTracker() {}

// Метод: Записывает исход сессии
void ProgressTracker::logSessionOutcome(const std::string& outcome) {
    sessionHistory.push_back(outcome);
}

// Метод: Рассчитывает соблюдение плана(заглушка)
double ProgressTracker::calcCompliance(const std::string& interval) const {
    return 90.0; // Пример
}
