#include <stdio.h>
#define G 1.5 
#define K 0.1
int main(void){
    int t = 0, throttle;
    float h = 250.0, v = -25.0, fuel = 500.0;
    float vt, ht, fuelt;

//programmeringslabb 1 nedan med while-loop
    printf("\nMoon Landing!\n"); //säg hej OCH skriv ut vad programmet ska göra
    printf("You will pilot a rocketship the last 250m\n");
    printf(" Each row represents the moon landing for each second\n");
    printf(" Set the throttle at each turn between 1 and 100 procent\n");
    
    printf("\nTime:  Height:  Velocity:  Fuel:   Throttle:\n"); //skriv ut tabellrubrik
    
    while (h > 0.0) { //beräkna variablernas nya värde OCH om farkosten ej har landat; börja vid * igen
        printf("%2ds %8.1fm %6.1fm/s %7.1fl   ", t, h, v, fuel); 
        scanf("%d", &throttle);

        if (throttle < 0 || 100 < throttle) {
            printf("Error! the throttle value has to be a whole number between 0 and 100!\n"); 
        }
        else {
            h = h + v + (K * throttle - G)/2;
            v = v + (K * throttle - G);
            fuel = fuel - throttle;
            t ++;
        }
    }
        if (v < -2) { //skriv ut om landningen gick bra eller inte
            printf("Oh no, a krasch landing :(\n");
            printf("Restart and try again!\n");
        }
        else {
            printf("Yes!, successful landing!\n");
            printf("Good job, bye!\n"); //säg hejdå
        }
    return 0;  
    
}


// Gaspådrag = f : Verkningsgrad = K = 0.1 : Gravitation på månen = G = 1.5
// Hastigheten vid tidpunkten t --> v(t) = v(t-1) + (fK-G)
// Höjden över månytan vid tidpunkten t --> h(t) = h(t-1) + v(t)- (fK - G)/2
// Återstående bränsle vid tidpunkten t --> b(t) = b(t-1) - f
// Vi ska inte ta hänsyn till att bränslet kan ta slut

// Vi ska beräkna "gaspådraget", Vi ska skriva ett program som simulerar vad som händer vid olika "gaspådrag" under de sista 250m mot månytan
// faktorsatsen antas ha hastigheten -25m/s på 250m höjd och 500kg bränsle

//programmeringslabb 1 nedan med while-loop 