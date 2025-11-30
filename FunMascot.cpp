#include "FunMascot.hpp"

// Конструктор: Инициализирует поля
FunMascot::FunMascot(const std::string& userId, MascotMood currentMood, int experiencePoints,
    const std::set<std::string>& unlockedSkins)
    : userId(userId), currentMood(currentMood), experiencePoints(experiencePoints), unlockedSkins(unlockedSkins) {}

// Конструктор копирования
FunMascot::FunMascot(const FunMascot& other)
    : userId(other.userId), currentMood(other.currentMood), experiencePoints(other.experiencePoints),
    unlockedSkins(other.unlockedSkins) {}

// Деструктор
FunMascot::~FunMascot() {}


// Метод: Реакция на сессию
std::string FunMascot::respondToSession(TrainingSession::WorkoutStatus outcome) const {
    return "Good job!"; 
}
