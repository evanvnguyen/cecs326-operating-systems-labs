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

void add(char *name, int priority, int burst){
	Node *head = NULL;
	task.name = name;
	task.priority = priority;
	task.burst = burst;
	insert(&head, &task);
		
}

void schedule(void){

}
