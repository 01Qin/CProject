#include <stdio.h>

int main()
{
    int sum=0, num1=0, num2=0, num3=0, num4=0;
    FILE *file_read;

    if ((file_read = fopen("numbers.s", "r")) == NULL){
        printf("File not found."); return 1;
    } else {
        fscanf(file_read, "%d %d %d %d", &num1, &num2, &num3, &num4);
        fclose(file_read);

        printf("Numbers found in the file 'numbers.s':\n");
        printf("%d, %d, %d and %d\n\n", num1, num2, num3, num4);
        
        sum = num1 + num2 + num3 + num4;
        printf("Sum of the numbers: %d", sum);

    }
    return 0;
}
