#ifndef DIETPROGRAM_HPP
#define DIETPROGRAM_HPP

#include <string>
#include <list>

// Класс DietProgram: План питания
class DietProgram {
public:
    // Конструктор: Инициализирует план питания
    DietProgram(const std::string& id, const std::string& ownerUserId, const std::string& planDate,
        const std::list<std::string>& dailyMeals, const std::string& dailyTargets);

    // Деструктор
    ~DietProgram();

    // Метод: Обновляет план по изменению веса (заглушка)
    void updateForWeightShift(double weightDelta);

    // Метод: Рассчитывает суммарные нутриенты за день (заглушка)
    std::string calcDailySummary() const;

    // Метод: Заменяет блюдо в плане (заглушка)
    void swapDish(const std::string& mealTime, const std::string& replacement);

private:
    std::string id; // Идентификатор
    std::string ownerUserId; // Владелец
    std::string planDate; // Дата плана
    std::list<std::string> dailyMeals; // Приемы пищи
    std::string dailyTargets; // Цели по нутриентам
};

#endif
