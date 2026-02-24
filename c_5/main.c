#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/*
 *  Рефакторинг кода программы c_4/main_2.c
 *  Посимвольный ввод с клавиатуры.
 *  Окончание ввода  - Ctrl X
 *  Сообщения в терминале на кириллице согласно заданию в readme.md
 */

 int main(void) {

    bool locale_status = true; // флаг локали по умолчанию true

    int c;

    long total_chars = 0; // счётчик символов

    // Пытаемся переключить русскую локаль UTF-8 
    if(setlocale(LC_ALL, "ru_RU.UTF8") == NULL) {
        // пробуем альтернативный вариант
        if(setlocale(LC_ALL, ".UTF8") == NULL) {
            locale_status = false; // не получилось - сброс флага локали
            setlocale(LC_ALL,""); // использовать системную локаль
        }
    }

    if(locale_status) {
        // если удалось установить русскую локаль UTF-8
        // выводим инструкцию пользователя на кириллице
        printf("Для завершения ввода:\n");
        printf("1. Нажать комбинацию Ctrl + X\n");
        printf("2. Нажать клавишу Enter\n");
        printf("Начните ввод текста >>>");
    } else {
        // вывод инструкции пользователя на латинице
        // (английский язык или транслит)
        printf("To exit:\n");
        printf("1. Press Ctrl + X\n");
        printf("2. Press Enter\n");
        printf("Input text now >>>");
    }

    // считываем символы пока не встретится Ctrl-x
    while( (c = getchar()) != 24) {
        total_chars++; // увеличиваем счетчик символов, учёт всех кроме Ctrl-x
    }
    

        if(locale_status) {
            // вывод таблицы на кириллице
            printf("\n%s\t\t%s\n", "СЧЁТЧИК", "ИТОГО");
            printf("\n%s\t%ld", "СИМВОЛОВ", total_chars);
        } else {
            // вывод таблицы на латинице (английский язык или транслит)
            printf("\n%s\t\t%s\n", "COUNTER", "TOTAL");
            printf("\n%s\t\t%ld", "CHARS", total_chars);
        }

    return 0;
 }