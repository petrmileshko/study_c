#include <stdio.h>

/*
 *  Программа подсчёта символов - пробелы, табуляция, конец строки.
 *  Ввод с клавиатуры.
 *  Вывод результата в терминал.
 *  Окончание ввода на новой строке  -
 *  комбинацией клавиш - Ctrl + Z и потом Enter (EOF)
 */

int main(void)
{
    long number_of_spaces = 0, // символ пробела
        number_of_tab = 0,     // символы табуляции
        number_of_eol = 0;     // eol - конец строки (end of lines)

    int c;

    while ((c = getchar()) != EOF)
    {
        // оператор множественного выбора выполняет блок кода, условие которого
        // совпадает со значением сравниваемого выражения в скобках switch()
        // до оператора break
        switch (c)
        {
        case '\n':           // условие - конец строки
            number_of_eol++; // блок кода до оператора break
            break;
        case '\t': // условие - табуляция Tab
            number_of_tab++;
            break;
        case ' ': // условие - пробел Space
            number_of_spaces++;
            break;
        default:
            break;
        }
    }

    // обработаем если возникла ошибка при вводе
    if (ferror(stdin))
    {
        perror("Input Error");
        return 1;
    }

    printf("\n%-8s%8s\n", "SYMBOL", "TOTAL");
    printf("\n%-8s%8ld", "EOL", number_of_eol);
    printf("\n%-8s%8ld", "TAB", number_of_tab);
    printf("\n%-8s%8ld\n", "SPACE", number_of_spaces);
    /**
     *  форматирование вывода - %-8s%8ld означает:
     *  %-8s минимум 8 символов, выравнять по левому краю, тип данных string
     *  %8ld минимум 8 символов, выравнять по правому краю, тип данных long
     */

    return 0;
}
