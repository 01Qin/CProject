#include <stdio.h>
int main()
{
    int enter_num;
    float floating_pointer_num;
    printf("Enter an integer: ");
    scanf("%d", &enter_num);

    printf("Enter a decimal number: ");
    scanf("%f", &floating_pointer_num);

    printf("You entered the integer: %d", enter_num);
    printf("You entered the decimal number, rounded to two decimal places: %.2f", floating_pointer_num);
    
    return 0;

}