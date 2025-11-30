#ifndef FUNMASCOT_HPP
#define FUNMASCOT_HPP

#include <string>
#include <set>
#include "TrainingSession.hpp"

// Класс FunMascot: Логика маскота (котика)
class FunMascot {
public:
    enum class MascotMood { HAPPY, SAD, MOTIVATED }; // Настроение маскота

    // Конструктор: Инициализирует маскота
    FunMascot(const std::string& userId, MascotMood currentMood, int experiencePoints,
        const std::set<std::string>& unlockedSkins);

    // Конструктор копирования
    FunMascot(const FunMascot& other);

    // Деструктор
    ~FunMascot();

    // Метод: Реакция на статус тренировки
    std::string respondToSession(TrainingSession::WorkoutStatus outcome) const;

private:
    std::string userId; // Идентификатор пользователя
    MascotMood currentMood; // Текущее настроение
    int experiencePoints; // Очки опыта
    std::set<std::string> unlockedSkins; // Разблокированные скины
};

#endif
