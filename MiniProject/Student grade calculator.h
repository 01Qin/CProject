//
// Created by Quinn on 26.9.2025.
//

#ifndef C_ASSIGNMENTS_STUDY_PLANNER_H
#define C_ASSIGNMENTS_STUDY_PLANNER_H
#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdarg.h>
#define NAME_SIZE 21
#define MAX_GRADE 100
#define MAX_SUBJECTS 10
#define PROMPT_BUFFER 100

typedef struct {
    char name[NAME_SIZE];
    int score;
    int numeric_grade; // Grade on a 1-5 scale
} subject_data;

void clear_input_buffer();
bool check_whitespace(const char *s);
bool check_string(const char *s);
bool get_validated_filename(char *filename_buffer, size_t buffer_size);
int get_validated_int(const char *prompt, int min_value, int max_value);
int calc_grade(int score);
void print_grade(const char *student_name, const subject_data *subjects, int count, FILE *output_file);
void print_to_file(FILE *output_file, const char *fmt, ...);


#endif //C_ASSIGNMENTS_STUDY_PLANNER_H
