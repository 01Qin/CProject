#include <stdio.h>
int main()
{
    int first_num, second_num, sum, subtract, multiply;

    printf("Enter the first number: ");
    scanf("%d", &first_num);

    printf("Enter the second number: ");
    scanf("%d", &second_num);

    sum = first_num + second_num;
    subtract = first_num - second_num;
    multiply = first_num * second_num;
    
    printf("%d + %d = %d\n", first_num, second_num, sum);
    printf("%d - %d = %d\n", first_num, second_num, subtract);
    printf("%d * %d = %d\n", first_num, second_num, multiply);

    return 0;


}