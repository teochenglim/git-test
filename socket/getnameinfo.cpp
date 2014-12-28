 // Run on Windows Xp Pro, Visual C++ .Net 1.1

#include <stdio.h>

#include <winsock2.h>

#include <ws2tcpip.h>

#define NI_MAXHOST  1025

#define NI_MAXSERV    32

 

int main()

{

  // Declare variables
  WSADATA wsaData;

 

  // Initialize Winsock, request the Winsock 2.2

  int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

  if(iResult != NO_ERROR)

    printf("Error at WSAStartup().\n");

  else

    printf("WSAStartup() is OK.\n");

 

// Declare and initialize variables

hostent* remoteHost;

char* ip;

struct sockaddr_in saGNI;

char *hostName;

char servInfo[256];

int retVal;

u_short port;

port = 55555;

 

// Input name of host

printf("Input name of host: ");

hostName = (char*) malloc(sizeof(char*)*128);

fgets(hostName, 128, stdin);

 

printf("\nUsing gethostbyname()...\n");

hostName[strlen(hostName)-1] = '\0';

remoteHost = gethostbyname(hostName);

ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);

printf("IP address is: %s.\n", ip);

printf("Address type: %i.\n\n", remoteHost->h_addrtype);

 

// Set up sockaddr_in structure which is passed

// to the getnameinfo() function

saGNI.sin_family = AF_INET;

// saGNI.sin_addr.s_addr = inet_addr(ip);

saGNI.sin_addr.s_addr = inet_addr(ip);

saGNI.sin_port = htons(port);

 

// Call getnameinfo

if ((retVal = getnameinfo((SOCKADDR *)&saGNI,

  sizeof(sockaddr),

  hostName,

  256,

  servInfo,

  256,

  NI_NUMERICSERV)) != 0)

{

  printf("getnameinfo() failed.\n");

  printf("Error #: %ld.\n", WSAGetLastError());

}

else

  printf("getnameinfo() is OK.\n");

 

  WSACleanup();

  return 0;

}