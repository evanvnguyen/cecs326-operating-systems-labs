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
#include "cpu.h"
#define SIZE    100

static const int TIME = 10; // Time quantum
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
	
        free(temp);
	i++;
    }

    fclose(in);
    
    // add each task to the list
    // subtract the time quantum
    // if the result burst time is negative or 0, delete from list
    // else, loop back
    int num_done = 0;
    while (num_done < 8){
        for (i = 0; i < 8; i++){
    	    if (mytasks[i].burst > 0){
                run(&mytasks[i], TIME);
	    }
	    if (mytasks[i].burst - TIME <= 0){
		mytasks[i].burst = 0;
		printf("Task %s finished.\n", mytasks[i].name);
		num_done++;
	    } else {
		mytasks[i].burst = mytasks[i].burst - TIME;
            }
	    //printf("%s, %d, %d\n", mytasks[i].name, mytasks[i].priority, mytasks[i].burst);
    	}
    }
   
    for (i = 0; i < 8; i++){
    	//printf("%s, %d, %d\n", mytasks[i].name, mytasks[i].priority, mytasks[i].burst);
    	add(&head, mytasks[i].name, mytasks[i].priority, mytasks[i].burst, 0, 1, 1);
    }

    // invoke the scheduler
    schedule();

    return 0;
}
