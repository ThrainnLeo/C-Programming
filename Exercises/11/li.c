#include <stdio.h>
#include <string.h>

#define RED    "\e[31m"            // Error messages
#define GREEN  "\e[32m"            // User mode
#define YELLOW "\e[33m"            // Headings
#define BLUE   "\e[34m"            // Adm mode
#define PURPLE "\e[35m"            // Debug messages
#define CYAN   "\e[36m"            // Reserv
#define GREY   "\e[37m"            // Information messages
#define WHITE  "\e[0m"             // Reset to white

//--- A Book package -----------------------------
#define TITLESIZE 20+1
#define AUTHORSIZE 30+1
#define WHERESIZE 30+1
#define LIBSIZE 100
#define FROMSIZE 20+1
#define MAXAUTH 5

typedef struct{
    char name[AUTHORSIZE];
    char from[FROMSIZE];
    int born;
} Author;

typedef struct {
    char title[TITLESIZE];
    char author[AUTHORSIZE];
    float price;
    char where[WHERESIZE];
    int id;
} Book;

void viewBook(Book *pBook) {
    printf("%sTitle  : %s%s\n", YELLOW, pBook->title, WHITE);
    for(int author=0; author<pBook->nbOfAuthors; author++)
    printf("Author : %s\n", pBook->author);
    printf("Price  : %.2f\n", pBook->price);
    printf("Where  : %s\n", pBook->where);
    printf("Id     : %d\n", pBook->id);
}

Book initBook(char aTitle[], char anAuthor[], float aPrice, char aPlace[]){

   static int id=1;
   Book newBook;

   strcpy(newBook.title, aTitle);
   strcpy(newBook.author, anAuthor);
   newBook.price=aPrice;
   strcpy(newBook.where, aPlace);
   newBook.id=id++;
   return newBook;
}

//--- End of Book package ------------------------

// package librery
void viewLibrery(Book aLib[], int items){
    for(int book=0; book<items;book)
    viewBook(&aLib[book]);
}

int main(void) {

    Book lib[LIBSIZE];
    int books=0;
    
    book lib[LIBSIZE]={"Superman", {{"Stan Lee", "USA", 1911}},1, 0.25, "Library"};//forsätter vidare sen
    lib[1]=initBook("Batman", "Stan Lee", 0.35, "Library");
    books=2;

    printf("Library 0.4 AC\n");

    for (int book=0; book<books; book++)
       viewBook(&lib[book]);

    printf("Done, bye!\n");
}