#include "StrengthActivity.hpp"
#include "StandardExecutionStrategy.hpp"
#include "ProgressiveOverloadStrategy.hpp"
#include "PyramidStrategy.hpp"
#include "ProfileManager.hpp"
#include "Activity.hpp"
#include "STL.hpp"
#include "Template_Functions.hpp"
#include "FitnessProgram.hpp"
#include "FitnessTracker.hpp"
#include "CompileTimeDemo.hpp"
#include "FitnessCalculator.hpp"
#include <iostream>
#include <set>
#include <stdexcept>
#include <windows.h>
#include <memory>

int main() {
    SetConsoleOutputCP(1251);


    // 1. ДЕМОНСТРАЦИЯ CONSTEXPR, CONSTEVAL И CONSTINIT
    std::cout << "1. Демонстрация constexpr, consteval и constinit:" << std::endl;
    

    demonstrateCompileTimeFeatures();

    // 2. ДЕМОНСТРАЦИЯ ФИТНЕС-КАЛЬКУЛЯТОРА С COMPILE-TIME ВЫЧИСЛЕНИЯМИ
    std::cout << "\n\n2. Демонстрация фитнес-калькулятора:" << std::endl;


    FitnessCalculator::demonstrateFitnessCalculations();


    return 0;
}
