#include <stdio.h>
int main(int argc, char **argv){
int t = 0;
int s = 0; 
int v = 0;
int h = 324;

// visa programtitel (printf)
//visa tabellrubrik (printf)
printf("Constant acc demo\n");
printf("Time : Speed : Distance\n");
// Upprepa!!
do{
    printf("%4d:%5d:%8d\n",t,v,s);
    t = t + 1;
    v = 10 * t;
    s = 0.5 * 10 * t * t;
} while (s<324);
printf("Ground [%d..%d] sek!\n", t-1,t);
// visa t (heltal), s (heltal) och v (heltal) 

// visa att det är klart (printf)
printf("Program completed, Goodbye!\n");
return 0;

}

// Formeln för s --> s = 0.5 * a * t^2
// Formeln för v --> v = a * t 
// Höjden från eiffeltornet --> h = 324
// accelerationen --> a = 10 (9.82)
// Frågan är att vi ska göra en tabell över vad s och v blir varje sekund tills bollen träffar marken 




