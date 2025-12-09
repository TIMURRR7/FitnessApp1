#ifndef STANDARD_EXECUTION_STRATEGY_HPP
#define STANDARD_EXECUTION_STRATEGY_HPP

#include "IExecutionStrategy.hpp"
#include <iostream>

// Стандартная стратегия выполнения
class StandardExecutionStrategy : public IExecutionStrategy {
public:
    void execute(int sets, int reps, double weightKg) const override {
        std::cout << "=== Стандартная тренировка ===" << std::endl;
        for (int set = 1; set <= sets; ++set) {
            std::cout << "Подход " << set << ": " << reps << " повторений с весом " << weightKg << " кг" << std::endl;
        }
        std::cout << "Общий объем: " << (sets * reps * weightKg) << " кг" << std::endl;
    }

    std::string getDescription() const override {
        return "Стандартная тренировка: все подходы выполняются с одинаковым весом и количеством повторений";
    }

    double calculateNextWeight(double currentWeight, int setNumber, bool completedSuccessfully) const override {
        return currentWeight;
    }

    std::unique_ptr<IExecutionStrategy> clone() const override {
        return std::make_unique<StandardExecutionStrategy>(*this);
    }
};

#endif
