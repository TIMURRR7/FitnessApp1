using System;

namespace FitnessApp2
{
    public interface ITrackable
    {
        string GetTrackingInfo();           // Возвращает информацию для отслеживания
        void LogProgress(DateTime date);    // Записывает прогресс на определенную дату
        bool IsCompleted();                 // Проверяет, завершено ли задание/тренировка
    }
}
