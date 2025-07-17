#include <stdio.h>
int main()
{
    char firstname[15+1], lastname[20+1], filename_part1[8+1], filename_part2[3+1], full_filename[8+1+1+3+1];
    FILE *output_file;
    printf("The program saves your first and last name into a file.\n");

    printf("Enter your first name:");
    scanf("%15s", firstname);

    printf("Enter your last name:");
    scanf("%20s", lastname);

    printf("Enter the first part of your file name:\n");
    scanf("%8s", filename_part1);
    printf("Enter the second part of your file name:\n");
    scanf("%3s", filename_part2);


    printf("File where you want to save your name:\n\t");
    scanf("11%s",  full_filename);

    output_file = fopen(full_filename, "w");
    if (output_file == NULL)
    {
        printf("An error occurred when opening the file!");
        return 1;
    } 
    fprintf(output_file, "First Name: %s\n", firstname);
    fprintf(output_file, "Last Name: %s\n", lastname);
    fclose(output_file);

    printf("Successfully saved the data!");

    return 0;
}