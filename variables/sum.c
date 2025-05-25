#include <stdio.h>

/* This is a fine program with comments*/
int main()
{
    int first_number, second_number, sum;

    printf("Enter a number: ");
    scanf("%d", &first_number);

    printf("Enter another number: ");
    scanf("%d", &second_number);

    sum = first_number + second_number;

    printf("The sum of the numbers you entered is %d", sum);

    return 0;
}