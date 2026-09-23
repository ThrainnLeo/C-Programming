#include <stdio.h>

int main(void) {
    int i, j;
    int ndays;
    int weekday;

    printf("\nHello!\nI will print out a one-month calendar.\n\n");
    printf("Enter the number of days in the month: ");
    scanf("%d", &ndays);
    printf("Enter the starting day of the week (1=Mon, 7=Sun): ");
    scanf("%d", &weekday);
    printf("\n Mon Tue Wed Thu Fri Sat Sun\n");
    // if((i+1)%7==0), modolus

    for (i = 1; i < weekday; i++) {
        printf("    ");
    }

    for (j = 1; j <= ndays; j++) {
        printf("%4d", j);

        if ((i + j - 1) % 7 == 0 || j == ndays) {
            printf("\n");
        }
    }

    printf("\nGoodbye!\n\n");
    return 0;
}