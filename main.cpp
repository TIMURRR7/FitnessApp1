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
#include <iostream>
#include <set>
#include <stdexcept>
#include <windows.h>
#include <memory>

int main() {
    SetConsoleOutputCP(1251);
   
  

    // 1. ДЕМОНСТРАЦИЯ ИСПОЛЬЗОВАНИЯ STL
    std::cout << "\n\n1. Демонстрация использования STL:" << std::endl;

    STL_Demo stlDemo;
    stlDemo.demonstrateVectorUsage();
    stlDemo.demonstrateListUsage();
    stlDemo.demonstrateMapUsage();
    stlDemo.demonstrateArrayUsage();

    // 2. ДЕМОНСТРАЦИЯ ШАБЛОННЫХ ФУНКЦИЙ
    std::cout << "\n\n2. Демонстрация шаблонных функций:" << std::endl;
 

    demonstrateTemplateFunctions();

    // 3. ДЕМОНСТРАЦИЯ ШАБЛОННОГО КЛАССА
    std::cout << "\n\n3. Демонстрация шаблонного класса:" << std::endl;
 

    demonstrateFitnessProgram();



    return 0;
}
