#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>

int main() {
        // Create a new socket using:
        // AF_INET - internet IPv4 family type
        // SOCK_STREAM - TCP for port 6017
        // 0 - default protocol 
        int my_socket  = socket(AF_INET, SOCK_STREAM, 0);

        // specify an address for the socket
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(6017);
       
       	// IN_ADDR_ANY = #define'd as an unsigned long int 0x00 (0.0.0.0);
       	server_address.sin_addr.s_addr = INADDR_ANY;

	// connect to the socket
	// my_socket - our socket
	// second field - cast to ptr sockaddr
	// return 0 - OK
	// return -1 - ERROR

        int status = connect(my_socket, (struct  sockaddr *) &server_address, sizeof(server_address));
	
	bool is_ready;
        // check the status of the connection
        if (status == 0){
                printf("[Client] Returned 0: Connection successful\n\n");
        	is_ready = true;
	} else if (status == -1){
                printf("[Client] Returned -1: Connection unsucessful\n");
        }

        // receive data from the connection and store into a buffer, print it
      	char send_msg[256]; 
       	char response[256];
	
	while(is_ready){

		printf("[Client]: ");
		scanf("%s", send_msg);
		send(my_socket, &send_msg, sizeof(send_msg), 0);
		recv(my_socket, &response, sizeof(response), 0);

		if (strcmp(response, "exit") == 0) {
			is_ready = false;
			break;
		}

		printf("[Server]: %s\n\n", response);
	}
        
	printf("[Client] Connecton closed\n");

        // close the socket
        close(my_socket);

        return 0;

}
