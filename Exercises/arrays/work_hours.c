#include <stdio.h>

#define max_days 30


int main()
{
    int enter_days, i; 
    float daily_hs[max_days], total_hs = 0.0, avarage_hs;
    printf("The program calculates the total hours worked during\na specific period and the average length of a day.\n");
    
    do {
        printf("How many days (max %d): ", max_days);
        scanf("%d", &enter_days);
    

    } while (enter_days <= 0);
    printf("\n");
       
    for (i = 0; i < enter_days; i++){
        printf("Enter the working hours for day %d:", i + 1);
        scanf("%f", &daily_hs[i]);  

        while (daily_hs[i] < 0)
    {
        printf("Enter a positive number or 0 %d: ", i + 1);
        scanf("%f", &daily_hs[i]);
    }
    total_hs += daily_hs[i];
    }
    if (enter_days > 0){
        avarage_hs = total_hs / enter_days;
    } else {
        avarage_hs = 0.0;
    }

    printf("Total hours worked: %.1f\n", total_hs);
    printf("Average length of day: %.1f\n", avarage_hs);
    
    printf("Hours entered: ");
    for (i = 0; i < enter_days; i++){
        printf("%.1f", daily_hs[i]);
        }
    
    return 0;

}


