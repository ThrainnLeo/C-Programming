#include <stdio.h>
int main(void){
    int Mammal;
    int Insect;
    int Spider;
    int Creepy;
    int a; 
// Vareabler 
    printf("My objekt analyser\n");
    printf("Enter number of legs: ");
    scanf("%d", &a);
//Starta koden med förklaring på hur man ska göra 
    Mammal = 0<= a && a <=4;
    Insect = 5<= a && a <8;
    Spider = a == 8;
    Creepy = 8< a;
// Skriv koden för vilka regler som finns 
    printf("Mammal  : %d\n", Mammal);
    printf("Insect  : %d\n", Insect);
    printf("Spider  : %d\n", Spider);
    printf("Creepy  : %d\n", Creepy);
// Läs in grejerna 


    printf("Now you know what objekt it is, Goodbye\n");
// skriv ut grejer
return 0;

}