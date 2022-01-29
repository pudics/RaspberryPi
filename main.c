#include <stdio.h>
#include <time.h>

#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Get time =======================================================================
    time_t currentTime;
    char *currentTimeInString;
    struct tm *local;

    char hourDigitMSB;
    char hourDigitLSB;
    char minDigitMSB;
    char minDigitLSB;
    char secDigitMSB;
    char secDigitLSB;

    // Get current system time
    currentTime = time(NULL);
    local = localtime(&currentTime);

    printf("time --> %d : %d : %d\n", local->tm_hour, local->tm_min, local->tm_sec);

    // Check if time was successfully retreived
    if (currentTime == (time_t)-1)
    {
        printf("Failed to get the current time.\n");
    }
    else
    {
        // Convert retreived time to string
        currentTimeInString = ctime(&currentTime);

        // Check if time was successfully converted to string
        if (currentTimeInString == NULL)
        {
            printf("Failed to convert the current time.\n");
        }
        else
        {
            printf("The current time is: %s\n", currentTimeInString);

            // Retreive hour, min, sec digit information from string
            hourDigitMSB = currentTimeInString[11];
            hourDigitLSB = currentTimeInString[12];
            minDigitMSB = currentTimeInString[14];
            minDigitLSB = currentTimeInString[15];
            secDigitMSB = currentTimeInString[17];
            secDigitLSB = currentTimeInString[18];

            printf("The current time is: %c %c %c %c %c %c\n",
                hourDigitMSB,
                hourDigitLSB,
                minDigitMSB,
                minDigitLSB,
                secDigitMSB,
                secDigitLSB);

        }
    }


    // Get weather temperature =======================================================================
    
    // create a socket
    int networkSocket;
    networkSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(networkSocket, (struct sockaddr *)&server_address, sizeof(server_address));
    // check for error with the connection
    if (connection_status == -1)
    {
        printf("There was an error making a connection to the remote socket.\n");
    }

    // receive data from the server
    char server_response[256];
    recv(networkSocket, &server_response, sizeof(server_response), 0);

    // print out the server's response
    printf("The server sent the data: %s\n", server_response);

    // and then close the socket
    close(sock);

    //Get EUR to HUF exchange rate =======================================================================
    char *address;
    address = argv[1];

    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // connect to an address
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);
    inet_aton(address, &remote_address.sin_addr.s_addr);

    connect(client_socket, (struct sockaddr *)&remote_address, sizeof(remote_address));

    char request[] = "GET / HTTP/1.1\r\n\r\n";
    char response[4096];

    send(client_socket, request, sizeof(request), 0);
    recv(client_socket, &response, sizeof(response), 0);

    printf("response from the server: %s\n", response);
    close(client_socket);


    // Get gold price in HUF =======================================================================


    // Email notification =======================================================================

    return 0;
}