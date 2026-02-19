#include <stdio.h>

/* Программа вывода таблицы температур:
 *   Фаренгейт → Цельсия
 * Диапазон: от 0 до 300 °F с шагом 20 °F
 */

// Константы (C23: предпочтительнее const, чем #define)
static const int TEMPERATURE_MIN_F = 0;   // нижний предел, °F
static const int TEMPERATURE_MAX_F = 300; // верхний предел, °F
static const int TEMPERATURE_STEP_F = 20; // шаг, °F
// Более информативные названия констант;
// Область видимости ограничена файлом (static);
// Отладка проще (константы видны в отладчике).

// void - явно указано отсутствие параметров
int main(void)
{
    // TEMPERATURES вместо TEMPERATURE - орфография
    printf("TABLE OF TEMPERATURES\n");

    for (int fahr = TEMPERATURE_MIN_F;
         fahr <= TEMPERATURE_MAX_F;
         fahr += TEMPERATURE_STEP_F)
    {
        float celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3d\t%6.1f\n", fahr, celsius);
    }
    // Фигурные скобки лучше указывать даже для одного оператора.
    // Код легче читать и отлаживать.
    // Формула не «замурована» в printf.

    return 0; // Явное возвращение — хорошая практика (хотя в C23 не обязательно)
}
