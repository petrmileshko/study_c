#include <stdio.h>

/*
 *  Программа подсчёта символов и строк входного потока.
 *  Ввод с клавиатуры.
 *  Вывод результата в терминал.
 *  Окончание ввода -
 *  комбинацией клавиш - Ctrl + Z и потом Enter (EOF) обязательно на новой строке
 */

int main(void)
{
    long nc = 0, nl = 0;
    int c, last_char;

    while ((c = getchar()) != EOF)
    {

        if (c == '\n')
        {
            nl++;
        }

        // не учитываем символы перевода строки
        if (c != '\n')
        {
            nc++;
        }

        last_char = c; // запомним символ
    }

    // необходимо учесть строку даже если она не заканчивается '\n'
    if (last_char != '\n' && nc > 0)
    {
        ++nl;
    }

    // обработаем если возникла ошибка при вводе
    if (ferror(stdin))
    {
        perror("Input Error");
        return 1;
    }

    printf("\nNumber of chars = %ld", nc);
    printf("\nNumber of lines = %ld", nl);

    return 0;
}
