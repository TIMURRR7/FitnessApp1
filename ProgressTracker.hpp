#ifndef PROGRESSTRACKER_HPP
#define PROGRESSTRACKER_HPP

#include <string>
#include <list>
#include <memory>
#include <utility>

class ProgressTracker {
public:
    // Конструктор: Инициализирует поля
    ProgressTracker(const std::string& userId, const std::list<std::pair<std::string, double>>& weightLog,
        const std::list<std::string>& sessionHistory, int activeStreak);

    // Конструктор копирования
    ProgressTracker(const ProgressTracker& other);

    // Деструктор
    ~ProgressTracker();

    // Метод: Записывает исход сессии
    void logSessionOutcome(const std::string& outcome);

    // Метод: Рассчитывает соблюдение плана(заглушка)
    double calcCompliance(const std::string& interval) const;

    // Перегрузка оператора 
    ProgressTracker& operator+=(const std::string& session);

    // Перегрузка оператора 
    double operator[](const std::string& date) const;

    // Использование this
    ProgressTracker& setUserId(const std::string& userId) {
        this->userId = userId;
        return *this;
    }

private:
    std::string userId; // Идентификатор пользователя
    std::list<std::pair<std::string, double>> weightLog; // Лог веса
    std::list<std::string> sessionHistory; // История сессий
    int activeStreak; // Активная серия
};

#endif
