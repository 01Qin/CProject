#include <stdio.h>

int main()
{
    FILE *file_handle;
    float number_read;

    if ((file_handle = fopen("data.txt", "r"))== NULL){
        printf("File not found!"); return 0;
    } else {
        fscanf(file_handle, "%f", &number_read);
        fclose(file_handle);

        printf("The number %f was found in the file", number_read);
    }
    return 0;
}