#include <stdio.h> 
       int main()
       {  
         FILE *opening; 
         char *file_name = "filename.txt";
         char *opening_mode= "w"; 

         opening = fopen(file_name, opening_mode); 

        if(opening == NULL){ 
           printf("An error occurred when opening the file!"); 
           exit(1); 
        }  
        else {
          fprintf(opening, "Joe"); 
          fclose(opening);
        } 
       return 0;
      }