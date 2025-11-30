#ifndef SIMPLEUSER_HPP
#define SIMPLEUSER_HPP

#include "ProfileManager.hpp"

class SimpleUser : public ProfileManager {
public:
    SimpleUser(const std::string& id, const std::string& username, std::string additionalInfo)
        : ProfileManager(id, username, 0, ProfileManager::Gender::MALE, 0, 0,
            ProfileManager::Goal::HEALTH, ProfileManager::Level::BEGINNER,
            {}, {}, false),
        additionalInfo(additionalInfo) {}

    SimpleUser(const SimpleUser& other) : ProfileManager(other), additionalInfo(other.additionalInfo) {}

private:
    std::string additionalInfo;

public:
    std::string getAdditionalInfo() const { return this->additionalInfo; }
};

#endif
