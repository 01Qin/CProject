#include <stdio.h>
int main()
{
    int numbers[100], index;

    for (index = 0; index < 100; index++)
    {
        printf("Enter the %d. number: ", index+1);
        scanf("%d", &numbers[index]);
    }

    printf("The numbers in reversed order: ");

    for (index = 99; index >0; index--)
    {
        printf("%d", numbers[index]);
    }

}


