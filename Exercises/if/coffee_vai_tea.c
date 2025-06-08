#include <stdio.h>

int main()
{
    int cups; char choice;

    printf("Do you drink coffee or tea (c/t)? ");
    choice = getchar();

    while (getchar() != '\n');

    if (choice == 'c'){
        printf("How many cups do you drink daily: ");
        scanf("%d", &cups);

        if (cups >= 0 && cups <= 2){
            printf("You don't drink a lot of coffee, do you?");
        } else if (cups >= 3 && cups <= 20){
            printf("You drink a lot of coffee!\n");
        } else {
            printf("Error!");
        }
    }
    else if (choice == 't'){
        printf("How many cups do you drink daily: ");
        scanf("%d", &cups);

        if (cups >= 0 && cups <= 2) {
            printf("You do not drink a lot of tea.");
        } else if (cups >= 3 && cups <= 20){
            printf("You drink a lot of tea!");
        } else {
            printf("Error!");
        }
    }
    else {
        printf("An error occurred in the program!");
    }
    return 0;
}