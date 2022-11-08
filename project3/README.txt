CECS 326
Project 3
Group: Evan Nguyen 025625195

NOTE: This Makefile utilizes clang instead of gcc. To compile the source,
ensure you have the latest version of clang installed on your machine. If
skip this portion if clang is installed. If you would rather use gcc, see
below:

Changing the Makefile to use gcc:
----------------------------------
1) Find line 2 where it says 
	--> clang -0 main main.c
2) replace clang with gcc
	--> gcc -o main main.c

Standard clang compilation:
---------------------------------
1) In terminal/command line, type this command to run the makefile:
	--> make
	- This command compiles the source and creates an executable
2) In terminal/command line, type this command to run the executable:
	--> ./main
3) The program is set to run 100 times, randomly choosing between east/west
   villages and randomly choosing a set of people in those villages. The 
   program also randomly selects a set of actions that occur while crossing
   the road.

Thank you!
-Evan Nguyen
