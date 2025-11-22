using System;
using System.Collections.Generic;

public class TrainingSession
{
    // Перечисление: статус тренировки
    public enum WorkoutStatus { PLANNED, COMPLETED }    // Запланирована / Завершена

    // Поля класса
    private string id;                    // Уникальный ID сессии
    private string scheduledDate;         // Дата и время тренировки (в виде строки, например "2025-04-05 18:00")
    private int estDurationMin;           // Ожидаемая длительность в минутах
    private string sessionName;           // Название тренировки (например "Тренировка ног")
    private List<string> exerciseBlocks;  // Список блоков упражнений (упрощённо — строки)
    private WorkoutStatus currentStatus;    // Текущий статус сессии

    // Конструктор: создаёт новую тренировочную сессию
    public TrainingSession(string id, string scheduledDate, int estDurationMin,
        string sessionName, List<string> exerciseBlocks, WorkoutStatus currentStatus)
    {
        this.id = id;
        this.scheduledDate = scheduledDate;
        this.estDurationMin = estDurationMin;
        this.sessionName = sessionName;
        this.exerciseBlocks = exerciseBlocks;
        this.currentStatus = currentStatus;
    }

    // Метод: начинает сессию (меняет статус на PLANNED)
    public void BeginSession()
    {
        currentStatus = WorkoutStatus.PLANNED;
        Console.WriteLine($"[Сессия {id}] Начата: {sessionName}");
    }

    // Метод: завершает сессию (меняет статус на COMPLETED)
    public void FinishSession(string results)
    {
        currentStatus = WorkoutStatus.COMPLETED;
        Console.WriteLine($"[Сессия {id}] Завершена. Результат: {results}");
    }

    // Метод: переносит тренировку на новую дату
    public void ShiftDate(string newScheduledDate)
    {
        scheduledDate = newScheduledDate;
        Console.WriteLine($"[Сессия {id}] Перенесена на: {newScheduledDate}");
    }

    // Метод: рассчитывает сожжённые калории 
    public int CalcBurnedCalories(ProfileManager user)
    {
        return 500; // заглушка
    }

    public string GetSessionName()
    {
        return sessionName;
    }
}