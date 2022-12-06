/**
	 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

// schedule.txt is formatted like:
// [task name] [priority] [cpu burst]
// T1, 4, 20
// T2, 3, 25
// FCFS does not care about priority
// and executes the first task given 

Task task;

void add(struct node **head, char *name, int priority, int burst, int fcfs, int pri, int rr){
	// instead of allocating array of Task,
	// can just dynamically create new nodes 
	// here with the passed parameters.
	
	task.name = name;
	task.priority = priority;
	task.burst = burst;
	
	insert(head, &task);
	//traverse(head);
	run(&task, task.burst);
}

void schedule(void){
	//traverse(head);
	printf("FCFS scheduling finished!\n");	
}


