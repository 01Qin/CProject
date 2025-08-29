//
// Created by Quinn on 28.8.2025.
//
#include <stdio.h>
#define array_size 12

int main() {
    float tax_rate = 0.0, income_limit = 0.0, over_limit = 0.0;
    float month_salary[array_size], month_tax[array_size];
    int index;

    printf("Enter tax rate: ");
    scanf("%f", &tax_rate);
    printf("Enter income limit: ");
    scanf("%f", &income_limit);
    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &over_limit);
    over_limit = tax_rate / income_limit;

    for (index = 0; index < array_size; index++) {
        printf("Enter income for month %d: ", index + 1);
        scanf("%f", &month_salary[index]);

        if (month_salary[index] <= income_limit) {
            month_tax[index] = tax_rate / 100 * month_salary[index];
        } else {
            month_tax[index] = tax_rate / 100 * income_limit + over_limit / 100 * (month_salary[index] - income_limit);
        }
    }
    printf("\nmonth  income    tax\n");
    for (index = 0; index < array_size; index++) {
        printf("%-7d%-10.2f%.2f\n", index + 1, month_salary[index], month_tax[index]);
    }
    return 0;
}
