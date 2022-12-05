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


//Your code and design here
//

// 1. grab tasks from txt 
// 2. create a linkedlist with the first task being the first node
// 3. add the tasks into the list based on scheduling
// 4. first task read will be the first in the list
// 5. FCFS.
// 

// schedule.txt is formatted like:
// [task name] [priority] [cpu burst]
// T1, 4, 20
// T2, 3, 25
// FCFS does not care about priority

// so basic
int createList(void);

const char filename[] = "schedule.txt";

int main(){

	createList();
	return 0;
}

int createList(void){
	// *****************************************************************
	// Parse filename and add each attribute to an array of Task structs
	// *****************************************************************
	FILE *fp = fopen(filename, "r");
	const char s[2] = ", ";
	char *token = (char *)malloc(sizeof(char)*5); 
	int i;
	int j = 0;

	Task tasks[8];
	
	if (fp != NULL){
		char line[20];
		while (fgets(line,sizeof line, fp) != NULL){
			//printf("%d ", j);
			for (i = 0; i < 3; i++){
				if (i == 0){
					// read task name and assign it
					// doesnt work
					token = strtok(line, s);
					//printf("%s ", tasks[j].name);
				} else if (i == 1) {
					// read task priority
					token = strtok(NULL, s);
					tasks[j].priority = atoi(token);
					//printf("%d ", tasks[j].priority);
				} else if (i == 2) {
					// read task burst time
					token = strtok(NULL, s);
					tasks[j].burst = atoi(token);
					//printf("%d\n", tasks[j].burst);
				}
			}
			j++;
		}
		fclose(fp);
	} else {
		printf("error\n");
	}
	// Not sure why, but T8 is copied to all structs
	// Manually renamed the name attribute
	// Name only contains the number
	// Name == tid
	for (int k = 0; k < 8; k++){
		char new = k + '1';
		tasks[k].name = &new;
		tasks[k].tid = k + 1;
		printf("Name: T%c, Tid: %d, Priority: %d, Burst: %d\n",
		       	*tasks[k].name,
			tasks[k].tid,
		       	tasks[k].priority,
		       	tasks[k].burst);
	}
	
	// ****************************************
	// Create nodes and add each Task to a node
	// ****************************************
	
	struct node *head = NULL;
	insert(&head, &tasks[0]);
	return 1;
}	

