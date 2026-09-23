#include <stdio.h>
#define SIZE 6

int viewMap(char b[][SIZE], int m[][SIZE], int size){
    int done = -2;
    printf("    1  2  3  4  5  6\n");
    for (int row=0; row<size; row++) {

        printf(" %d ", row+1);
        for (int col=0; col<size; col++) {
            if (b[row][col]=='+')
            printf(" %d ", m[row][col]);
             else { 
            printf(" * ");
                done++;
            }
        }
        printf("\n");
    }
    return done;
}
int main(void){
    char map[SIZE][SIZE] = {{'*','*','*','*','*','*'},
                            {'*','B','*','*','*','*'},
                            {'*','*','*','*','*','*'},
                            {'*','*','*','B','*','*'},
                            {'*','*','*','*','*','*'},
                            {'*','*','*','*','*','*'}};
    int min[SIZE][SIZE]  =  {{1 , 1 , 1 , 0 , 0 , 0},
                            { 1 , 9 , 1 , 0 , 0 , 0},
                            { 1 , 1 , 2 , 1 , 1 , 0},
                            { 0 , 0 , 1 , 9 , 1 , 0},
                            { 0 , 0 , 1 , 1 , 1 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0},};
char r='1', c='1';
int d;

printf("Boom 0.43 AC\n");

do {
    map[r-'1'][c-'1']='+';
    if ((d = viewMap(map,min, SIZE))==0){
        printf("You win!!\n");
        break;
    } else {
        printf("DBG: Squears left %d\n", d);
    }
    printf("Where: ");
    scanf(" %c%c", &r, &c);
} while (map[r-'1'][c-'1']!='B');
printf("BOOM!!! bye!\n");
}