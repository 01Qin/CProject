//
// Created by Quinn on 26.9.2025.
//

#include "Student grade calculator.h"


int main(void) {
    char input_name[NAME_SIZE];
    bool valid_input = false; // Variable for student name input validation status
    int subject_num = 0; // Variable to store the number of subjects the user enters
    FILE *report_file = NULL; // File pointer for the generated report

    subject_data *subject_array = NULL; // Pointer for dynamic array of subject data

    printf("Welcome to the Student Grade Calculator!\n");

    // 1. Student name input and validation loop
    do {
        // Function call to prompt user
        valid_input = get_validated_filename(input_name, NAME_SIZE);
        if (valid_input) {
            if (strcmp(input_name, "stop") == 0) {
                printf("Program stopped.\n");
                return 0;
            }
        }
    } while (!valid_input); // Keep looping until valid name or 'stop' is entered

    // 2. Subject count input
    subject_num = get_validated_int("How many subjects do you want to calculate grades for? ", 1, MAX_SUBJECTS);
    // Allocate memory for the subject_array based on the user's input subject_num
    subject_array = (subject_data *) calloc(subject_num, sizeof(subject_data));

    if (subject_array == NULL) {
        fprintf(stderr, "Failed to allocate memory for subjects.\n");
        return 1;
    }

    // 3. Subject data collection loop
    for (int i = 0; i < subject_num; i++) {
        char subject_name[NAME_SIZE];
        bool valid_subject_name = false;

        do {
            printf("\n");
            printf("Enter subject %d name: ", i + 1);

            if (fgets(subject_name, NAME_SIZE, stdin) == NULL) {
                fprintf(stderr, "Failed to read subject %d.\n", i + 1);
                free(subject_array);
                return 1;
            }
            if (strchr(subject_name, '\n') == NULL) {
                fprintf(stderr, "Subject name is too long! Max %d characters.\n", NAME_SIZE);
                clear_input_buffer(); // Clear excess characters from stdin
                subject_name[0] = '\0';
                valid_subject_name = false;
                continue; // Restart loop
            } else {
                subject_name[strcspn(subject_name, "\n")] = '\0';
            }

            // Check if the name is empty or only whitespace
            if (check_whitespace(subject_name)) {
                fprintf(stderr, "Invalid subject name. Cannot be empty or only spaces.\n");
                subject_name[0] = '\0';
                valid_subject_name = false;
                continue;
            }
            // Check of the name contains others than letters and spaces
            else if (!check_string(subject_name)) {
                fprintf(stderr, "Invalid subject name. It must contain only letters and space.\n");
                subject_name[0] = '\0';
                valid_subject_name = false;
                continue;
            }
            // Copy the name to the stuct array
            strncpy(subject_array[i].name, subject_name, NAME_SIZE - 1);
            subject_array[i].name[NAME_SIZE - 1] = '\0';
            valid_subject_name = true;
        } while (subject_name[0] == '\0');

        // 4. Score input
        char prompt[PROMPT_BUFFER];
        // Build the prompt dynamically
        strcpy(prompt, "Enter your score for ");
        strncat(prompt, subject_array[i].name, sizeof(prompt) - strlen(prompt) - 1);
        strncat(prompt, "(0-100): ", sizeof(prompt) - strlen(prompt) - 1);

        int score = get_validated_int(prompt, 0, MAX_GRADE);

        // Store score and calculated numeric grade (1,2,3,4,5)
        subject_array[i].score = score;
        subject_array[i].numeric_grade = calc_grade(score);
    }

    //5. Report file handling
    report_file = fopen("report.txt", "w");

    if (report_file == NULL) {
        fprintf(stderr, "Failed to open report.txt.\n");
    } else {
        printf("Subjects report:\n");
    }

    // Print the final grade to both console and file
    print_grade(input_name, subject_array, subject_num, report_file);

    if (report_file != NULL) {
        fclose(report_file);
    }

    free(subject_array); // Free allocated memory
    subject_array = NULL;
    return 0;
}

