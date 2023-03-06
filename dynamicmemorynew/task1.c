#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_NAME_LENGTH 15

char *read_string()
{
    char *buffer = (char *)malloc(MAX_NAME_LENGTH + 1);
    fgets(buffer, MAX_NAME_LENGTH + 1, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}

void print_aligned(char *str, int width)
{
    printf("%-*s", width, str);
}

int main()
{
    int num_subjects, num_students = 0;
    char subjects[MAX_SUBJECTS][MAX_NAME_LENGTH];
    int **grades = NULL;
    char **students = NULL;

    printf("Enter the number of subjects (maximum %d): ", MAX_SUBJECTS);
    scanf("%d", &num_subjects);
    getchar(); 

    if (num_subjects <= 0 || num_subjects > MAX_SUBJECTS)
    {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    printf("Enter the names of the subjects:\n");
    for (int i = 0; i < num_subjects; i++)
    {
        printf("Subject %d: ", i + 1);
        fgets(subjects[i], MAX_NAME_LENGTH + 1, stdin);
        subjects[i][strcspn(subjects[i], "\n")] = '\0';     }


    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add student\n");
        printf("2. Print diary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); 

        switch (choice)
        {
        case 1:
            printf("Enter student name: ");
            char *student_name = read_string();

            num_students++;
            students = (char **)realloc(students, num_students * sizeof(char *));
            students[num_students - 1] = student_name;

            grades = (int **)realloc(grades, num_students * sizeof(int *));
            grades[num_students - 1] = (int *)malloc(num_subjects * sizeof(int));

            printf("Enter grades for %s:\n", student_name);
            for (int i = 0; i < num_subjects; i++)
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &grades[num_students - 1][i]);
                getchar();
            }
            break;
        case 2:
            printf("\n");

            printf("%*s", MAX_NAME_LENGTH + 1, "");
            for (int i = 0; i < num_subjects; i++)
            {
                print_aligned(subjects[i], MAX_NAME_LENGTH + 1);
            }
            printf("\n");

            for (int i = 0; i < num_students; i++)
            {
                print_aligned(students[i], MAX_NAME_LENGTH + 1);
                for (int j = 0; j < num_subjects; j++)
                {
                    printf("%*d", MAX_NAME_LENGTH + 1, grades[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}