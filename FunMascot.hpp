#ifndef FUNMASCOT_HPP
#define FUNMASCOT_HPP

#include <string>
#include <set>
#include "ProfileManager.hpp"
#include "ProgressTracker.hpp"
#include "TrainingSession.hpp" 

// Класс FunMascot: Логика маскота (котика)
class FunMascot {
public:
    enum class MascotMood { HAPPY, SAD, MOTIVATED }; // Настроение маскота

    // Конструктор: Инициализирует маскота
    FunMascot(const std::string& userId, MascotMood currentMood, int experiencePoints,
        const std::set<std::string>& unlockedSkins);

    // Деструктор
    ~FunMascot();

    // Метод: Реакция на статус тренировки
    std::string respondToSession(TrainingSession::WorkoutStatus outcome) const;

    // Метод: Начисляет очки опыта
    void addExperience(int points);

    // Метод: Генерирует мотивационное сообщение
    std::string generateMotivation(const ProfileManager& user, const ProgressTracker& tracker) const;

private:
    std::string userId; // Идентификатор пользователя
    MascotMood currentMood; // Текущее настроение
    int experiencePoints; // Очки опыта
    std::set<std::string> unlockedSkins; // Разблокированные скины
};

#endif
