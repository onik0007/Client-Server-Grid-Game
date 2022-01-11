#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE	1024
#define LISTEN_PORT	60000
#define NUM_RANGE 9
#define SIZE 26
char * grid[NUM_RANGE][NUM_RANGE];

void getNewBoard(){
     //creates a brand new blank board. Returns a pointer to the array 
    int j,k;
     //char * grid[NUM_RANGE][NUM_RANGE];
    for (j = 0; j < NUM_RANGE; j++){
        for (k = 0; k < NUM_RANGE; k++)
        {
            grid[k][j]="   ";
        }//Endfor
    }//Endfor
    return;
}//EndFunction getNewBoard
void drawBoard(){
    int j,k;
     //This function prints out the board that was passed. Returns void
    char * const NLINE = "    A    B    C    D    E    F    G    H    I";
    char * const HLINE = "  +----+----+----+----+----+----+----+----+----+";
    char * const VLINE = "  |    |    |    |    |    |    |    |    |    |";

    printf("%s\n",NLINE);
    printf("%s\n",HLINE);
    for (j = 0; j < NUM_RANGE; j++)
    {  
        printf("%s\n",VLINE);
        printf("%d ",j+1);
        for (k = 0; k < NUM_RANGE; k++)
        {  if(strcmp(grid[k][j],"   ")==0){
                printf("| %s",grid[k][j]);
            }else{
                printf("| %s  ",grid[k][j]);
            }
        }
        printf("%s","|");
        printf("\n");
        printf("%s\n",VLINE);
        printf("%s\n",HLINE);
    }
    return;
}//EndFunction drawBoard
void makePlay(int x, int y, char* c){
     //Arrays are zero indexed but our grid starts at index 1
    grid[x-1][y-1]=c;

    return;
}//EndFunction makePlay
void startBoard(int *num, char*l){
     //struct startPlays p1;
    for (int i = 0;i<11;i++)
    {
        printf("%d %d %c \n",*(num +i),*(num +i+11),*(l+i));
         //makePlay(*(num +i),*(num +i+10),strcat(*(l+i),"");
    }
 //create fun to generate ran num 1-9, add to array(compare to previous to prevent duplicates)
}//EndFunction startBoard



int Average(int num1, int num2)
{
    return 0;
}
int Sum(int num1, int num2)
{
    return 0;
}
int Range(int num1, int num2)
{
    return 0;
}
void saveWorksheet()
{

}

int main(int argc, char *argv[]){

    int sock_listen,sock_recv;
    struct sockaddr_in  my_addr,recv_addr;
    int i,bytes_received;
    int incoming_len,send_len;
    struct sockaddr remote_addr;
    int recv_msg_size;
    char buf[BUF_SIZE],msg[BUF_SIZE];
    socklen_t addr_size;

            /* create socket for listening */
    sock_listen=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_listen < 0){
        printf("socket() failed\n");
        exit(0);
    }
        /* make local address structure */
    memset(&my_addr, 0, sizeof (my_addr));  /* zero out structure */
    my_addr.sin_family = AF_INET;   /* address family */
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* current machine IP */
    my_addr.sin_port = htons((unsigned short)LISTEN_PORT);
        /* bind socket to the local address */
    i=bind(sock_listen, (struct sockaddr *) &my_addr, sizeof (my_addr));
    if (i < 0){
        printf("bind() failed\n");
        exit(0);
    }
    
    
        /* listen ... */
    
    i=listen(sock_listen, 5);
    if (i == 0){
        printf("listen() failed\n");
        exit(0);
    }
     
 
        /* get new socket to receive data on */
        /* It extracts the first connection request from the  */
        /* listening socket  */
    //addr_size=sizeof(recv_addr);
    sock_recv=accept(sock_listen, (struct sockaddr *) &recv_addr, &addr_size);
    while (1){
        bytes_received=recv(sock_recv,buf,BUF_SIZE,0);
        //buf[bytes_received]=0;
        printf("Received: %s\n",buf);
        printf("Enter messsage to send to client:" );
        printf("To end communication enter shutdown or quit");
        scanf("%s",msg);
        int bytes_sent=send(sock_recv,msg,BUF_SIZE,0);
        
    if (strcmp(buf,"shutdown") == 0)
        break;
    }
    //close(sock_recv);
    //close(sock_listen);
}