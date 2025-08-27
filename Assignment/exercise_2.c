//
// Created by Quinn on 22.8.2025.
//
#include <stdio.h>
int main() {
    float tax_rate, income_limit, over_limit;
    float month_salary[12],month_tax[12];
    int index;
    printf("Enter tax rate: ");
    scanf("%f", &tax_rate);
    printf("Enter income limit: ");
    scanf("%f", &income_limit);
    printf("Enter tax rate for incom over the limit: ");
    scanf("%f", &over_limit);
    over_limit = tax_rate / income_limit;

    for (index = 0; index < 12; index++) {
        printf("Enter income for month %d: ", index + 1);
        scanf("%f", &month_salary[index]);

        if (month_salary[index] <=income_limit) {
            month_tax[index] = tax_rate / 100 * month_salary[index];
        }
        else {
            month_tax[index] = tax_rate / 100 * income_limit + over_limit / 100 * (month_salary[index] - income_limit);
        }
    }
    printf("\nmonth  income    tax\n");
    for (index = 0; index < 12; index++) {
        printf("%-7d%-10.2f%.2f\n", index + 1, month_salary[index], month_tax[index]);
    }
    return 0;
}
