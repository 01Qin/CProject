#include <stdio.h>
 int main()
 {
    int enter_num, count = 0;
    float average_num, sum = 0.0;
    printf("The program calculates the average of scores you enter.\n");
    printf("End with a negative integer.\n");

    do
    {
        printf("Enter score (4-10):");
        scanf("%d", &enter_num);

		if (enter_num >= 4 && enter_num <=10){
            sum += enter_num;
            count ++;
        }
			 
    } while (enter_num >= 0);

	 if (count > 0)
        printf("You entered %d scores.\n", count);
		average_num = sum / count;
	    printf("Average score: %.2f", average_num);
    return 0;
    
 }