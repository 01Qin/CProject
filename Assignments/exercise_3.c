//
// Created by Quinn on 28.8.2025.
//
#include <stdio.h>

int main() {
    int student_total = 0, i = 0, student_num, grade;

    printf("How many students: ");
    scanf("%d", &student_total);

    if (student_total <= 0) {
        printf("There is no student without any number!\n");
        return 0;
    }


    int grades[student_total];
    for (i = 0; i < student_total; i++) {
        grades[i] = -1;
    }

    while (1) {
        printf("Enter student number (1 - %d) or 0 to stop: ", student_total);
        scanf("%d", &student_num);

        if (student_num == 0) {
            break;
        }

        if (student_num < 1 || student_num > student_total) {
            printf("Invalid student number!\n");
            return 0;
        }

        printf("Enter grade (0 - 5) or -1 to stop: ");
        scanf("%d", &grade);

        if (grade <= -1 || grade > 5) {
            printf("Invalid grade!\n");
            return 0;
        }
        grades[student_num - 1] = grade;

        if (student_num == student_total) {
            break;
        }
    }

        printf("\n%-10s%-10s\n", "Student", "Grade");
        for (i = 0; i < student_total; i++) {
            printf("%-10d ", i + 1);
            if (grades[i] == -1) {
                printf("%-10s\n","N/A\n");
            }
            else {
                printf("%-10d\n", grades[i]);
            }
        }

        return 0;
    }
