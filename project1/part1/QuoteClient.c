
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
        server_address.sin_addr.s_addr = INADDR_ANY; // IN_ADDR_ANY = #define'd as an unsigned long int 0x00 (0.0.0.0);

	// connect to the socket
	// my_socket - our socket
	// second field - cast to ptr sockaddr
	// return 0 - OK
	// return -1 - ERROR

        int status = connect(my_socket, (struct  sockaddr *) &server_address, sizeof(server_address));

        // check the status of the connection
        if (status == 0){
                printf("Returned 0: Connection successful\n");
        } else if (status == -1){
                printf("Returned -1: Connection unsucessful\n");
        }

        // receive data from the connection and store into a buffer, print it
        char response[256];
        recv(my_socket, &response, sizeof(response), 0);
        printf("%s\n", response);

        // close the socket
        close(my_socket);

        return 0;

}
