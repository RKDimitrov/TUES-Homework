#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int num_subjects, num_students = 0;
    char subjects[10][20];

    do{
        printf("Enter number of subjects");
        scanf("%d", &num_subjects);
    }while(num_subjects <= 0);

    printf("Enter the names of the subjects:\n");
    for(int i; i < num_subjects; i++){
        printf("Subjects:");
        fgets(subjects[i], 20 + 1, stdin);
        subjects[i][strcspn(subjects[i], "\n")] = '\0';
    }
    while (1)
    {
        printf("1: Add Student");
        printf("2: +Print Diary");

        int choice;
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
        }
    }
    
}