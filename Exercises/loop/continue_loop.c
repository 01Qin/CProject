#include <stdio.h>

int main()
{
    int i, even_or_odd;

    for (i = 1; i < 11; i++)
    {
        even_or_odd = i % 2;
        if (even_or_odd != 0)
        {
            continue;
            
        }
        else
        {
            printf("%d\n", i);
            
        }
        return 0;
    }
}