#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("The current value of i is %d", i);
        i--;
    }
    return 0;
}