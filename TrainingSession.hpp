#ifndef TRAININGSESSION_HPP
#define TRAININGSESSION_HPP

#include <string>
#include <list>
#include "ProfileManager.hpp" 

// Класс TrainingSession: Тренировочная сессия
class TrainingSession {
public:
    enum class WorkoutStatus { PLANNED, COMPLETED }; // Статус сессии

    // Конструктор: Инициализирует сессию
    TrainingSession(const std::string& id, const std::string& scheduledDate, int estDurationMin,
        const std::string& sessionName, const std::list<std::string>& exerciseBlocks, // Упрощено
        WorkoutStatus currentStatus);

    // Деструктор: Освобождает ресурсы
    ~TrainingSession();

    // Метод: Начинает сессию
    void beginSession();

    // Метод: Завершает сессию с сохранением результатов 
    void finishSession(const std::string& results);

    // Метод: Переносит дату сессии
    void shiftDate(const std::string& newScheduledDate);

    // Метод: Рассчитывает сожжённые калории
    int calcBurnedCalories(const ProfileManager& user) const;

private:
    std::string id; // Идентификатор
    std::string scheduledDate; // Запланированная дата
    int estDurationMin; // Оценка длительности в минутах
    std::string sessionName; // Название сессии
    std::list<std::string> exerciseBlocks; // Блоки упражнений (упрощённо)
    WorkoutStatus currentStatus; // Текущий статус
};

#endif
