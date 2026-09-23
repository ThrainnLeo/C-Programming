#include <stdio.h>
int main(void){
    int n;
    int Max = 0;

    printf("Hello I will calculate the max values of some numbers\n");
   
   do {
    printf("Enter some values of numbers:");
    scanf("%d", &n);
    if ( n > Max) Max=n;
        Max = n;
   } while (n != 0);


    printf("The maximal value is: %d\n\n", Max);
    return 0;
}

// do
    //Statment
    //while (expression);
// e=1+1/1!+1/2!+1/3!+1/4!