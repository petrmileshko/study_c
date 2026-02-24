#include <stdio.h>

/*
 *  Программа подсчёта символов, cтрок и слов.
 *  Ввод с клавиатуры.
 *  Вывод результата в терминал.
 *  Окончание ввода на новой строке  -
 *  комбинацией клавиш - Ctrl + Z и потом Enter
 */


 int main(void) {

    long number_of_chars = 0,
        number_of_lines = 0,
        number_of_words = 0;

    int c;

        while((c = getchar() ) != EOF) {
            number_of_chars++; // увеличить счётчик символов

            switch(c) {
                case ' ':
                case '\t':  // символы пробела и табуляция разделяют слова
                    number_of_words++; //  увеличить счётчик слов
                break;
                case '\n': // перевод/конец строки 
                    number_of_lines++;  //  увеличить счётчик строк
                    number_of_words++; //  увеличить счётчик слов
                break;
                default:
                break;
            }

        }

        // Форматируем и выводим на экран таблицу
        printf("\n%8s\t%-8s\n", "COUNTER","TOTAL");
        printf("\n%8s\t%-8ld","LINES", number_of_lines);
        printf("\n%8s\t%-8ld","WORDS", number_of_words);
        printf("\n%8s\t%-8ld\n","CHARS", number_of_chars);

    return 0;
 }