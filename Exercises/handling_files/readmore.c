#include <stdio.h>

int main()
{
    FILE *file_handle;
    float number1, number2, number3, number4;
    if ((file_handle = fopen("data.txt","r")) == NULL){
        printf("FIle not found!"); return 0;
    } else {
        fscanf(file_handle, "%f %f %f %f", &number1, &number2, &number3, &number4);
        fclose(file_handle);

        printf("The numbers %f, %f, %f and %f were found in the file", number1, number2, number3, number4);
    }
    return 0;
}