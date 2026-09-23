#include <stdio.h>
#include <math.h>
#define VALUES 10                    // Största antal input
	
//Dekleration av menuhantering  
void enterM(int storage[], int size, int *pSpot);        //Där man matar in mätvärden 
void viewM(int storage[], int size);                     // Där man visar mätvärden 
void resetM(int storage[], int size, int *pSpotLAST);    // Återställer mätvärden 
void calcM(int storage[], int calc);                     //"Beräknar mätvärden" fast ändå inte  

int main(void) {
    char input='q';       //Lagrar användarens inmatning
    int pSpot=0;          // Håller reda på antalet inmatade mätvärden
    int nmb[VALUES]={0};  //en arrey till alla inlagda värden med hänsyn till konstanten "maximala input"  
    
   
    printf("Starting Lab #2...\n\n");
    printf("Measurement calculator!\n\n");
    printf("VECRQ? x\n");
    printf("Please use:\n v to View\n e to Enter\n c to Compute\n r to Reset\n q to Quit\n");

// Huvudloop för att hantera menyn och användarinmatning
    do{
        scanf(" %c", &input);
        switch(input){
            case 'v' : viewM(nmb, VALUES        )   ; break;
            case 'e' : enterM(nmb, VALUES, &pSpot)   ; break; // adressen skickas till variabeln spot som ett argument (värdet kan ändras)
            case 'c' : calcM(nmb, pSpot          )   ; break;
            case 'r' : resetM(nmb, VALUES, &pSpot)   ; break; //  adressen skickas till variabeln spot som ett argument (värdet kan ändras)
            case 'q' : break;
            default  : printf("Please use:\n v to View\n e to Enter\n c to Compute\n r to Reset\n q to Quit\n"); break;
        }


    } while (input!='q'); // loopen fortsätter tills man trycker (q)


	printf("...Lab #2 done, bye!\n");
	return 0;
}

//------menu packetet-------

void enterM(int storage[], int size, int *pSpot){
    for(int i=*pSpot; i<size; i++){
        printf("Enter measurement #%d or (0) :", i+1);
        scanf("%d", &storage[i]);
        (*pSpot)++; //håller reda på antalet matade värden 
        if(storage[i]==0){ // Avsluta inmatningen om användaren matar in (0) eller roppar på andra funktioner 
            (*pSpot)--; //minskar värdet med 1 (ifall användaren skriver in 0)
            break;
        }
    }
}

void viewM(int storage[], int size){
    int ZERO=0;                         //lokal vareabel som kontrolerar om det finns några mätvärden i arrayen 
    for(int i=0; i<size; i++){
        if(storage[i]!=0){
            ZERO = 0;
            break;
        }
    }
    if(ZERO){
        printf("No input\n");
    } else {
        printf("Values given:\n");
        printf("[");
    for(int i=0; i<size; i++){
        if(storage[i]==0 && storage[i+1]!=1){ // (storage[i] säger att alla värden som inte är namngivna är = 0) (storgae[i+1] undersöker om nästa värde är = 0 eller inte)
            break;
        } else{
            printf("%2d ", storage[i]);
        }
    }
    printf("]\n\n");
    }
}

void resetM(int storage[], int size, int *pSpot){
    for (int i=0; i<size; i++){
        storage[i]=0;
    }
    *pSpot=0;
    printf("Reset!\n\n");
}

//----------Uträknings packetet i kompilatorn-----

int maxValue(int storage[], int calc)
{
    int max;
    max = storage[0];
    for(int i = 1; i < calc; i++)
    {
        if(storage[i] > max) // går i genom alla värden och uppdaterar max-värdet 
        {
            max = storage[i];
        }
    }
    return max;
}
int minValue(int storage[], int calc)
{
    int min;
    min = storage[0];
    for(int i = 1; i < calc; i++)
    {
        if(storage[i] < min) // går i genom alla värden i arreyen och uppdaterar min-värdet 
        {
            min = storage[i];
        }
    }
    return min;
}
float avrValue(int storage[], int calc)
{
    int sum = 0; // Lagrar summan av mätvärden
    float avr; // lagrar genomsnittet av mätvärdena
    for(int i = 0; i < calc; i++) // En loop för att initiera över alla mätvärden i arrayen storrage
    {
        sum += storage[i]; // Lägger till det aktuella mätvärdet till summen
    }
    avr = (float) sum/calc; // Beräknar genomsnittet genom att dividera summan med antalet mätvärden
    return avr; // Returnerar genomsnittet som en flyttalsvariabel 
}
void normArray(int storage[], int normValues[], int calc)
{
    for(int i = 0; i < calc; i++)
    {
        normValues[i] = round(storage[i] - avrValue(storage, calc));// räknar ut normvärdet 
    }
    return;
}
void calcM(int storage[], int calc)
{
    if(calc > 0) //kontrollera om det finns mätvärden att beräkna 
    {
        int normValues[calc];
        normArray(storage, normValues, calc);                   // Normalisera mätvärdena
        printf("Max value: %d\n", maxValue(storage, calc));     // Visar maximalt värde
        printf("Min value: %d\n", minValue(storage, calc));     // Visar minimalt värde
        printf("Avr value: %.2f\n", avrValue(storage, calc));   // Visar genomsnittligt värde
        viewM(normValues, calc);                                // Visa normaliserade 
    }
    else
    {
        printf("No measurements\n"); // Medela om inga mätväden finns 
    }
    return;
}