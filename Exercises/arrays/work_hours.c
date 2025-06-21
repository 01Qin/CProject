#include <stdio.h>

int enter_days; 
float enter_1h, enter_2h, enter_3h;

int main()
{
    printf("The program calculates the total hours worked during\na specific period and the average length of a day.");
    printf("How many days:");
    scanf("%d", &enter_days);

    printf("Enter the working hours for day 1:");
    scanf("%d", &enter_1h);
    printf("Enter the working hours for day 2:");
    scanf("%d", &enter_2h);
    printf("Enter the working hours for day 3:");
    scanf("%d", &enter_3h);

}