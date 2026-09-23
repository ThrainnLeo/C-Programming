#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SUITS 4
#define RANK 13
#define DECK 52
#define FACE 10

void initRandomGenerator(void){
    srand((unsigned)time(NULL));
}
int rndNumber(int nbs){
    return rand()%nbs;
}

void printCard(int aCard){
    switch (aCard/RANK){
        case 0:printf("[Club   ]"); break;
        case 1:printf("[Dimond ]"); break;
        case 2:printf("[Heart  ]"); break;
        case 3:printf("[Spade  ]"); break;
    }
    switch (aCard%RANK){
        case 0:     printf("A]");   break;
        case 9:     printf("T]");   break;
        case 10:    printf("J]");   break;
        case 11:    printf("Q]");   break;
        case 12:    printf("K]");   break;
        default:    printf("%d]", (aCard%RANK)+1); break; 
    }
}

int getRANK(int aCard){
    if((aCard%RANK)>=FACE)
        return FACE;
    else
        return (aCard%RANK)+1;

}

int main(int argc, char **argv){
    {
        printf("Mounte Carlo\n");

        for(int card=0; card<DECK; card++){
            printCard(card);
            printf("[%d]", getRANK(card));
            printf("\n");
        }
    printf("Program compleded, bye!\n");
    return 0;
    }
}


// jag tror att koden inte är klar och att det fattas några rader i slutet 