#include "TrainingSession.hpp"

// Конструктор: Инициализирует все поля
TrainingSession::TrainingSession(const std::string& id, const std::string& scheduledDate, int estDurationMin,
    const std::string& sessionName, const std::list<std::string>& exerciseBlocks,
    WorkoutStatus currentStatus)
    : id(id), scheduledDate(scheduledDate), estDurationMin(estDurationMin), sessionName(sessionName),
    exerciseBlocks(exerciseBlocks), currentStatus(currentStatus) {}

// Деструктор
TrainingSession::~TrainingSession() {}

// Метод: Начинает сессию (устанавливает статус PLANNED)
void TrainingSession::beginSession() {
    currentStatus = WorkoutStatus::PLANNED;
}

// Метод: Завершает сессию (устанавливает статус COMPLETED)
void TrainingSession::finishSession(const std::string& results) {
    currentStatus = WorkoutStatus::COMPLETED;
}

// Метод: Переносит дату
void TrainingSession::shiftDate(const std::string& newScheduledDate) {
    scheduledDate = newScheduledDate;
}

// Метод: Рассчитывает калории (заглушка)
int TrainingSession::calcBurnedCalories(const ProfileManager& user) const {
    return 500;
}
