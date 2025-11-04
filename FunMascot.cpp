#include "FunMascot.hpp"

// Конструктор: Инициализирует поля
FunMascot::FunMascot(const std::string& userId, MascotMood currentMood, int experiencePoints,
    const std::set<std::string>& unlockedSkins)
    : userId(userId), currentMood(currentMood), experiencePoints(experiencePoints), unlockedSkins(unlockedSkins) {}

// Деструктор
FunMascot::~FunMascot() {}

// Метод: Реакция на сессию (заглушка)
std::string FunMascot::respondToSession(TrainingSession::WorkoutStatus outcome) const {
    return "Good job!"; // Пример
}

// Метод: Добавление опыта
void FunMascot::addExperience(int points) {
    experiencePoints += points;
}

// Метод: Генерирует мотивацию (заглушка)
std::string FunMascot::generateMotivation(const ProfileManager& user, const ProgressTracker& tracker) const {
    return "Keep going!"; // Пример
}
