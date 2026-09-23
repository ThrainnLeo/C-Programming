#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLESIZE 20
#define PRICESIZE 10
#define AUTHORSIZE 30 + 1
#define WHERESIZE 30 +1 
#define LIBRERYSIZE 100

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
Book initBook(char aTitle[], char anAuthor[] , double aPrice, char aPlace[]){
    Book newBook;

    strcpy(newBook. title, aTitle);
    strcpy(newBook. author, anAuthor);
    // strcpy(newBook. price, aPrice);
    newBook.price = aPrice;
    strcpy(newBook. where, aPlace);
    newBook.id=1;
    return newBook;
}

int main(int argv, char **argc){
    Book lib[LIBRERYSIZE]; 
    int books=0;

    lib[0]= initBook("Superman", "Stan Lee", 0.25, "Librery");
    lib[1]= initBook("Batman", "Stan Lee", 0.35, "Librery");
    books=2;

    printf("Librery\n");
    for(int book=0; book<books; book++)
        viewBook(&lib[book]);
    printf("Librery Exit\n");
    return 0;
}