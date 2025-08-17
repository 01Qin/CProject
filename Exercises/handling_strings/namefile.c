#include <stdio.h>
#include <string.h>

int main()
{
    char firstname[15+1], lastname[20+1], full_filename[256];
    
    FILE *output_file;

    printf("The program saves your first and last name into a file.\n");

    printf("Enter your first name:");
    scanf("%15s", firstname);

    printf("Enter your last name:");
    scanf("%20s", lastname);


    printf("File where you want to save your name:");
    scanf("%255s", full_filename);
    

    output_file = fopen(full_filename, "w");
    if (output_file == NULL)
    {
        printf("An error occurred when opening the file!");
        return 1;
    } 

    fprintf(output_file, "%s\n", lastname);
    fclose(output_file);

    printf("Successfully saved the data!\n");

    return 0;
}