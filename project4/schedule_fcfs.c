/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int returnTaskContents(void);
struct node returnLinkedList(struct task); // to be examined

const char filename[] = "schedule.txt";

int main(){
	returnTaskContents();
	return 0;
}

int returnTaskContents(void){
	FILE *fp = fopen(filename, "r");
	const char s[2] = ",";
	char *token;
	int i;
	if (fp != NULL){
		char line[20];
		while (fgets(line,sizeof line, fp) != NULL){
			token = strtok(line, s);
			for (i = 0; i < 3; i++){
				if (i == 0){
					// read task name
					printf("%s ", token);
					token = strtok(NULL, s);
				} else if (i == 1) {
					// read task priority
					printf("%d ", atoi(token));
				} else if (i == 2) {
					// read task burst time
					token = strtok(NULL, s);
					printf("%d\n", atoi(token));
				}
			}
		}
		fclose(fp);
	} else {
		printf("error\n");
	}
	
	return 1;
}	

// returns a node
// traverse it in main
//struct node returnLinkedList(struct task){
	// add the tasks to the linked list
	// starting with the first task
//	return NULL;
///}
