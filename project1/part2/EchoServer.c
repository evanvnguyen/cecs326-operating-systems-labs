
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {

	// create a string to hold the quote
	char msg[256] = "Hello there! I am the server";

	// create the server socket
	int my_server = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(6017);
	server_address.sin_addr.s_addr = INADDR_ANY; // local machine

	// bind the socket to our IP and port
	bind(my_server, (struct sockaddr*) &server_address, sizeof(server_address));

	// listen() to any connections
	// my_socket - created socket
	// 1 - max # of queue pending connections
	listen(my_server, 5);

	// accept() the connection
	// my_socket = created socket
	// NULL - struct to store the incoming address - not used
	// NULL - strut to store the incoming address length - not used
	int client_socket = accept(my_server, NULL, NULL);
	
	bool is_ready;

	// accept() will return a non-negative integer on a successful connection 
	// and will return -1 on non-successful connection. 
	if (client_socket > 0){
		printf("Returned 0: Connection successful\n\n");
		is_ready = true;
	} else if (client_socket == -1) {
		printf("Returned -1: Connection unsuccessful\n");
	} else {
		printf("Fatal error. Unknown return\n");
	}

	char inc_message[256];

	while (is_ready) {	

		if (client_socket == -1) {
			is_ready = false;
		}
	
		recv(client_socket, &inc_message, sizeof(inc_message), 0); 
	
		if (strcmp(inc_message, "exit") == 0){
			is_ready = false;
		}
		
		// echo here
		send(client_socket, &inc_message, sizeof(inc_message), 0);

		printf("[Client] %s\n\n", inc_message);
		
		}

	printf("Connection closed\n");
	
	// close() the socket
	close(my_server);
	
	return 0;	
}
