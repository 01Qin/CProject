#include <stdio.h>
int main()
{
    int pressed_num, first_num, second_num, result_num;
    printf("1: subtraction\n2: addition\n3: multiplication\n"
    );
    printf("Select function:");
    scanf("%d", &pressed_num);

    switch (pressed_num)
    {
    case 1:
        
        printf("Enter the first number: ");
        scanf("%d", &first_num);
        printf("Enter the second number: ");
        scanf("%d", &second_num);
        result_num = first_num - second_num;
        printf("%d - %d = %d", first_num, second_num, result_num);
        break;
    
    case 2:
 
        printf("Enter the first number: ");
        scanf("%d", &first_num);
        printf("Enter the second number: ");
        scanf("%d", &second_num);
        result_num = first_num + second_num;
        printf("%d + %d = %d", first_num, second_num, result_num);
        break;

    case 3:

        printf("Enter the first number: ");
        scanf("%d", &first_num);
        printf("Enter the second number: ");
        scanf("%d", &second_num);
        result_num = first_num * second_num;
        printf("%d * %d = %d", first_num, second_num, result_num);
        break;

    default:
        printf("your input is outside the allowed range.");
        break;
    }
    return 0;
}