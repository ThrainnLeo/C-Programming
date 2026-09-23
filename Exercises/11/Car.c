#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLESIZE 20
#define PRICESIZE 10
#define AUTHORSIZE 30
#define WHERESIZE 30 

typedef struct{
    char title[TITLESIZE + 1];
    double price;
    char author[AUTHORSIZE + 1];
    char where[WHERESIZE + 1];
    int id;

} Book;

void viewBook(Book *pBook){
    printf("Title : %s\n", pBook-> title);
    printf("Price : %.2f\n",pBook-> price);
    printf("Author : %s\n", pBook->author);
    printf("Where : %s\n", pBook-> where);
    printf("id : %d\n", pBook-> id);
}
Book initBook(char aTitle[], double aPrice[] , char anAuthor[], char aPlace[]){
    Book newBook;

    strcopy(newBook. title, aTitle);
    strcopy(newBook. price, aPrice);
    strcopy(newBook. author, anAuthor);
    strcopy(newBook. where, aPlace);
    newBook.id=1;
    return newBook;
}

int main(int argv, char **argc){
    Book marvel = initBook("Superman", 0.25, "Stan Lee", "Librery");

    printf("Librery\n");
    viewBook(&marvel);
    printf("Librery Exit\n");
    return 0;
}