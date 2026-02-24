#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/*
 *  Рефакторинг кода программы c_4/main_2.c
 *  Посимвольный ввод с клавиатуры.
 *  Окончание ввода  - Ctrl X
 *  Сообщения в терминале на кириллице согласно заданию в readme.md
 */

int main(void)
{

    bool locale_status = true; // флаг локали по умолчанию true

    int c,             // текущий введённый пользователем символ с клавиатуры
        last_c = '\n'; // последний введённый символ с клавиатуры

    long total_chars = 0, // счётчик символов
        total_lines = 0,  // счётчик строк
        total_words = 0;  // счётчик слов

    // Пытаемся переключить русскую локаль UTF-8
    if (setlocale(LC_ALL, "ru_RU.UTF8") == NULL)
    {
        // Пробуем альтернативный вариант
        if (setlocale(LC_ALL, ".UTF8") == NULL)
        {
            locale_status = false; // Не получилось - сброс флага локали
            setlocale(LC_ALL, ""); // Использовать системную локаль
        }
    }

    if (locale_status)
    {
        // Если удалось установить русскую локаль UTF-8
        // выводим инструкцию пользователя на кириллице
        printf("Для завершения ввода:\n");
        printf("1. Нажать комбинацию Ctrl + X\n");
        printf("2. Нажать клавишу Enter\n");
        printf("Начните ввод текста >>>");
    }
    else
    {
        // вывод инструкции пользователя на латинице
        // (английский язык или транслит)
        printf("To exit:\n");
        printf("1. Press Ctrl + X\n");
        printf("2. Press Enter\n");
        printf("Input text now >>>");
    }

    // Считываем нажатые символы на клавиатуре.
    // Выход из цикла при нажатии Ctrl-X (код 24)
    while ((c = getchar()) != 24)
    {
        total_chars++; // увеличиваем счетчик символов, учёт всех кроме Ctrl-x

        if (c == '\n')
        {
            // завершаем строку
            total_lines++;
        }

        if ((c == ' ' || c == '\t' || c == '\n') &&
            !(last_c == ' ' || last_c == '\t' || last_c == '\n'))
        {
            // Завершаем слово при условии,
            // что перед этим не было символа, указанного в условии
            total_words++;
        }

        last_c = c; // Запомнить последний символ
    }

    // Учёт последнего незавершённого слова
    if (!(last_c == ' ' || last_c == '\t' || last_c == '\n') && total_chars > 0)
    {
        total_words++;
    }

    // Учёт последней незавершённой строки
    if (last_c != '\n' && total_chars > 0)
    {
        total_lines++;
    }

    // Обработать если ошибка при вводе
    if (ferror(stdin))
    {
        if (locale_status)
        {
            perror("Ошибка ввода.");
        }
        else
        {
            perror("Input error.");
        }
        return 1; // Завершить программу
    }

    if (locale_status)
    {
        // Вывод таблицы на кириллице
        printf("\n%s\t\t%s\n", "СЧЁТЧИК", "ИТОГО");
        printf("\n%s\t%ld", "СИМВОЛОВ", total_chars);
        printf("\n%s\t\t%ld", "СТРОК", total_lines);
        printf("\n%s\t\t%ld", "СЛОВ", total_words);
    }
    else
    {
        // Вывод таблицы на латинице (английский язык или транслит)
        printf("\n%s\t\t%s\n", "COUNTER", "TOTAL");
        printf("\n%s\t\t%ld", "CHARS", total_chars);
        printf("\n%s\t\t%ld", "LINES", total_lines);
        printf("\n%s\t\t%ld", "WORDS", total_words);
    }

    return 0;
}
