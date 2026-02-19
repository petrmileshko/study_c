#include <stdio.h>

/*  Программа подсчёта символов и строк входного потока
 *  ввод с клавиатуры
 *  вывод результата в терминал
 */

int main(void)
{
    long nc = 0, nl = 0;
    int c = 0, last_char = 0;

    while ((c = getchar()) != EOF)
    {
        last_char = c;

        if (c == '\n')
        {
            nl++;
            // printf("Endline '\\n' → nl = %ld\n", nl);
        }

        // не учитываем символы перевода строки и Ctrl Z
        if (c != '\n' && c != 26)
        {
            nc++;
            // printf("Char '%c' counted → nc = %ld\n", c, nc);
        }
    }

    // необходимо учесть строку даже если она не заканчивается '\n'
    if (last_char != '\n' && nc > 0)
    {
        ++nl;
        printf("Last line without '\\n' → nl = %ld\n", nl);
    }

    if (ferror(stdin))
    {
        perror("Input Error");
        return 1;
    }

    printf("\nNumber of chars = %ld", nc);
    printf("\nNumber of lines = %ld", nl);

    return 0;
}
