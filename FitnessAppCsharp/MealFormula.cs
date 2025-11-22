using System;
using System.Collections.Generic;

public class MealFormula
{
    // Поля класса
    private string id;                          // Уникальный ID рецепта
    private string dishName;                    // Название блюда
    private List<string> componentList;         // Список ингредиентов
    private string nutritionPerPortion;         // Нутриенты на одну порцию (например, "300 ккал, 25г белка")
    private int prepTimeMin;                    // Время приготовления в минутах

    // Конструктор
    public MealFormula(string id, string dishName, List<string> componentList,
        string nutritionPerPortion, int prepTimeMin)
    {
        this.id = id;
        this.dishName = dishName;
        this.componentList = new List<string>(componentList); 
        this.nutritionPerPortion = nutritionPerPortion;
        this.prepTimeMin = prepTimeMin;
    }

    // Метод: пересчитывает нутриенты на заданное количество порций
    public string AdjustPortions(double portionFactor)
    {
        if (portionFactor <= 0) return "Ошибка: порции должны быть больше 0";

        // Пример: "300 ккал" → "900 ккал" при portionFactor = 3
        string result = $"Порции: {portionFactor:F1}\n" +
                        $"Калорийность: {ExtractCalories() * portionFactor} ккал\n" +
                        $"Время приготовления: {prepTimeMin * portionFactor:F0} мин";

        return result;
    }

    // Метод: проверяет, подходит ли блюдо пользователю (заглушка с логикой)
    public bool FitsUserPrefs(ProfileManager user)
    {
        
        // Если цель — похудеть, и блюдо слишком калорийное — не подходит
        if (user.GetGoal() == ProfileManager.Goal.LoseWeight && ExtractCalories() > 500)
            return false;

 
        return true;
    }

    // Вспомогательный метод: вытаскиваем калории из строки 
    private int ExtractCalories()
    {
        // Ищем число перед "ккал"
        var parts = nutritionPerPortion.Split(' ');
        foreach (var part in parts)
        {
            if (int.TryParse(part, out int kcal))
                return kcal;
        }
        return 300; 
    }

    // Геттеры 
    public string GetDishName() => dishName;
    public string GetId() => id;
    public List<string> GetIngredients() => componentList;
    public string GetNutritionInfo() => nutritionPerPortion;
    public int GetPrepTime() => prepTimeMin;
}