// ----------------------------------------------------------------------
// HELPER FUNCTIONS
// ----------------------------------------------------------------------

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool check_whitespace(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isspace(s[i])) {
            return false;
        }
    }
    return true;
}

bool check_string(const char *s) {
    if (s == NULL || s[0] == '\0') { // Check for neither empty string nor alphabetic character
        return false;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        // Allow both letters (isalpha) and spaces (isspace)
        if (!isalpha(s[i]) && !isspace(s[i])) {
            return false;
        }
    }
    return true;
}

bool get_validated_filename(char *filename_buffer, size_t buffer_size) {
    printf("Please enter your name or 'stop' to stop: ");

    if (fgets(filename_buffer, buffer_size, stdin) == NULL) {
        return false;
    }

    if (strchr(filename_buffer, '\n') == NULL) {
        filename_buffer[0] = '\0';
        fprintf(stderr, "Invalid input. Please enter your name within %zu characters.\n", buffer_size - 1);
        clear_input_buffer();
        return false;
    }
    filename_buffer[strcspn(filename_buffer, "\n")] = '\0';

    if (strcmp(filename_buffer, "stop") == 0) {
        return true;
    }
    if (check_whitespace(filename_buffer)) {
        fprintf(stderr, "Invalid input: Name cannot be empty or only spaces. Please try again!\n");
        filename_buffer[0] = '\0';
        return false;
    }
    if (!check_string(filename_buffer)) {
        fprintf(stderr, "Invalid input: Name must only contain letters and spaces. Please try again.\n");
        filename_buffer[0] = '\0';
        return false;
    }
    return true;
}

int get_validated_int(const char *prompt, int min_value, int max_value) {
    int value = 0;
    char buffer[NAME_SIZE];
    int count = 0;
    char random_char = '\0';
    bool input_success = false;

    while (!input_success) {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "Error reading from user.\n");
            return -1;
        }
        count = sscanf(buffer, "%d %c", &value, &random_char);
        if (count == 1) { // Read exactly one integer
            if (value >= min_value && value <= max_value) {
                input_success = true;
            } else {
                fprintf(stderr, "Input must be between %d and %d. Please try again.\n", min_value, max_value);
            }
        } else if (count == 2) {
            fprintf(stderr, "Invalid input. Please enter a whole number only.\n");
        } else {
            fprintf(stderr, "Invalid input. Please a whole number.\n");
        }
    }
    return value;
}

int calc_grade(int score) {
    if (score >= 90) {
        return 5;
    } else if (score >= 80) {
        return 4;
    } else if (score >= 70) {
        return 3;
    } else if (score >= 60) {
        return 2;
    } else if (score >= 50) {
        return 1;
    } else {
        return 0;
    }
}

void print_grade(const char *student_name, const subject_data *subjects, int count, FILE *output_file) {
    double total_grade = 0.0;

    for (int i = 0; i < count; i++) {
        total_grade += subjects[i].numeric_grade;
    }

    double average_grade;
    if (count > 0.0) {
        average_grade = total_grade / count;
    } else {
        average_grade = 0.0;
    }
    print_to_file(output_file, "--------------------------------------------\n");
    print_to_file(output_file, "Student: %s\n", student_name);
    print_to_file(output_file, "--------------------------------------------\n");
    print_to_file(output_file, "%-30s %-7s %s\n", "Subject", "Score", "Grade");
    print_to_file(output_file, "--------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        print_to_file(output_file, "%-30s %-2d%%  %5d\n",
                      subjects[i].name,
                      subjects[i].score,
                      subjects[i].numeric_grade);
    }
    print_to_file(output_file, "\nAverage grade: %.2f\n", average_grade);
    print_to_file(output_file, "--------------------------------------------\n");
}

void print_to_file(FILE *output_file, const char *fmt, ...) {
    va_list args_console;
    va_list args_file;

    // Print to the console
    va_start(args_console, fmt);
    vprintf(fmt, args_console);
    va_end(args_console);

    // Print to file
    if (output_file != NULL) {
        va_start(args_file, fmt);
        vfprintf(output_file, fmt, args_file);
        va_end(args_file);
    }
}
