#ifndef PROGRESSIVE_OVERLOAD_STRATEGY_HPP
#define PROGRESSIVE_OVERLOAD_STRATEGY_HPP

#include "IExecutionStrategy.hpp"
#include <iostream>
#include <algorithm>

// Стратегия прогрессивной перегрузки: постепенное увеличение веса
class ProgressiveOverloadStrategy : public IExecutionStrategy {
private:
    double weightIncrement; // Прирост веса между подходами (в кг)

public:
    explicit ProgressiveOverloadStrategy(double increment = 2.5) : weightIncrement(increment) {}

    void execute(int sets, int reps, double weightKg) const override {
        std::cout << "=== Прогрессивная перегрузка ===" << std::endl;
        double currentWeight = weightKg;

        for (int set = 1; set <= sets; ++set) {
            std::cout << "Подход " << set << ": " << reps << " повторений с весом " << currentWeight << " кг" << std::endl;
            currentWeight += weightIncrement;
        }

        double totalVolume = 0;
        currentWeight = weightKg;
        for (int set = 1; set <= sets; ++set) {
            totalVolume += reps * currentWeight;
            currentWeight += weightIncrement;
        }

        std::cout << "Общий объем: " << totalVolume << " кг" << std::endl;
    }

    std::string getDescription() const override {
        return "Прогрессивная перегрузка: вес увеличивается на " + std::to_string(weightIncrement) + " кг с каждым подходом";
    }

    double calculateNextWeight(double currentWeight, int setNumber, bool completedSuccessfully) const override {
        if (completedSuccessfully) {
            return currentWeight + weightIncrement;
        }
        return currentWeight; 
    }

    std::unique_ptr<IExecutionStrategy> clone() const override {
        return std::make_unique<ProgressiveOverloadStrategy>(*this);
    }

    double getWeightIncrement() const { return weightIncrement; }
};

#endif
