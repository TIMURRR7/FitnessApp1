#ifndef PYRAMID_STRATEGY_HPP
#define PYRAMID_STRATEGY_HPP

#include "IExecutionStrategy.hpp"
#include <iostream>
#include <algorithm>

// Пирамидальная стратегия: вес увеличивается, повторения уменьшаются
class PyramidStrategy : public IExecutionStrategy {
private:
    double weightIncrement; // Прирост веса (в кг)
    int repsDecrement;      // Уменьшение повторений

public:
    PyramidStrategy(double weightInc = 5.0, int repsDec = 2)
        : weightIncrement(weightInc), repsDecrement(repsDec) {}

    void execute(int sets, int reps, double weightKg) const override {
        std::cout << "=== Пирамидальная тренировка ===" << std::endl;

        double totalVolume = 0;
        double currentWeight = weightKg;
        int currentReps = reps;

        for (int set = 1; set <= sets; ++set) {
            std::cout << "Подход " << set << ": " << currentReps << " повторений с весом " << currentWeight << " кг" << std::endl;
            totalVolume += currentReps * currentWeight;

            currentWeight += weightIncrement;
            currentReps = std::max(1, currentReps - repsDecrement); 
        }

        std::cout << "Общий объем: " << totalVolume << " кг" << std::endl;
    }

    std::string getDescription() const override {
        return "Пирамидальная тренировка: вес увеличивается на " + std::to_string(weightIncrement) +
            " кг, повторения уменьшаются на " + std::to_string(repsDecrement);
    }

    double calculateNextWeight(double currentWeight, int setNumber, bool completedSuccessfully) const override {
        if (completedSuccessfully) {
            return currentWeight + weightIncrement;
        }
        return currentWeight - weightIncrement; // Уменьшаем вес, если не справились
    }

    std::unique_ptr<IExecutionStrategy> clone() const override {
        return std::make_unique<PyramidStrategy>(*this);
    }

    double getWeightIncrement() const { return weightIncrement; }
    int getRepsDecrement() const { return repsDecrement; }
};

#endif
