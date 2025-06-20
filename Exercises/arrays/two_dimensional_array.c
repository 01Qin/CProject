#include <stdio.h>

int main()
{
    int first_matrix[5][5] = 
    {2, 34, 23, 21, 58, 
    3, 6, 56, 2, 9, 
    76, 92, 2, 4, 77, 
    1, 45, 45, 8, 33, 
    99, 3, 34, 5, 78};

    int second_matrix[5][5] =
    {45, 3, 34, 6, 77, 
    2, 45, 67, 3, 2, 
    21, 23, 54, 67, 67, 
    43, 2, 45, 99, 0, 
    54, 76, 88, 63, 5};
    
    // need the third array for holding the sum of the matrices
    int sum_matrix[5][5];
    int y, x;

    for (y = 0; y <5; y++)
    {
        for (x = 0; x< 5; x++)
        {
            sum_matrix[y][x] = first_matrix[y][x] + second_matrix[y][x];
                if (x == 4) {
                    printf("%d\n", sum_matrix[y][x]);
                }
                // every time the value of x is 4, the program must print a newline. 
                // In other cases, a tab character (\t) is printed between the elements.
                else {
                    printf("%d\t", sum_matrix[y][x]);
                }
        }
    }
}