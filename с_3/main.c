#include <stdio.h>

/* Программа вывода таблицы температур:
 *   Фаренгейт → Цельсия
 * Диапазон: от 0 до 300 °F с шагом 20 °F
 */

// Символические константы
#define LOWER 0   // нижний предел
#define UPPER 300 // верхний предел
#define STEP 20   // шаг

int main()
{
    printf("TABLE OF TEMPERATURE\n"); // Заголовок таблицы

    /* Для вывода используем цикл for и символические константы */
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d\t%6.1f\n", fahr, 5.0 * (fahr - 32.0) / 9.0);
}
