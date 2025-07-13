#include <stdio.h>
int main()
{
    int matrix[5][4];
    int squares[5][4];

    int x, y;

    FILE *read_file;
    FILE *write_file;

    if((read_file = fopen("matrix.txt", "r")) == NULL){
        printf("Failed to open file (matrix.txt).");
        return 0;
    }
    else {
        for(y = 0; y < 5; y ++){
            for(x = 0; x < 4; x++){
                if(x == 3){
                    fscanf(read_file, "%d", &matrix[y][x]);
                }
                else {
                    fscanf(read_file, "%d", &matrix[y][x]);
                }
            }
        }
    }
    fclose(read_file);

    for(y = 0; y < 5; y++){
        for(x = 0; x < 4; x ++){
            squares[y][x] = 0; squares[y][x] = matrix[y][x] * matrix[y][x];
        }
    }

    if((write_file = fopen("squares.txt", "w")) == NULL){
        printf("Failed to open file (squares.txt).");
    }
    else {
        for(y = 0; y < 5; y ++){
            for(x = 0; x < 4; x ++){
                if(x == 3){
                    fprintf(write_file, "%d\n", squares[y][x]);
                }
                else {
                    fprintf(write_file, "%d", squares[y][x]);
                }
            }
        }
    }
    fclose(write_file);
    return 0;
}