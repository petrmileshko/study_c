#include <stdio.h>
#include <stdbool.h>

/*
 * Программа подсчёта символов, строк и слов.
 * Ввод с клавиатуры.
 * Вывод результата в терминал.
 * Окончание ввода на новой строке — комбинацией клавиш Ctrl + Z и потом Enter.
 */

int main(void) {
    long number_of_chars = 0,
         number_of_lines = 0,
         number_of_words = 0;

    int c;
    bool new_word = false; // флаг нового слова
    bool new_line = false; // флаг, указывающий, что последняя строка не завершена \n

    while (1) { // Бесконечный цикл, выход будет по EOF
        c = getchar();

        // Проверка на конец ввода — если EOF, выходим из цикла
        if (c == EOF) {
            break;
        }

        number_of_chars++; // увеличить счётчик символов (только для реальных символов)

        switch (c) {
            case ' ':
            case '\t':  // символы пробела и табуляции разделяют слова
                if (new_word)
                    number_of_words++; // увеличить счётчик слов, если флаг истина
                new_word = false; // сбросить флаг слова
                break;
            case '\n': // перевод/конец строки
                number_of_lines++;  // увеличить счётчик строк
                if (new_word)
                    number_of_words++;
                new_word = false;
                new_line = true; // отметить, что строка завершена \n
                break;
            default:
                new_word = true;
                new_line = false; // строка ещё не завершена \n
                break;
        }
    }

    // Обработать случай, если последнее слово не закончилось разделителем
    if (new_word) {
        number_of_words++;
    }

    // Учесть последнюю строку, если она не закончилась на \n
    if (!new_line && number_of_chars > 0) {
        number_of_lines++;
    }

    // Обработать ошибку ввода
    if (ferror(stdin)) {
        perror("Input Error");
        return 1;
    }

    // Форматируем и выводим на экран таблицу
    printf("%8s\t%-8s\n", "COUNTER", "TOTAL");
    printf("%8s\t%-8ld\n", "LINES", number_of_lines);
    printf("%8s\t%-8ld\n", "WORDS", number_of_words);
    printf("%8s\t%-8ld\n", "CHARS", number_of_chars);

    return 0;
}
