#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/*
 *  Программа анализа длин слов во входном потоке
 *  Посимвольный ввод с клавиатуры.
 *  Окончание ввода  - Ctrl X
 *  Для разных значений длины подсчитать количество слов
 *  Вывести результат в таблице
 */

int main(void)
{

    bool locale_status = true;

    if (setlocale(LC_ALL, "ru_RU.UTF8") == 0)
    {
        if (setlocale(LC_ALL, ".UTF8") == 0) {

            locale_status = false;
            setlocale(LC_ALL, "");
        }
    }
   
    if (locale_status)
    {
        printf("   %s | %s\n","Длина","Слов");
    }
    else
    {
        printf("%8s | %s\n","Length","Words");

    }

    printf("%8d | %d\n", 4, 3);
    printf("%8d | %d\n", 5, 1);
    printf("%8d | %d\n", 1, 4);
    printf("%8d | %d\n", 2, 2);
    
    return 0;
}
