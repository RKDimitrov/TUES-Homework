#include <stdio.h>
#include "processes.h"
#include <limits.h>
#include <string.h>

struct Process processes[5];
int processescount = 0;

int nextprocessid(){
    static unsigned int processid = 0;
    processid++;
    return processid;
}

int createnewprocess(char name[30]){
    struct Process q1;
    q1.id = nextprocessid();
    
    if(processescount != 5){
        processes[processescount] = q1;
        processescount ++;
        return q1.id;
    }else{
        return 0;
    }
}

void stopprocess(int id){
    int DelIndex;
    for (int i = 0; i < processescount; i++)
    {
        if (processes[i].id == id)
        {
            DelIndex = i;
        }
    }
    if (DelIndex < processescount)
    {
        struct Process temp;
        temp = processes[processescount];
        processes[processescount] = processes[DelIndex];
        processes[DelIndex] = temp;
    }
    processescount--;
}
