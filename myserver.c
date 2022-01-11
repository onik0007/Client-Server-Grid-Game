

///IDs#////////////
/*620112010
(other group member ids go here)
*/
#include <stdio.h>
#include <sys/types.h>	/* system type defintions */
#include <sys/socket.h>	/* network system functions */
#include <netinet/in.h>	/* protocol & struct definitions */
#include <stdlib.h>	/* exit() warnings */
#include <string.h>	/* memset warnings */
#include <unistd.h>

#define BUF_SIZE	1024
#define LISTEN_PORT	60000
#define NUM_RANGE 9

int main(int argc, char *argv[]){
    char * grid[NUM_RANGE][NUM_RANGE];
    int mysock,sock_recv;
    struct sockaddr_in  my_addr,recv_addr;
    int i,addr_size,bytes_received;
    int incoming_len,send_len;
    struct sockaddr remote_addr;
    int recv_msg_size;
    char buf[BUF_SIZE],msg[BUF_SIZE];



 void getNewBoard(){
        //creates a brand new blank board. Returns a pointer to the array 
        for (int j = 0; j < NUM_RANGE; j++){
            for (int k = 0; k < NUM_RANGE; k++)
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




int isonSheet(int x,int y){ 
    ///checks if position entered by user is on board
    
    
    if (x<=0 || y<=0){
   
        return -1;
        
        
        }
        
    else if(x>NUM_RANGE || y>NUM_RANGE){
        
       
        return -1;
        
        
    }

    else  return 1;
        
    
    
}// end isonboard



int * translatecell(char * cell){


/*comnverts a cell entered by client to a coordinate on the sheet,E.g A1 would be converted to (1,1) in form of array 
and returns an array
                                                            */
int x,y=0;

int * pt=NULL;
int coord[2];

if (cell[0]=='A'||cell[0]=='a'){

        x=1;

    }


    else if (cell[0]=='B'||cell[0]=='b'){


        x=2;
    }


    else if (cell[0]=='C'||cell[0]=='c'){


        x=3;
    }

    else if (cell[0]=='D'||cell[0]=='d'){


        x=4;
    }


    else if (cell[0]=='E'||cell[0]=='e'){


        x=5;
    }


    else if (cell[0]=='F'|| cell[0]=='f'){


        x=6;
    }


    else if (cell[0]=='G'||cell[0]=='g'){


        x=7;
    }
    else if (cell[0]=='H'||cell[0]=='h'){


        x=8;
    }

    else if (cell[0]=='I'||cell[0]=='i'){


        x=9;
    }




if (cell[1]==49){

        y=1;

    }


    else if (cell[1]==50){


        y=2;
    }


    else if (cell[1]==51){


        y=3;
    }

    else if (cell[1]==52){


        y=4;
    }


    else if (cell[1]==53){


       y=5;
    }


    else if (cell[1]==54){


        y=6;
    }


    else if (cell[1]==55){


        y=7;
    }
    else if (cell[1]==56){


        y=8;
    }

    else if (cell[1]==57){


        y=9;
    }





coord[0]=x;
coord[1]=y;


pt=&coord;
return pt;

}




char * selectcell(char * cell){

   //selects a cell on spreadsheet and returns the contents of the selected cell
 
int *pos=translatecell(cell);
char *c=grid[pos[0]-1][pos[1]-1];
printf("cell %s selected,value in cell:%c\n",cell,*c);
return c;


}//end selectcell




void placevalue(char *cell,char* c){

   //Arrays are zero indexed but our grid starts at index 1
   //places values in cells
   

   int * pos=translatecell(cell);
   grid[pos[0]-1][pos[1]-1]=c;

   return;

}//end placevalue





////++++++++++++++++++++++++++++FORMULA FUNCTIONS+++++++++++++++++++++++++++++++++++++++++++++++++++++////////////////////////////////////////////////




void average(char * cell1,char * cell2){

char *con; char*c;
if (cell1[0]==cell2[0]){

        printf("Column");



        }

    



}



/// need to expand this communicate() function

void communicate(){


 //receive msg from client

        


       //send msg to client
      strcpy(msg," Welcome to server,Enter a formula to send to server for evaluation or type 'quit'to exit");
      int bytes_sent=write(sock_recv,msg,BUF_SIZE);
  while (1){
        

        ///receive msg from client
       bytes_received=read(sock_recv,buf,BUF_SIZE);
        printf("received:%s\n", buf);
  
       buf[bytes_received]=0;
       msg[bytes_sent]=0;

       strcpy(msg,"Enter a formula to send to server for evaluation or type 'quit'to exit");
      int bytes_sent=write(sock_recv,msg,BUF_SIZE);



        
    if (strcmp(buf,"shutdown") == 0)
        break;
    }

    close(sock_recv);
    close(mysock);




    }




/////THIS  PORTION OF THE SERVER WAS COMMENTED OUT TO FACILITATE TESTING/////////////////////////////////////////////////////////////////////
            

////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*////////////////////////////////////////////////////////////

/*

            create socket for listening 
    mysock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (mysock < 0){
        printf("socket() failed\n");
        exit(0);
    }
        make local address structure 
    memset(&my_addr, 0, sizeof (my_addr));  /* zero out structure 
    my_addr.sin_family = AF_INET;   /* address family 
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* current machine IP 
    my_addr.sin_port = htons((unsigned short)LISTEN_PORT);

        /* bind socket to the local address 
    i=bind(mysock, (struct sockaddr *) &my_addr, sizeof (my_addr));
    if (i < 0){
        printf("bind() failed\n");
        exit(0);
    }
    
    
         listen ... 
    
    i=listen(mysock, 5);
    if (i < 0){
        printf("listen() failed\n");
        exit(0);
    }
        */




        /* get new socket to receive data on */
        /* It extracts the first connection request from the  */
    
    /* listening socket      
    addr_size=sizeof(recv_addr);
    sock_recv=accept(mysock, (struct sockaddr *) &recv_addr, &addr_size);


    /////COMMUNICATION ACTIVITES////////

    printf("A client has connected to this server\n");

    */

    //communicate();


//////+++++++++++++++++++++++++++++++++++++++++++++++++++///////////////////////////////////////////////////////////////////////////////




////testing section///////////////


getNewBoard();
drawBoard();
//int*pos=translatecell("a2");


//if (isonSheet(pos[0],pos[1])==1){

//printf("Yasss");

//}


//average("A1","A6");////this runs to a point needs to completed
placevalue("A1","1s");

selectcell("A1");

drawBoard();
}