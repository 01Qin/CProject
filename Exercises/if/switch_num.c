#include <stdio.h>

int main()
{
    int number_pressed;
    
    printf("Press a number key from 1 to 4: ");
    scanf("%d", &number_pressed);

    switch (number_pressed)
    {
    case 1:{
        printf("You pressed the number 1.");
        break;
    }
    case 2:{
        printf("You pressed the number 2.");
        break;
    }
    case 3:{
        printf("You pressed the number 3.");
        break;
    }
    case 4:{
        printf("You pressed the numner 4.");
        break;
    }
    default:
        printf("your input is outside the allowed range.");
    }
    return 0;
}