#ifndef FITNESSCOMPONENT_HPP
#define FITNESSCOMPONENT_HPP

#include <string>
#include <iostream>

class FitnessComponent {
public:
    virtual ~FitnessComponent() {
        std::cout << "FitnessComponent destructor" << std::endl;
    }

    virtual std::string getInfo() const = 0;
    virtual FitnessComponent* clone() const = 0;
    virtual double calculateSomething() const { return 0.0; }

    void callVirtual() const {
        std::cout << "Результат виртуального: " << calculateSomething() << std::endl;
    }
};

#endif
