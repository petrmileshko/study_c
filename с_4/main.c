#include <stdio.h>

/* Программа
 *
 *
 */

int main(void)
{
    double nc = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            nc++;
        }
    }

    printf("%.0f", nc);
    return 0;
}
