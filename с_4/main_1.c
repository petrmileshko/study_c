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
    long number_of_spaces = 0, number_of_tab = 0, number_of_enter = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        // оператор множественного выбора выполняет блок кода, условие которого
        // совпадает со значением сравниваемого выражения в скобках switch()
        // до оператора break
        switch (c)
        {
        case '\n': // условие - конец строки Enter
            number_of_enter++;  // блок кода
            break; // до оператора break
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

    return 0;
}
