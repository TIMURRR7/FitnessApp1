#ifndef CARDIOACTIVITY_HPP
#define CARDIOACTIVITY_HPP

#include "Activity.hpp"

class CardioActivity : public Activity {
public:
    CardioActivity(double distanceKm)
        : Activity("cardio_id", "Кардио", { MuscleGroup::LEGS }, ActivityType::CARDIO,
            {}, ProfileManager::Level::BEGINNER, "Кардио"),
        distance(distanceKm)
    {
        baseCaloriesPerMin = 10;
    }

    int estimateCalories(int duration) const override {
        return static_cast<int>(duration * baseCaloriesPerMin + distance * 30);
    }

private:
    double distance;
};

#endif
