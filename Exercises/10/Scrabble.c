#include <stdio.h>
#include <string.h>
#define SIZE 10

void viewBoard(char aBoard[][SIZE+1], int rows){
    printf(" 0123456789\n");
    for(int r=0; r<rows; r++){
        printf("%c%s\n", 'a' + r, aBoard[r]);
    }

}
int main(void){
    //char or string?
    //char board[SIZE][SIZE]={{'*', '*', '*'},....};
    char board[SIZE][SIZE+1]={"**********", //Gjort en 2D array med strängar 
                              "**********",
                              "*SCRABBLE*",
                              "**********",
                              "**********",
                              "**********",
                              "**********",
                              "**********",
                              "**********",
                              "**********",};
    char r, c, d;
    char w[SIZE];
    printf("Scrabble\n");

    viewBoard(board, SIZE);
    printf(" :");
    scanf(" %c%c%c %s", &r, &c, &d, w); // en bokstav, en bokstav, ett ord (en sträng)
    switch(d){
        case '>' :
        case 'v' : for(int row=r-'a'; row<r-'a'+strlen(w); row++)
                        board[row][c-'0'] = w[row - (r -'a')]; 
                    break;
        default  : printf("ERROR: Unknown direction");

    }
    viewBoard(board, SIZE);
    
    printf("Done bye\n");
}