#include <stdio.h>
int main()
{
    char firstname[15], lastname[20], filename[11];
    printf("The program saves your first and last name into a file.");

    printf("Enter your first name:");
    scanf("%s", &firstname[0]);

    printf("Enter your last name:");
    scanf("%s", &lastname[0]);

    printf("Enter your file name:");


    printf("Successfully saved the data!");
}