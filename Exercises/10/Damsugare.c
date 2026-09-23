#include <stdio.h>
#include <string.h>
#define SIZE 10 
 void lookUp(int fst, int snd, int trd){
    char lut[][7]={ "black", "brown", "red", "orange", "yellow", "green", "blue", "purple", "gray", "white"};
    int value = i; 
    for (i=0; i<10; i++){
        if(strcmp(colour, lut[i])==0)
        return value[i];
    } 
    printf("%s %s %s\n", lut[fst], lut[snd], lut[trd]);
 }
 int main(int argc, char **argv){
    char value[SIZE]= "150"; 
    printf("Resistor colour look-up table!\n");
    printf("Enter resistor value [ohm] : ");
    scanf("%s", value);
    printf("Resistor colour code is       : ");
    // lookUp(1,2,3);

    switch(strlen(value)){
        case 1  : lookUp(0, value[0]-'0', 0); break;
        case 2  : lookUp(value[0]-'0', value[1]-'0', 0); break;
        default : lookUp(value[0]-'0',value[1]-'0', strlen(value)-2);
    }


    printf("RCLT Done, bye!\1");
    return 0;
 }