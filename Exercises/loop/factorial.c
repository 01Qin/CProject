#include <stdio.h>

int main()
{
    int enter_num;
    long long factorial_num = 1;
    int i = 1;

    printf ("Enter an integer: ");
    scanf("%d", &enter_num);

    do
    {
        factorial_num *= i;
        i++;
    } while (i <= enter_num );

        printf("The factorial of %d is %lld", enter_num, factorial_num);

    return 0;

}