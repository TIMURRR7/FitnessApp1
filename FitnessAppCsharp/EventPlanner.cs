using System;
using System.Collections.Generic;

public class EventPlanner
{
    // Поля класса
    private List<string> plannedEvents;     // Список запланированных событий (например, "2025-04-05 18:00 - Тренировка ног")
    private string notifyRules;             // Правила уведомлений (например, "за 30 минут", "утром в 9:00")

    // Конструктор: инициализирует календарь и правила напоминаний
    public EventPlanner(List<string> plannedEvents, string notifyRules)
    {
        this.plannedEvents = plannedEvents;
        this.notifyRules = notifyRules;
    }

    // Метод: добавляет тренировку в расписание (возвращает статус)
    public string AddToSchedule(TrainingSession session)
    {
        
        plannedEvents.Add($"Тренировка: {session.GetSessionName()} - {DateTime.Now:yyyy-MM-dd HH:mm}");
        return "Scheduled"; // как в C++ версии
    }

    // Метод: откладывает уведомление для события
    public void DelayNotification(string eventId, int delayMin)
    {
        // Заглушка 
        Console.WriteLine($"Уведомление для {eventId} отложено на {delayMin} минут");
    }

    // Метод: переносит пропущенные тренировки на следующий доступный день
    public void RescheduleMissed()
    {
        // Заглушка
        Console.WriteLine("Пропущенные тренировки перенесены автоматически");
    }
}