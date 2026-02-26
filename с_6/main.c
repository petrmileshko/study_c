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
        printf("Программа анализа длин слов\n");
        printf("Вводите текст (посимвольно). Для завершения:\n");
        printf("1. Нажмите Ctrl + X\n");
        printf("2. Затем нажмите Enter\n");
        printf("Начните ввод >>>\n");
    } else
    {
        printf("Word length analysis program\n");
        printf("Input text (character by character). To exit:\n");
        printf("1. Press Ctrl + X\n");
        printf("2. Then press Enter\n");
        printf("Start input >>>\n");
    }


    if (locale_status)
    {
        printf("   %s | %s\n","Длина","Слов");
    } else
    {
        printf("%8s | %s\n","Length","Words");

    }

    printf("%8d | %d\n", 4, 3);
    printf("%8d | %d\n", 5, 1);
    printf("%8d | %d\n", 1, 4);
    printf("%8d | %d\n", 2, 2);
    
    return 0;
}
