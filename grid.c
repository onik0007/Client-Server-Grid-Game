#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

# define NUM_RANGE 9
#define ALPHA_RANGE 73
# define SIZE 26

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
    //char* ALINE;
    //This function prints out the board that was passed. Returns void
    char * const NLINE = "    A    B    C    D    E    F    G    H    I";
    char * const HLINE = "  +----+----+----+----+----+----+----+----+----+";
    char * const VLINE = "  |    |    |    |    |    |    |    |    |    |";

    printf("%s\n",NLINE);
    printf("%s\n",HLINE);

    //strcpy(ALINE, NLINE);
    //strcat(ALINE, HLINE);
    
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
    
    return ;

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




void saveWorksheet(){
    FILE *fp;
    fp = fopen("9x9Grid","a+");

    int j,k;
    //char* ALINE;
    //This function prints out the board that was passed. Returns void
    char * const NLINE = "    A    B    C    D    E    F    G    H    I";
    char * const HLINE = "  +----+----+----+----+----+----+----+----+----+";
    char * const VLINE = "  |    |    |    |    |    |    |    |    |    |";

    fprintf(fp,"%s\n",NLINE);
    fprintf(fp,"%s\n",HLINE);

    //strcpy(ALINE, NLINE);
    //strcat(ALINE, HLINE);
    
    for (j = 0; j < NUM_RANGE; j++)
    {  
        fprintf(fp,"%s\n",VLINE);
        fprintf(fp,"%d ",j+1);
        for (k = 0; k < NUM_RANGE; k++)
        {  if(strcmp(grid[k][j],"   ")==0){
                fprintf(fp,"| %s",grid[k][j]);
            }else{
                fprintf(fp,"| %s  ",grid[k][j]);
            }
        }
        fprintf(fp,"%s","|");
        fprintf(fp,"\n");
        fprintf(fp,"%s\n",VLINE);
        fprintf(fp,"%s\n",HLINE);
    }
    
    // add graph to file 
}

char * getList(int x1, int y1, int x2, int y2){//Create list from input for the funs

    char *values = malloc(81);
    int count = 0,i,j;

    for (i=y1; i<y2+1;i++){
        for (j =y1; j<y2;j++){
            values[count] =  *grid[i-1][j-1];
            count++;
        }
    }
    return values;
}


char * getCell(int x, int y) //1= True 0= False
{
    if (strcmp(grid[x-1][y-1],"   ") == 0)
    {
        return 0; //space is empty
    }
    else
    {
        return (grid[x-1][y-1]); //Space is occupied with existing letter
    }
}





//int main(){

//    getNewBoard();
//   saveWorksheet();
//    drawBoard();
//    makePlay(1,1,"a");
//    makePlay(2,1,"b");
//    makePlay(3,1,"c");
//    makePlay(4,1,"d");
//    makePlay(5,1,"e");
//    drawBoard();
//    printf("list: %s",getList(1,1,1,5));

    //printf("%c \n",drawBoard());

//    return 0;
//}

    
