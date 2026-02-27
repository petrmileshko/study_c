#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/*
 *  Программа анализа длин слов во входном потоке
 *  Посимвольный ввод с клавиатуры.
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
    bool locale_status = true;

    // текущий и послений символы
    int c,
        last_char = '\n';

    int analysis_table[MAX_CHARS + 1] = {0};
    // 50 элемент массива будет хранить количество слов длиной 50 и более
    // Элементы с 1 по 49 будут хранить количество слов,
    // длины которых соответствуют индексу
    // 0 элемент не задействован, так как слов с нулевой длиной нет

    int word_length = 0; // длина текущего слова

    // выбор региональной настройки для вывода на русском языке
    if (setlocale(LC_ALL, "ru_RU.UTF8") == 0)
    {
        // альтернативный способ, если не удалось первым
        if (setlocale(LC_ALL, ".UTF8") == 0)
        {

            // сбросим флаг, так как не удалось настроить на русский язык
            locale_status = false;
            // используем настройки системы
            setlocale(LC_ALL, "");
        }
    }

    // Вывод инструкции пользователя на экран в зависимости от locale_status
    // на русском или на латинице
    if (locale_status)
    {
        printf("Программа анализа длин слов\n");
        printf("Вводите текст (посимвольно). Для завершения:\n");
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

    /*
    //Код для тестирования вывода из массива с искусственными (моковыми) данными

    analysis_table[4] = 14;
    analysis_table[5] = 12;
    analysis_table[1] = 3;
    analysis_table[MAX_CHARS] = 5;
    */

    // Получение и проверка символа с клавиатуры
    while((c = getchar()) != 24) {

        // проверка на завершение слова
        if( (c == ' ' || c == '\t' || c == '\n') &&
            !(last_char == ' ' || last_char == '\t' || last_char == '\n') &&
            word_length > 0)
        {
            analysis_table[word_length]++; // увеличиваем счётчик слов этой длины
            word_length = 0; // обнуляем для нового слова
        }
        else
        {
            word_length++; // продолжаем увеличивать длину текущего слова
        }

        last_char = c;
    }

    // Обработка ошибок при вводе
    if(ferror(stdin)) {

        if(locale_status)
        {
            perror("Ошибка ввода.");
        }
        else
        {
            perror("Input error.");
        }
        return 1; // Завершить программу
    }

    // Если последний символ не управляющий, надо учесть длину слова
    if( !(last_char == ' ' || last_char == '\t' || last_char == '\n') && word_length > 0) {
        analysis_table[word_length]++;
    }

    // Вывод результатов на экран в зависимости от locale_status
    //  на русском или на английском
    if (locale_status)
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
        for (int i = 1; i <= MAX_CHARS; i++)
        {
            if (analysis_table[i] > 0 && i < MAX_CHARS)
            {
                printf("%8d | ", i);

                for (int j = 0; j < analysis_table[i]; j++)
                {
                    putchar(HIST_CHAR);
                }
                putchar('\n');
            }
            else if (analysis_table[i] > 0 && i == MAX_CHARS)
            {
                printf("      %d+| ", MAX_CHARS);
                for (int j = 0; j < analysis_table[i]; j++)
                {
                    putchar(HIST_CHAR);
                }
                putchar('\n');
            }
        }
    }
    else
    {
        for (int i = 1; i <= MAX_CHARS; i++)
        {
            if (analysis_table[i] > 0 && i < MAX_CHARS)
            {
                printf("%8d | %d\n", i, analysis_table[i]);
            }
            else if (analysis_table[i] > 0 && i == MAX_CHARS)
            {
                printf("      %d+| %d\n", MAX_CHARS, analysis_table[i]);
            }
        }
    }

    return 0;
}
