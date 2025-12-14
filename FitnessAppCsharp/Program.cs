using System;
using System.Text;
using System.Collections.Generic;


namespace FitnessApp2
{
    class Program
    {
        static void Main()
        {
            System.Console.OutputEncoding = System.Text.Encoding.UTF8;

            // 1. Демонстрация использования .NET Collections Framework
            Demo.DemonstrateCollections();

            // 2. Демонстрация обобщенных функций
            Demo.DemonstrateGenericFunctions();

            // 3. Демонстрация обобщенного класса
            Demo.DemonstrateGenericClass();

            System.Console.WriteLine("\n=== Демонстрация завершена ===");
        }
    }
}
