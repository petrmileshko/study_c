#include <stdio.h>
#include <stdbool.h>

/*
 *  Программа подсчёта символов, cтрок и слов.
 *  Ввод с клавиатуры.
 *  Вывод результата в терминал.
 *  Окончание ввода на новой строке  -
 *  комбинацией клавиш - Ctrl + Z и потом Enter (EOF)
 */


 int main(void) {

    long number_of_chars = 0,
        number_of_lines = 0,
        number_of_words = 0;

    int c;
    bool new_word = false; // флаг устанавливается в истину для каждого нового слова
    bool new_line = false; // флаг устанавливается  в истину для каждой новой строки

        while((c = getchar() ) != EOF) {
        
            // Игнорируем символ Ctrl+Z (код 26) при вводе с клавиатуры
            if (c == 26) { // 26 — код символа Ctrl+Z в Windows
                continue; // пропускаем этот символ, не увеличиваем счётчики
            }

            number_of_chars++; // увеличить счётчик символов

            switch(c) {
                case ' ':
                case '\t':  // символы пробела и табуляция разделяют слова
                    if(new_word) 
                        number_of_words++; //  увеличить счётчик слов если флаг истина
                    new_word = false; // установить флаги в ложное значение 
                    new_line = false;
                break;
                case '\n': // перевод/конец строки 
                    number_of_lines++;  //  увеличить счётчик строк
                    if(new_word) 
                        number_of_words++;
                    new_word = false; // после увеличения надо сбросить флаг в ложь
                    new_line = true; // после символа \n начинается отсчёт новой строки
                break;
                default:
                    new_word = true;
                    new_line = false;
                break;
            }

        }

        // Обработать случай, если последнее слово не закончилось разделителем
        if (new_word) {
            number_of_words++;
        }

        // Обработать случай, если последняя строка не заканчивается символов \n
        if (!new_line) {
            number_of_lines++;
        }

        // обработаем если возникла ошибка при вводе
        if (ferror(stdin))
        {
             perror("Input Error");
             return 1;
        }

        // Форматируем и выводим на экран таблицу
        printf("\n%8s\t%-8s\n", "COUNTER","TOTAL");
        printf("\n%8s\t%-8ld","LINES", number_of_lines);
        printf("\n%8s\t%-8ld","WORDS", number_of_words);
        printf("\n%8s\t%-8ld\n","CHARS", number_of_chars);

    return 0;
 }