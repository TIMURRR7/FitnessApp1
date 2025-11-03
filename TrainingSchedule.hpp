#ifndef TRAININGSCHEDULE_HPP
#define TRAININGSCHEDULE_HPP

#include <string>
#include <list>
#include "TrainingSession.hpp"
#include "FitnessDatabase.hpp"
#include "ProfileManager.hpp"

// Класс TrainingSchedule: План тренировок на период
class TrainingSchedule {
public:
    // Default-конструктор: Инициализирует пустой план
    TrainingSchedule();

    // Конструктор: Инициализирует план с параметрами
    TrainingSchedule(const std::string& id, const std::string& ownerUserId, const std::string& startDate,
        const std::string& endDate, const std::list<TrainingSession>& sessions);

    // Деструктор: Освобождает ресурсы
    ~TrainingSchedule();

    // Метод: Генерирует новый план на основе пользователя и библиотеки
    TrainingSchedule createPlan(const ProfileManager& user, const FitnessDatabase& library); // Возвращает новый план

    // Метод: Корректирует план на основе обратной связи 
    void adjustFromFeedback(const std::string& userFeedback);

    // Метод: Возвращает список предстоящих сессий
    std::list<TrainingSession> listNextSessions(int count) const;

private:
    std::string id; // Идентификатор плана
    std::string ownerUserId; // Владелец плана
    std::string startDate; // Дата начала периода
    std::string endDate; // Дата конца периода
    std::list<TrainingSession> sessions; // Список тренировок
};

#endif
