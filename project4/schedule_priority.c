/*
 * Priority scheduling
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

/*
 * Your code and design here:
 */

Task task;

void add(char *name, int priority, int burst, int fcfs, int pri, int rr){

	Node *head = NULL;
	//Node *head = NULL;
	task.name = name;
	task.priority = priority;
	task.burst = burst;
	insert(&head, &task);
	//priTraverse(head);	
	if (fcfs == 0 && pri == 1 && rr == 0) {
		run(&task, task.burst);
	}

}

void schedule(void){	
	//printf("%d\n", task.priority);
	printf("Priority scheduling finished!\n");
}
