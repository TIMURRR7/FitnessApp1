using System;
using System.Collections.Generic;

public class TrainingSchedule
{
    // Поля 
    private string id;
    private string ownerUserId;
    private string startDate;
    private string endDate;
    private List<TrainingSession> sessions;

    // Конструктор по умолчанию
    public TrainingSchedule()
    {
        id = "";
        ownerUserId = "";
        startDate = "";
        endDate = "";
        sessions = new List<TrainingSession>();
    }

    // Конструктор с параметрами
    public TrainingSchedule(string id, string ownerUserId, string startDate,
        string endDate, List<TrainingSession> sessions)
    {
        this.id = id;
        this.ownerUserId = ownerUserId;
        this.startDate = startDate;
        this.endDate = endDate;
        this.sessions = new List<TrainingSession>(sessions); 
    }

    // Метод: генерирует новый план (заглушка — возвращает копию текущего)
    public TrainingSchedule CreatePlan(ProfileManager user, FitnessDatabase library)
    {
       
        return new TrainingSchedule(this.id, this.ownerUserId, this.startDate, this.endDate, this.sessions);
    }

    // Метод: корректирует план (заглушка)
    public void AdjustFromFeedback(string userFeedback)
    {
        // Заглушка 
    }

    // Метод: возвращает предстоящие сессии (заглушка)
    public List<TrainingSession> ListNextSessions(int count)
    {
        return new List<TrainingSession>(); 
    }

  
    public string GetId() { return id; }
    public string GetOwnerUserId() { return ownerUserId; }
    public string GetStartDate() { return startDate; }
    public string GetEndDate() { return endDate; }
    public List<TrainingSession> GetSessions() { return sessions; }

   
}