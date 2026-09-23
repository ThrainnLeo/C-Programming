#include <stdio.h>
int main(void){

int code;

printf("Hello, lets look at some areacodes\n");
printf("Please enter a areacode: \n");
scanf("%d", &code);

switch (code){
    case 229  : printf("Albany:  \n"); break;
    case 404  : printf("Atlanta \n"); break;
    case 470  : printf("Atlanta \n"); break;
    case 478  : printf("Macon \n"); break;
    case 678  : printf("Atlanta \n"); break;
    case 706  : printf("Columbus \n"); break;
    case 762  : printf("Colombus \n"); break;
    case 770  : printf("Atlanta \n"); break;
    case 912  : printf("Savannah \n"); break;
    case 913  : 
    default   : printf("Not recognized\n"); break;
}

printf("Goodbye!\n");
return 0;
}