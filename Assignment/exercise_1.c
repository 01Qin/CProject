//
// Created by Quinn on 19.8.2025.
//
#include <stdio.h>


int main() {
    float bus_price=0, taxi_price=0, money=0;
    int selection;

    printf("Enter price of bus ticket: ");
    scanf("%f", &bus_price);

    printf("Enter price of taxi ticket: ");
    scanf("%f", &taxi_price);

    printf("How much money do you have: ");
    scanf("%f", &money);

    if (money < bus_price && money < taxi_price) {
        printf("You need to walk, bye!\n");
        return 0;
    }

    while (money >= bus_price || money >= taxi_price) {
    printf("\nDo you want to take:\n 1. Bus (%.2f euros)\n 2. Taxi (%.2f euros)\n", bus_price, taxi_price);

    printf("Enter your selection: ");
    scanf("%d", &selection);


    switch (selection) {
        case 1: {
            if (money >= bus_price) {
                money -= bus_price;
                printf("You chose: %d\n", selection);
                printf("You have %.2f euros left.\n", money);
            } else {
                printf("You don’t have enough money for the bus.\n");
            }
            break;

        }
        case 2: {
            if (money >= taxi_price) {
                money -= taxi_price;
                printf("You chose: %d\n", selection);
                printf("You have %.2f euros left.\n", money);
            }
            else {
                printf("You don't have enough money for the taxi.\n");
            }
            break;
        }
        default:
            printf("Invalid selection, please chose 1 or 2.\n");
    }
        if (money < bus_price && money < taxi_price) {
            printf("You need to walk, bye!");
            break;
        }
    }
return 0;
}