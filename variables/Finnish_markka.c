#include <stdio.h>
int main()
{
    float cvrt_factor, markka_factor, euro_factor;

    printf("Enter an amount in FIM: ");
    scanf("%f", &markka_factor);

    cvrt_factor = 5.94573;
    euro_factor = markka_factor / cvrt_factor;
    printf("FIM converted to euro: %.2f\n", euro_factor);

    return 0;



}


