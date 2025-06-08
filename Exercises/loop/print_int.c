#include <stdio.h>

int main()
{
    int i, enter_num;
    printf("Enter an integer: ");
    scanf("%d\n", &enter_num);

    for (i = 1; i <= enter_num; i++)
    {
        printf("%d", i);   
    }
    return 0;
}