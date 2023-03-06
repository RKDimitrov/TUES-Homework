
#include <stdio.h>
#include <stdlib.h>

#define ERROR_MSG "Memory allocation error. Exiting...\n"

float calculate_average(float grades[], int num_grades) {
    float sum = 0;
    for (int i = 0; i < num_grades; i++) {
        sum += grades[i];
    }
    return sum / num_grades;
}

void add_grade(float **grades, int *num_grades) {
    float new_grade;
    printf("Enter the new grade: ");
    scanf("%f", &new_grade);

    if (*num_grades == 100) {
        printf("The maximum number of grades has been reached. Cannot add another grade.\n");
        return;
    }

    *num_grades += 1;
    *grades = (float *)realloc(*grades, *num_grades * sizeof(float));
    if (*grades == NULL) {
        printf(ERROR_MSG);
        free(*grades);
        exit(1);
    }
    (*grades)[*num_grades - 1] = new_grade;
    printf("Grade %f has been added.\n", new_grade);
}

void delete_last_grade(float **grades, int *num_grades) {
    if (*num_grades == 0) {
        printf("No grades to delete.\n");
        return;
    }

    *num_grades -= 1;
    *grades = (float *)realloc(*grades, *num_grades * sizeof(float));
    if (*grades == NULL && *num_grades != 0) {
        printf(ERROR_MSG);
        free(*grades);
        exit(1);
    }
    printf("Last grade has been deleted.\n");
}

int main() {
    int num_grades = 0;
    float *grades = NULL;

    do {
        printf("Enter the number of initial grades (must be a positive integer): ");
        scanf("%d", &num_grades);
    } while (num_grades <= 0);

    grades = (float *)malloc(num_grades * sizeof(float));
    if (grades == NULL) {
        printf(ERROR_MSG);
        free(grades);
        exit(1);
    }

    printf("Enter the initial grades:\n");
    for (int i = 0; i < num_grades; i++) {
        scanf("%f", &grades[i]);
    }

    int choice;
    do {
        printf("1. Calculate average grade of the student\n");
        printf("2. Add a new grade\n");
        printf("3. Delete the last grade\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("The average grade of the student is %f\n", calculate_average(grades, num_grades));
                break;
            case 2:
                add_grade(&grades, &num_grades);
                break;
            case 3:
                delete_last_grade(&grades, &num_grades);
                break;
            case 4:
                free(grades);
                break;
            default:
                printf("Invalid choice. Try again.");
        }
    } while (choice != 4);

    return 0;
}