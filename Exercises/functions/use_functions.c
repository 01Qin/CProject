#include <stdio.h>
int first_int, second_int, third_int, largest_num, smallest_num;
void largest(void);
void smallest(void);

int main()
{
    printf("Enter the 1. number:");
    scanf("%d", &first_int);

    printf("Enter the 2. number:");
    scanf("%d", &second_int);

    printf("Enter the 3. number:");
    scanf("%d", &third_int);
    largest();
    smallest();

    
    printf("Among the numbers you entered,\nthe largest was %d and the smallest was %d.", largest_num, smallest_num);
    
    return 0;
}

void largest(void)
{
    // initialise largest_num with the first integer.
    largest_num = first_int;

    if (second_int > largest_num){
        largest_num = second_int;
    }

    if(third_int > largest_num){
        largest_num = third_int;
    }  
    }

void smallest(void)
{
    smallest_num = first_int;

    if (second_int < smallest_num){
        smallest_num = second_int;
    }

    if (third_int < smallest_num){
        smallest_num = third_int;
    }

    }
