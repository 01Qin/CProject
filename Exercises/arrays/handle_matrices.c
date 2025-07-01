#include <stdio.h>

int main()
{
    int sum = 0, y, x;
    int matrix[5][5] =
    {
    4, 6, 25, 88, 5,
    34, 5, 300, 4, 65,
    78, 43, 11, 90, 125,
    98, 585, 12, 63, 21,
    45, 35, 9, 5, 1
    };

    printf("In the array:\n");
    for (y = 0; y < 5; y++){

        for (x = 0; x < 5; x++){
            if (x == 4){
                printf("%d\n",matrix[y][x]);
            }
            else {
                printf("%d\t", matrix[y][x]);
            }
            sum += matrix[y][x];

        }
    }

    printf("the sum of the elements is %d", sum);
    
    return 0;
}