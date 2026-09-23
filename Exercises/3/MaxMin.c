#include <stdio.h>
int main(void){
    int n1;
    int n2;
    int n3;
    int n4;

    printf("Hello, what is MAX and Min\n");
    printf("Select 4 numbers: \n");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if(n1>=n2 && n1>=n3 && n1>=n4) 
        printf("MAX:  %d\n", n1);
    if(n2>=n1 && n2>=n3 && n2>=n4) 
        printf("MAX:  %d\n", n2);
    if(n3>=n1 && n3>=n2 && n3>=n4) 
        printf("MAX:  %d\n", n3);
    if(n4>=n2 && n4>=n2 && n4>=n3) 
        printf("MAX:  %d\n", n4);

    if(n1<=n2 && n1<=n3 && n1<=n4) 
        printf("MIN: %d\n", n1);
    if(n2<=n1 && n2<=n3 && n2<=n4) 
        printf("MIN: %d\n", n2);
    if(n3<=n1 && n3<=n2 && n3<=n4) 
        printf("MIN: %d\n", n3);
    if(n4<=n1 && n4<=n2 && n4<=n3) 
        printf("MIN: %d\n", n4);

    printf("Now you know what is MAX and what is MIN, Goodbye!\n");
    return 0;
}