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
	// add the task to the schedulers linked list of tasks
        add(&head,name,priority,burst, 1, 0, 0);
	
        free(temp);
	i++;
    }

    fclose(in);
    // invoke the scheduler
    schedule();

    return 0;
}
