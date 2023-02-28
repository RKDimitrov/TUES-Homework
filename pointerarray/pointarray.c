#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addStudent(char* name,char students, char* subjects, int numSubjects, int numStudents){
    char *students = (char *)realloc(students, (numStudents + 1) * sizeof(char));
    printf("Enter student name: ");
}

int main(){
    int numSubjects;
    int numStudents = 0;
    char *subjects = (char *)malloc(15 * sizeof(char));
    char *students = (char *)malloc(20 * sizeof(char));

    printf("Enter the number of subjects (maximum 20): ");
    scanf("%d", &numSubjects);
    if(numSubjects <= 0 || numSubjects > 20){
        printf("Invalid number of subjects.\n");
        scanf("%d",&numSubjects);
    }

    printf("Enter the number or students: ");
    scanf("%d", &numStudents);
    if(numStudents <=0){
        printf("Invalid number of students.\n");
        scanf("%d", &numStudents);
    }

    printf("Enter the names of the subjects:\n");
    for(int i = 0; i < numSubjects; i++){    
        scanf("%s", &subjects[i]);   
    }
    
    while(1){
        int choice;
        printf("1.Add student\n");
        printf("2.Print diary\n");
        printf("3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            printStudent();
        default:
            break;
        }
    }

    free(subjects);
    free(students);
    return 0;
}