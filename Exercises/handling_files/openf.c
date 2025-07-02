#include <stdio.h> 
int main()
{
    // *opening declares a file handle for the opened file. 
    // "w" - write mode; "a" - opened for appending; "r+", "w+" - opened for reading and writing;
    // "a+" - opened for reading and appending
    // "wb" - open a file in binary mode
    FILE *opening = fopen("filename.txt", "w");
        //fprintf function is almost similar to the printf function, the only difference is that
        // fprintf receives the name of a file handle as its argument.
        fprintf(opening, "Joe");
        // close any open files after using them.
        fclose(opening);
    return 0;
}