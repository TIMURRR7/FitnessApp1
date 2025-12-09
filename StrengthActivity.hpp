#ifndef STRENGTHACTIVITY_HPP
#define STRENGTHACTIVITY_HPP

#include "Activity.hpp"
#include "IExecutionStrategy.hpp"

// Производный класс StrengthActivity: Силовое упражнение
class StrengthActivity : public Activity {
public:
    // Перечисление типов стратегий выполнения
    enum class ExecutionType { STANDARD, PROGRESSIVE_OVERLOAD, PYRAMID };

    StrengthActivity(const std::string& id, const std::string& title,
        const std::set<MuscleGroup>& targetedMuscles,
        const std::set<ProfileManager::Equipment>& requiredEquipment,
        ProfileManager::Level complexity, const std::string& description,
        int sets, int reps, double weightKg, ExecutionType execType = ExecutionType::STANDARD);

    // Конструктор копирования
    StrengthActivity(const StrengthActivity& other);

   
    StrengthActivity& operator=(const Activity& other);
    StrengthActivity& operator=(const StrengthActivity& other) = delete;

    int getDurationEstimate() const override;

    bool matchesUser(const ProfileManager& user) const override;

    void generateReport() const override;

    std::unique_ptr<Activity> clone() const override;
    int getSets() const { return sets; }
    int getReps() const { return reps; }
    double getWeightKg() const { return weightKg; }

    
    void execute() const;
    void setExecutionStrategy(std::unique_ptr<IExecutionStrategy> strategy);
    const IExecutionStrategy* getExecutionStrategy() const { return executionStrategy.get(); }
    std::string getExecutionStrategyDescription() const;

private:
    int sets; // Количество подходов
    int reps; // Количество повторений
    double weightKg; // Вес в кг
    std::unique_ptr<IExecutionStrategy> executionStrategy; // Стратегия выполнения (делегирование)

   
    std::unique_ptr<IExecutionStrategy> createStrategy(ExecutionType type) const;
};

#endif

