#include <stdio.h>
#define SIZE 'Z'-'A'+1

int main(void){
    int frqTbl[SIZE]={0};
    char ch;
    printf("Hello, This is a Morse decoder\n");
// Ber om en lång mening

// läs in och markerar 
printf("please enter a short text\n");
do{
    scanf("%c", &ch);
    if ((ch>='A') && (ch<='Z')) 
    frqTbl[ch-'A']++;
} while (ch!='\n');
printf("\n");

// visa resultat 
    for (char ch='A'; ch<='Z'; ch++){
        printf(" %c", ch);
    }
    printf("\n");
    for (char ch='A'; ch<='Z'; ch++){
        printf("%2d", frqTbl[ch-'A']);
    }
    printf("\n");



    printf("Done, Goodbey\n");
}

// Vi ska läsa in tecken för tecken (Bra att använda '\n')
// Gör en Hurts som ska bestå av A--Z
// När vi skriver (%d) så får vi fram en vareabel, men om vi skriver (%5d) får vi vareabler i 5 positioner 