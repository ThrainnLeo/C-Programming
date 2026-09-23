#include <stdio.h>
int main(void){
float f = 100;
float c = 37;

printf("Converter fom farenheit to celsius\n");
printf("Please enter temp in Faranheit\n");
 printf("value, f:");
 scanf("%f", &f);

c = (f-32) * 5/9;

printf("Temp in Celcius should be: %.1f goodbye\n",c);
return c;
}