#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "grid.c"

#define PORT 8787876890000

double average(char arr[]) {

   double sum = 0.0;
   int i;

    for(i = 0; i<sizeof(*arr);i++){
        sum+= arr[i] - '0';
    }
    return sum/i;
}
double sum(char arr[]) {

    double sum = 0.0;
    int i;

    for(i = 0; i<sizeof(*arr);i++){
        sum+= arr[i] - '0';
    }
    return sum;
}
double max(char arr[]){
    int i;
    
    // Initialize maximum element
    int max = arr[0] - '0';
    // compare every element with current max 
    for (i = 1; i < sizeof(*arr); i++){
        if (arr[i] > max)
            max = arr[i] - '0';
    }
 
    return max;
}
double min(char arr[]){
    int i;
    
    // Initialize maximum element
    int min = arr[0] - '0';
    // compare every element with current min 
    for (i = 1; i < sizeof(*arr); i++){
        if (arr[i] < min)
            min = arr[i] - '0';
    }
    return min;
}




int main(){
    int x1,x2,y1,y2;
    char c;

	int listeningsock,ret;
	struct sockaddr_in host_addr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024]; //toSend data
    pid_t childpid;

	//char client_message[1024]; //toRec data

	listeningsock = socket(AF_INET, SOCK_STREAM, 0); //creating socket on server side ..socket(domain,type of input,IP)
	if (listeningsock <0){
        printf("[-]Connection Error!\n");
        exit(1);
    }
    printf("[+]Server Socket Created Sucessfully.\n");

	    //creating an address to bind to
	memset(&host_addr, '\0', sizeof(host_addr)); 	/* zero out structure */
	host_addr.sin_family = AF_INET;		//address family 
	host_addr.sin_port = htons(PORT);
	host_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	//host machine IP 	*port #

		/* bind socket to the local address */
    ret = bind(listeningsock, (struct sockaddr*)&host_addr, sizeof(host_addr));
	if (ret < 0){
		printf("[-]Binding failed.\n");
        exit(1);
	}
    printf("[+]Binding sucessful, port: %d\n", 4444);

	if(listen(listeningsock, 10) == 0){
        printf("[+]Listning...\n");
    }
    else{
        printf("[-] Error.\n");
    }
    getNewBoard();
    int activeUser = 0 ;

    while(1){
        newSocket = accept(listeningsock, (struct sockaddr*)&newAddr, &addr_size);
        if (newSocket < 0){
            exit(1);
        }
        printf("[+] Connection successful from %s %d\n", inet_ntoa(newAddr.sin_addr) ,ntohs(newAddr.sin_port));
        activeUser+=1;

        if ((childpid = fork()) == 0){
            close(listeningsock);

            while (1){
                recv(newSocket,buffer,1024,0); //Get x
                if (strcmp(buffer,"shutdown") == 0){
                    printf("[+] Disconnected from %s %d\n", inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
                    activeUser-=1;
                    break;
                }//use else if to terminate if 1st client 'shutdown' 0.0.0.0
                else{
                    x1 = buffer[1] - 48;
                    y1 = buffer[2] - 48;
                    x2 = buffer[3] - 48;
                    y2 = buffer[4] - 48;
                    //CASE TO DETERMINE IF THE USER WANTS. 
                    char CHOICE = buffer[0];
                    //c = activeUser+'0';
                    //strcpy(buffer, &c);
                    //send(newSocket,buffer,1024,0);
//should split str by "("
                    switch(CHOICE) {
                        case 'A' :
                            printf("Average selected!\n");
                            printf("list: %s size: ",getList(x1,x2,y1,y2));
                            printf("%f\n",average(getList(x1,x2,y1,y2)));
                            break;
                        case 'S' :
                            printf("Sum selected!\n");
                            printf("list: %s sum: %f \n",getList(x1,x2,y1,y2), sum(getList(x1,x2,y1,y2)));
                            //printf("size: %d\n",sizeof(getList(x1,x2,y1,y2)));
                            break;
                        case 'R' :
                            printf("Range selected\n" );
                            printf("%f\n", (max(getList(x1,x2,y1,y2))-min(getList(x1,x2,y1,y2))));
                            break;
                        case 'W' :
                            drawBoard();
                            saveWorksheet();
                            printf("Worksheet Saved\n" );
                            break;
                        default :
                            printf("Make Play\n" );
                            makePlay(buffer[1]-'0',buffer[2]-'0',&buffer[0]); 
                       }

                    printf("Client Said: %c\n", buffer[0]);
                    send(newSocket,buffer,strlen(buffer),0); //- send grid to client 
                }
            }
        }
    }
    close(newSocket);
    return 0;
}
