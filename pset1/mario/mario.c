#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int d, i, h;
    do
    {
        h = get_int("What do you want the height of the pyramid?\n");
    }
    while (h < 1 || h > 8);
    
    for (i = 0; i < h; i++)
    {
        for (d = h - i - 1; d > 0; d--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
        
    }
}