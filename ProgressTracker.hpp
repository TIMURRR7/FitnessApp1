#ifndef PROGRESSTRACKER_HPP
#define PROGRESSTRACKER_HPP

#include <string>
#include <list>

// Класс ProgressTracker: Отслеживание прогресса
class ProgressTracker {
public:
    // Конструктор: Инициализирует трекер
    ProgressTracker(const std::string& userId, const std::list<std::pair<std::string, double>>& weightLog,
        const std::list<std::string>& sessionHistory, int activeStreak);

    // Деструктор: Освобождает ресурсы
    ~ProgressTracker();

    // Метод: Записывает результат сессии
    void logSessionOutcome(const std::string& outcome);

    // Метод: Рассчитывает процент соблюдения плана
    double calcCompliance(const std::string& interval) const;

private:
    std::string userId; // Идентификатор пользователя
    std::list<std::pair<std::string, double>> weightLog; // История веса (дата, вес)
    std::list<std::string> sessionHistory; // История сессий
    int activeStreak; // Текущий стрик
};

#endif
