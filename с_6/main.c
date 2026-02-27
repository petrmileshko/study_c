#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/*
 *  Программа анализа длин слов во входном потоке
 *  Посимвольный ввод с клавиатуры только латинскими буквами.
 *  Окончание ввода  - Ctrl X
 *  Для разных значений длины подсчитать количество слов
 *  Вывести результат в таблице или в виде гистограммы
 */

// максимальная длина слова (допустить, что слова более этого значения встречаются редко)
#define MAX_CHARS 50

// способы вывода результатов 0 - таблица, в противном случае - гистограмма
#define OUTPUT_TYPE 0

// символ, используемый для рисования гистограммы
#define HIST_CHAR '*'

int main(void)
{
    // флаг региональной настройки программы для вывода на экран
    bool localeStatus = true;

    // текущий и послений символы
    int currentСhar,
        lastСhar = '\n';

    int analysisTable[MAX_CHARS + 1] = {0};
    // 50 элемент массива будет хранить количество слов длиной 50 и более
    // Элементы с 1 по 49 будут хранить количество слов,
    // длины которых соответствуют индексу
    // 0 элемент не задействован, так как слов с нулевой длиной нет

    int wordLength = 0; // длина текущего слова

    // выбор региональной настройки для вывода на русском языке
    if (setlocale(LC_ALL, "ru_RU.UTF8") == 0)
    {
        // альтернативный способ, если не удалось первым
        if (setlocale(LC_ALL, ".UTF8") == 0)
        {

            // сбросим флаг, так как не удалось настроить на русский язык
            localeStatus = false;
            // используем настройки системы
            setlocale(LC_ALL, "");
        }
    }

    // Вывод инструкции пользователя на экран в зависимости от localeStatus
    // на русском или на латинице
    if (localeStatus)
    {
        printf("Программа анализа длин слов\n");
        printf("Вводите текст только на английском. Для завершения:\n");
        printf("1. Нажмите Ctrl + X\n");
        printf("2. Затем нажмите Enter\n");
        printf("Начните ввод >>>\n");
    }
    else
    {
        printf("Word length analysis program\n");
        printf("Input text (character by character). To exit:\n");
        printf("1. Press Ctrl + X\n");
        printf("2. Then press Enter\n");
        printf("Start input >>>\n");
    }

    // Получение и проверка символа с клавиатуры
    while((currentСhar = getchar()) != 24) {

        // проверка на завершение слова
        if( (currentСhar == ' ' || currentСhar == '\t' || currentСhar == '\n')
            && !(lastСhar == ' ' || lastСhar == '\t' || lastСhar == '\n') &&
            wordLength > 0)
        {   // проверка если длина в диапазоне до максимального значения
            if(wordLength < MAX_CHARS) 
            {
                // увеличиваем счётчик слов этой длины
                analysisTable[wordLength]++; 
            }
            else 
            {
                // увеличиваем счётчик слова максимальной длины или большей
                analysisTable[MAX_CHARS]++; 
            }
            wordLength = 0; // обнуляем счётчик для нового слова
        }
        else if(!(currentСhar == ' ' || 
                currentСhar == '\t' || currentСhar == '\n'))
        {
            wordLength++; // продолжаем увеличивать длину текущего слова
        }

        lastСhar = currentСhar;
    }

    // Обработка ошибок при вводе
    if(ferror(stdin)) {

        if(localeStatus)
        {
            perror("Ошибка ввода.");
        }
        else
        {
            perror("Input error.");
        }
        return 1; // Завершить программу
    }

    // Если последний символ не управляющий, надо учесть длину последнего слова
    //  и увеличить его счётчик
    if(
        !(lastСhar == ' ' || lastСhar == '\t' || lastСhar == '\n')
        && wordLength > 0)
    {

            if(wordLength < MAX_CHARS) 
            {
                analysisTable[wordLength]++; 
                // увеличиваем счётчик слов этой длины
            }
            else 
            {
                // увеличиваем счётчик слова максимальной длины или большей
                analysisTable[MAX_CHARS]++; 
            }
    }

    // Вывод результатов на экран в зависимости от localeStatus
    //  на русском или на английском
    if (localeStatus)
    {
        printf("   %s | %s\n", "Длина", "Слов");
    }
    else
    {
        printf("%8s | %s\n", "Length", "Words");
    }

    // Выбор способа, с помощью которого результаты будут
    // отображаться на экране (гистограмма или таблица)
    if (OUTPUT_TYPE)
    {
        printf("   _____________\n");
        for (int countCharacters = 1; 
            countCharacters <= MAX_CHARS; countCharacters++)
        {
            if (analysisTable[countCharacters] > 0 && 
                countCharacters < MAX_CHARS)
            {
                printf("%8d | ", countCharacters);

                for (int countWords = 0; 
                    countWords < analysisTable[countCharacters]; countWords++)
                {
                    putchar(HIST_CHAR);
                }
                putchar('\n');
            }
            else if (analysisTable[countCharacters] > 0 
                && countCharacters == MAX_CHARS)
            {
                printf("      %d+| ", MAX_CHARS);
                for (int countWords = 0; 
                    countWords < analysisTable[countCharacters]; countWords++)
                {
                    putchar(HIST_CHAR);
                }
                putchar('\n');
            }
        }
    }
    else
    {
     for (int countCharacters = 1; 
        countCharacters <= MAX_CHARS; countCharacters++)
     {
        if (analysisTable[countCharacters] > 0 && 
            countCharacters < MAX_CHARS)
        {
         printf("%8d | %d\n", countCharacters, analysisTable[countCharacters]);
        }
        else if (analysisTable[countCharacters] > 0 && 
            countCharacters == MAX_CHARS)
        {
         printf("      %d+| %d\n", MAX_CHARS, analysisTable[countCharacters]);
        }
     }
    }

    return 0;
}
