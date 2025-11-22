using System;
using System.Collections.Generic;

public class ProgressTracker
{
    // Поля класса 
    private string userId;                                          // ID пользователя
    private List<KeyValuePair<string, double>> weightLog;           // История веса: (дата, вес)
    private List<string> sessionHistory;                            // История завершённых сессий
    private int activeStreak;                                       // Текущий стрик (дни подряд)

    // Конструктор
    public ProgressTracker(string userId, List<KeyValuePair<string, double>> weightLog,
        List<string> sessionHistory, int activeStreak)
    {
        this.userId = userId;
        this.weightLog = new List<KeyValuePair<string, double>>(weightLog);     
        this.sessionHistory = new List<string>(sessionHistory);                
        this.activeStreak = activeStreak;
    }

    // Метод: записывает результат завершённой тренировки
    public void LogSessionOutcome(string outcome)
    {
        sessionHistory.Add(outcome);
        activeStreak++; 
        Console.WriteLine($"[Progress] Зафиксирована сессия: {outcome}. Стрик: {activeStreak} дней");
    }

    // Метод: рассчитывает процент соблюдения плана за период (заглушка )
    public double CalcCompliance(string interval)
    {
        return 90.0; // фиксированное значение
    }

    public string GetUserId() => userId;
    public int GetActiveStreak() => activeStreak;
    public List<KeyValuePair<string, double>> GetWeightLog() => weightLog;
    public List<string> GetSessionHistory() => sessionHistory;

 
}