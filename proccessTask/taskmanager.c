#include "processes.h"
#include <stdio.h>

void print_processes() {
    printf("ID\tName\n");
    for (int i = 0; i < processescount; i++) {
        printf("%d\t%s\n", processes[i].id, processes[i].name);
    }
}

int main() {
    int choice;
    char name[30];
    int id;
    do {
        printf("\nTask Manager\n");
        printf("1. Create new process\n");
        printf("2. List all processes\n");
        printf("3. Stop process\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process name: ");
                scanf("%s", &name);
                int result = createnewprocess(name);
                if(result == 0) printf("Error: Maximum number of running processes reached. Please stop a process to create a new one.\n");
                else printf("New process created with ID %d\n", result);
                break;
            case 2:
                print_processes();
                break;
            case 3:
                printf("Enter process id to stop: ");
                scanf("%d", &id);
                stopprocess(id);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}