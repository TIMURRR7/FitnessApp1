#include "TrainingSession.hpp"
#include <stdexcept>

// Конструктор: Инициализирует все поля
TrainingSession::TrainingSession(const std::string& id, const std::string& scheduledDate, int estDurationMin,
    const std::string& sessionName, const std::list<std::string>& exerciseBlocks,
    WorkoutStatus currentStatus)
    : id(id), scheduledDate(scheduledDate), estDurationMin(estDurationMin), sessionName(sessionName),
    exerciseBlocks(exerciseBlocks), currentStatus(currentStatus) {}

// Конструктор копирования
TrainingSession::TrainingSession(const TrainingSession& other)
    : id(other.id), scheduledDate(other.scheduledDate), estDurationMin(other.estDurationMin),
    sessionName(other.sessionName), exerciseBlocks(other.exerciseBlocks), currentStatus(other.currentStatus) {}

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

// Перегрузка оператора ==
bool TrainingSession::operator==(const TrainingSession& other) const {
    return this->id == other.id;
}

// Перегрузка оператора +=
TrainingSession& TrainingSession::operator+=(const std::string& exercise) {
    this->exerciseBlocks.push_back(exercise);
    return *this;
}
