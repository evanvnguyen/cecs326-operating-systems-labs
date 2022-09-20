
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {

	// create a string to hold the quote
	char msg[256] = "You only live once";

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

	// send() data to the connected socket
	send(client_socket, msg, sizeof(msg), 0);

	// close() the socket
	close(my_server);
	
	return 0;	
}
