#include <stdio.h>
int main(void){
    int Year;
    int Month;
    int Day;

    printf("Date of birth from US to EU\n");
    printf("Select date of birth in US\n :");
    scanf("%d. %d. %d", &Year, &Month, &Day);

    printf("Year    : %04d", Year);
    printf("Month    : %02d", Month);
    printf("Day    : %02d", Day);


    printf("Your date of birth in EU should be:\n");
    return 0;

}