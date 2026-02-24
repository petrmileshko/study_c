#include <stdio.h>
#include <stdbool.h>

/*
 *  Программа подсчёта символов, cтрок и слов.
 *  Ввод с клавиатуры.
 *  Вывод результата в терминал.
 *  Окончание ввода на новой строке  -
 *  комбинацией клавиш - Ctrl + Z и потом Enter (EOF)
 */

int main(void)
{

    long number_of_chars = 0,
         number_of_lines = 0,
         number_of_words = 0;

    int c, last_char = '\n';
    bool new_word = false; // флаг устанавливается в истину для каждого нового слова

    while ((c = getchar()) != EOF)
    {

        // Игнорируем символ Ctrl+Z (код 26) при вводе с клавиатуры,
        //  когда комбинация нажата не на новой строке
        if (c == 26)
        {             // 26 — код символа Ctrl+Z в Windows
            continue; // пропускаем этот символ, не увеличиваем счётчики
        }

        number_of_chars++; // увеличить счётчик символов

        switch (c)
        {
        case ' ':
        case '\t':                 // символ пробела и табуляции завершают слово
            if (new_word)          // если флаг установлен надо
                number_of_words++; // увеличить счётчик слов
            new_word = false;      // слово завершено, сброс флага и ожидание ввода нового слова
            break;
        case '\n':             // конец строки
            number_of_lines++; // увеличить счётчик строк
            if (new_word)
                number_of_words++; // символ \n также завершает слово
            new_word = false;      // после сбросить флаг
            break;
        default:
            // в случае ввода любых других символов, начинаем новое слово и
            new_word = true; // устанавливаем флаг
            break;
        }

        last_char = c; // запомним последний символ
    }

    // Обработать случай, если последнее слово не закончилось разделителем
    if (new_word)
    {
        number_of_words++;
    }

    // Обработать случай, если последняя строка не заканчивается символом \n
    if (last_char != '\n' && number_of_chars > 0)
    {
        number_of_lines++; // в этом случае увеличить количество строк
    }

    // обработаем если возникла ошибка при вводе
    if (ferror(stdin))
    {
        perror("Input Error");
        return 1;
    }

    // Форматируем и выводим на экран таблицу
    printf("\n%8s\t%-8s\n", "COUNTER", "TOTAL");
    printf("\n%8s\t%-8ld", "LINES", number_of_lines);
    printf("\n%8s\t%-8ld", "WORDS", number_of_words);
    printf("\n%8s\t%-8ld\n", "CHARS", number_of_chars);

    return 0;
}
