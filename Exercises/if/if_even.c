#include <stdio.h>

int main(){
    int enter_num;

    printf("Enter an integer: ");
    scanf("%d", &enter_num);

    if (enter_num % 2 == 0)
        printf("Number %d is even.", enter_num);
    else
        printf("Number %d is odd.", enter_num);

    return 0;

}

