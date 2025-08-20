//
// Created by Quinn on 19.8.2025.
//
#include <stdio.h>
float bus_price=0, taxi_price=0, money=0;
int selection=0;

int main() {
    printf("Enter price of bus ticket: ");
    scanf("%f", &bus_price);

    printf("Enter price of taxi ticket: ");
    scanf("%f", &taxi_price);

    printf("How much money do you have: ");
    scanf("%f", &taxi_price);

    printf("Do you want to take\n 1. bus (3.50 euros)\n 2. taxi (25.70 euros)\n");

    printf("Enter your selection: ");
    scanf("%d", &selection);


    switch (selection) {
        case 1: {
            printf("Your chose: %d\n", selection);
            printf("You have %f euros left.", money - bus_price);
            break;
        }
        case 2: {
            printf("Your chose: %d", selection);
            printf("You have %f euros left", money - taxi_price);
        }
            default:
            printf("You need to walk, bye!");
    }
    return 0;
}