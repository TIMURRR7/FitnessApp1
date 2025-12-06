#ifndef STRENGTHACTIVITY_HPP
#define STRENGTHACTIVITY_HPP

#include "Activity.hpp"

class StrengthActivity : public Activity {
public:
    StrengthActivity(const std::string& id,
        const std::string& title,
        const std::set<MuscleGroup>& targetedMuscles,
        const std::set<ProfileManager::Equipment>& requiredEquipment,
        ProfileManager::Level complexity,
        const std::string& description,
        int sets, int reps, double weightKg)
        : Activity(id, title, targetedMuscles, ActivityType::STRENGTH,
            requiredEquipment, complexity, description),
        sets(sets), reps(reps), weightKg(weightKg)
    {
        baseCaloriesPerMin = 8;
    }

    int estimateCalories(int duration) const override {
        return static_cast<int>(duration * baseCaloriesPerMin + sets * reps * 0.5);
    }

private:
    int sets;
    int reps;
    double weightKg;
};

#endif
