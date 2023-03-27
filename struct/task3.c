#include <stdio.h>
#include <stdlib.h>

int studentsCount = 0;

typedef struct {
    char name[15];
    int number;
    double grade;
} Student;



int main(){
   

    Student *students = NULL;
    while (1)
    {
        int choice;
        printf("------Menu------\n");
        printf("1. Add a student\n"); 
        printf("2. Print all students\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Adding student\n"); 
                studentsCount++;
                students = (Student*)realloc(students, studentsCount * sizeof(Student));
                printf("Enter name: ");
                scanf("%s", students[studentsCount - 1].name);
                printf("Enter number: ");
                scanf("%d", &students[studentsCount - 1].number);
                printf("Enter grade: ");
                scanf("%lf", &students[studentsCount - 1].grade);

                break;
            case 2:
                printf("Printing all students\n");
                for (int i = 0; i < studentsCount; i++)
                {
                    printf("Name: %s,\n Number: %d,\n Grade: %lf\n", students[i].name, students[i].number, students[i].grade);
                }
                break;
            case 3:
                printf("Exiting");
                return 0;
                break;
        }
    }
    
    
}