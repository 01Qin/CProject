#include <stdio.h>
int main()
{
    int enter_num;
    printf("Enter an integer: ");
    scanf("%d", &enter_num);

    if (enter_num % 2 == 0)
    printf("The number is 0.");
    else
    printf("The number is 1.");

    return 0;
}