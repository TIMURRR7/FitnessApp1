#ifndef SIMPLEUSER_HPP
#define SIMPLEUSER_HPP

#include "ProfileManager.hpp"
#include "FitnessComponent.hpp"

class SimpleUser : public ProfileManager {
public:
    SimpleUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate,
        Gender gender, int heightCm, double currentWeight, Goal goal, Level level, std::string additionalInfo)
        : ProfileManager(id, username, 25, gender, heightCm, currentWeight, goal, level,
            { Weekday::MONDAY }, { Equipment::DUMBBELLS }, true),
        additionalInfo(additionalInfo)
    {}

    SimpleUser(const SimpleUser& other) = delete;

    ~SimpleUser() override {
        std::cout << "SimpleUser destructor" << std::endl;
    }

   
    double calculateSomething() const override {
        return calculateBMI() + 10.0;
    }

    SimpleUser& operator=(const ProfileManager& base) {
        if (this != &base) {
            ProfileManager::operator=(base);
            additionalInfo = "assigned from base";
        }
        return *this;
    }

    std::string getAdditionalInfo() const { return this->additionalInfo; }

private:
    std::string additionalInfo;
};

#endif
