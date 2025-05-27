#include <stdio.h>

int main()
{
    char coffee; /* initialise the only variable */
    printf("Do you drink coffee? (y / n): ");
    coffee = getchar(); /* waits until the user enters something on the keyboard */
/* could equally well have used the function scanf(), ("%c", &coffee) */

    if ((coffee == 'y') || (coffee == 'Y'))
        printf("You're a coffee drinker!");
    else if ((coffee == 'n') || (coffee == 'N'))
        printf("You don't drink coffee.");
    else
        printf("Please give me a proper answer!");
    return 0;

}