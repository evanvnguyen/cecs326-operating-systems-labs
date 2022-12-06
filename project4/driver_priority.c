/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100

Task mytasks[8];

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
	
    int i = 0;
    int j;
    in = fopen(argv[1],"r");
    Node *head = NULL;	    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the local mytasks struct
	mytasks[i].name = name;
	mytasks[i].priority = priority;
	mytasks[i].burst = burst;

	// add the task to the schedulers linked list of tasks
        add(name,priority,burst, 0, 1, 1);
	
        free(temp);
	i++;
    }

    fclose(in);
    // For priority scheduling:
    // Sort the tasks based on priority
    Task temp1;
    for (i = 0; i < 8; i++){
    	for (j = 0; j < 8; j++){
	    if (mytasks[j].priority > mytasks[j+1].priority){
		temp1 = mytasks[j];
		mytasks[j] = mytasks[j+1];
		mytasks[j+1] = temp1;
	    }
    	}
    }

    for (i = 0; i < 8; i++){
    	//printf("%s, %d, %d\n", mytasks[i].name, mytasks[i].priority, mytasks[i].burst);
    	add(mytasks[i].name, mytasks[i].priority, mytasks[i].burst, 0, 1, 0);
    }

    // invoke the scheduler
    schedule();

    return 0;
}
