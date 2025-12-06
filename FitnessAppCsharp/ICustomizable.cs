using System.Collections.Generic;  

namespace FitnessApp2
{
    public interface ICustomizable
    {
        void AddCustomModification(string modification);  // Добавить пользовательскую модификацию
        List<string> GetModifications();                   // Получить все модификации
        void ResetToDefault();                            // Сбросить настройки к значениям по умолчанию
    }
}
