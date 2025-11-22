using System;
using System.Collections.Generic;

public class FunMascot
{
    // Настроение маскота
    public enum MascotMood { HAPPY, SAD, MOTIVATED }

    // Поля класса 
    private string userId;                    // Кому принадлежит маскот
    private MascotMood currentMood;           // Текущее настроение
    private int experiencePoints;             // Очки опыта
    private HashSet<string> unlockedSkins;    // Разблокированные скины 

    // Конструктор
    public FunMascot(string userId, MascotMood currentMood, int experiencePoints,
        HashSet<string> unlockedSkins)
    {
        this.userId = userId;
        this.currentMood = currentMood;
        this.experiencePoints = experiencePoints;
        this.unlockedSkins = new HashSet<string>(unlockedSkins);
    }

    // Метод: реакция маскота на результат тренировки
    public string RespondToSession(TrainingSession.WorkoutStatus outcome)
    {
        if (outcome == TrainingSession.WorkoutStatus.COMPLETED)
        {
            currentMood = MascotMood.HAPPY;
            return "Отличная работа! Ты молодец!";
        }
        else
        {
            currentMood = MascotMood.SAD;
            return "Не расстраивайся, завтра получится лучше!";
        }
    }

    // Метод: начисляет очки опыта
    public void AddExperience(int points)
    {
        experiencePoints += points;
        Console.WriteLine($"[Маскот] +{points} XP! Всего: {experiencePoints}");

        // Каждые 100 очков — улучшаем настроение
        if (experiencePoints % 100 == 0)
            currentMood = MascotMood.MOTIVATED;
    }

    // Метод: генерирует мотивационное сообщение
    public string GenerateMotivation(ProfileManager user, ProgressTracker tracker)
    {
        int streak = tracker.GetActiveStreak();
        double bmi = user.CalculateBMI();

        if (streak >= 7)
            return "Ты на огне! Стрик " + streak + " дней! Котик гордится тобой!";
        if (bmi < 18.5)
            return "Не забывай кушать! Котик хочет, чтобы ты был сильным!";
        if (bmi > 25)
            return "Всё под контролем! Ещё немного — и ты будешь в форме! Мяу!";

        return "Ты на правильном пути!";
    }

    // Геттеры
    public MascotMood GetMood() => currentMood;
    public int GetExperiencePoints() => experiencePoints;
    public HashSet<string> GetUnlockedSkins() => unlockedSkins;
}