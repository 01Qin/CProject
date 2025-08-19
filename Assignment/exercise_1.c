//
// Created by Quinn on 19.8.2025.
//
#include <stdio.h>
float bus_price, taxi_price, money;
int selection;
int main() {
    printf("Enter price of bus ticket: ");
    scanf("%f", &bus_price);

    printf("Enter price of taxi ticket: ");
    scanf("%f", &taxi_price);

    printf("How much money do you have: ");
    scanf("%f", &taxi_price);

    printf("You have %f euros left.", money);

    printf("Do you want to take\n, 1. bus (3.50 euros)\n,2. taxi (25.70 euros)");

    printf("Enter your selection: ");
    scanf("%d", &selection);
    printf("Your chose: %d", selection);
    if (selection == 1) {
        printf("You have %f euros left", money - bus_price);
    else
        {
            printf("You have %f euros left", money);
        }
    }
    return 0;
}