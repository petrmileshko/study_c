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

#define MAX_CHARS 50

int main(void)
{

    bool locale_status = true;
    int analysis_table[MAX_CHARS + 1] = {0}; // 51 элемент массива будет хранить количество слов длиной 50 и более 
    // элементы с 1 по 49 будут хранить количество слов, длины которых соответсвуют индексу элемента 

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

    // Протестируем вывод мз массива с тестовыми данными
    analysis_table[4] = 3;
    analysis_table[5] = 2;
    analysis_table[1] = 4;
    analysis_table[50] = 1;
    analysis_table[51] = 2;

    if (locale_status)
    {
        printf("   %s | %s\n","Длина","Слов");
    } else
    {
        printf("%8s | %s\n","Length","Words");

    }

    for (int i = 1; i <= MAX_CHARS + 1; i++)
    {
        if(analysis_table[i] > 0 && i <= MAX_CHARS)
        {
            printf("%8d | %d\n", i, analysis_table[i]);
        } else if(i == MAX_CHARS + 1)
        {
            printf("      50+| %d\n",analysis_table[i]);
        }
    }
    
    return 0;
}
