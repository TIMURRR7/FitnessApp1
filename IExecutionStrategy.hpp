#ifndef IEXECUTIONSTRATEGY_HPP
#define IEXECUTIONSTRATEGY_HPP

#include <string>
#include <memory>

// Интерфейс стратегии выполнения упражнения
class IExecutionStrategy {
public:
    virtual ~IExecutionStrategy() = default;

    // Выполнение упражнения с учетом стратегии
    virtual void execute(int sets, int reps, double weightKg) const = 0;

    // Получение описания стратегии
    virtual std::string getDescription() const = 0;

    // Расчет рекомендуемого веса для следующего подхода
    virtual double calculateNextWeight(double currentWeight, int setNumber, bool completedSuccessfully) const = 0;

    virtual std::unique_ptr<IExecutionStrategy> clone() const = 0;
};

#endif
