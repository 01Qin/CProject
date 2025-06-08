#include <stdio.h>

// must be very careful about the syntax, i've been debugging for an hour, 
// and didn't expect it to be a syntax problem.

int first_num, second_num, sum1, difference, product1;
void sum(void);
void diff(void);
void product(void);


int main()
{
    int choice; 
    do{

        printf("1: sum of two numbers\n2: difference of two numbers\n");
        printf("3: product of two numbers\n<0: terminate the program");
        printf("Select calculation:");
        scanf("%d", &choice);

        if(choice < 0) {
            printf("Terminating the program...");
        }
        else if(choice == 1) {
            printf("Enter the first number:");
            scanf("%d", &first_num);
            printf("Enter the second number:");
            scanf("%d", &second_num);
            sum();
            printf("\n");
        }
        else if(choice == 2) {
            printf("Enter the first number:");
            scanf("%d", &first_num);
            printf("Enter the second number:");
            scanf("%d", &second_num);
            diff();
            printf("\n");
        }
        else if(choice == 3) {
            printf("Enter the first number:");
            scanf("%d", &first_num);
            printf("Enter the second number:");
            scanf("%d", &second_num);
            product();
            printf("\n");
        }
        else {
            printf("You entered an invalid number.\n\n");
        }
  }while(choice>0);

  return 0;
}


void sum(void)
{
    sum1 = first_num + second_num;
    printf("%d + %d = %d", first_num, second_num, sum1);
    
}
void diff(void)
   {
    difference = first_num - second_num;
    printf("%d - %d = %d", first_num, second_num, difference);
    }

void product(void)
{
    product1 = first_num * second_num;
    printf("%d * %d = %d", first_num, second_num, product1);
}
