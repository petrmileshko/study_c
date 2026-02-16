/** Программа вывода таблицы температур:
 *        Фаренгейт     Цельсия
 * от 0 до 300 с шагом 20 Фаренгейт
 */
#include <stdio.h>

int main()
{
    int fahr, celcius;

    fahr = 0;
    celcius = 5*(fahr-32)/9;
    printf("%d\t%d\n",fahr, celcius);
}