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

struct Task returnTaskContents(void);
struct node returnLinkedList(struct Task); // to be examined

// Dummy struct
// This is implemented in task.h
struct Task {
	char name[2];
	int burst;
};

int main(){
	returnTaskContents();
	return 0;
}
struct Task returnTaskContents(void){
	
	// read the file
	FILE* ptr;
	char ch;

	// open file in reading mode
	ptr = fopen("schedule.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened\n");
	}
	
	printf("content: \n");

	// print what is written in file char by char
	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);
	
	// dummy task
	struct Task Task1;
	strcpy(Task1.name, "t1");
	Task1.burst = 0;

	// ***************************************
	// Parse for comma separater
	// Add name and burst time to the struct
	// ***************************************

	// close the file 
	fclose(ptr);	
	
	return Task1;
}	

// returns a node
// traverse it in main
struct node returnLinkedList(struct Task){
	// add the tasks to the linked list
	// starting with the first task
	return NULL;
}
