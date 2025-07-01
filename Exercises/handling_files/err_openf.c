#include <stdio.h> 
int main()
{  
    FILE *opening; 
    opening = fopen("filename.txt", "w"); 
    
    // always account for error conditions
    if(opening == NULL){ 
        printf("An error occurred when opening the file!"); 
        return 0;
    }  
    else {
        printf(opening, "Joe"); 
        fclose(opening);
    }
    return 0;
}