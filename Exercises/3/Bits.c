#include <stdio.h>
int main(void){

    int nb;

    printf("hello, this is a digit caunter\n");
    printf("Enter a number:");
    scanf("%d", &nb);

    if (nb>=0 && nb<=9){
        printf("Number has 1 bit\n");
    } else {
        if (nb>=10 && nb<=99){
            printf("Number has 2 bits\n");
        } else {
            if (nb>=100 && nb<=999)
            printf("Number has 3 bits\n");
        }
    }


    printf("goodbye!\n");
    return 0;
}