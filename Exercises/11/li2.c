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
    printf("Author : %s\n", pBook->author.name);
    printf("Price  : %.2f\n", pBook->price);
    printf("Where  : %s\n", pBook->where);
    printf("Id     : %d\n", pBook->id);
}

Book initBook(char aTitle[], char anAuthor[], float aPrice, char aPlace[]){

   static int id=1;
   Book newBook;

   strcpy(newBook.title, aTitle);
   strcpy(newBook.author.name, anAuthor);
   newBook.price=aPrice;
   strcpy(newBook.where, aPlace);
   newBook.id=id++;
   return newBook;
}

Book enterBook() {
    char theTitle[TITLESIZE];
    char theAuthor[AUTHORSIZE];
    float thePrice;
    char thePlace[WHERESIZE];

    printf("Title  ? ");
    scanf("%[^\n]%*c", theTitle);
    printf("Author ? ");
    scanf("%[^\n]%*c", theAuthor);
    printf("Price  ? ");
    scanf("%f%*c", &thePrice);
    printf("Where  ? ");
    scanf("%[^\n]%*c", thePlace);

    return initBook(theTitle, theAuthor, thePrice, thePlace);
}

//--- End of Book package ------------------------

//--- Package Library ----------------------------

void viewLibrary(Book aLib[], int items) {
    for (int book=0; book<items; book++)
       viewBook(&aLib[book]);
}

//--- End of Library package ---------------------

int main(void) {

    Book lib[LIBSIZE]= { {"Superman", {{"Stan Lee", "USA", 1911}}, 1, 0.25, "Library"},
                        {"Batman", {{"Stan Lee", "USA", 1917}}, 2, 0.35, "Library"},
                        {"Hi & Luis", {{"Mort Walker", "USA", 1927}},3, 0.45, "Library"}};
    int books=0;
    char cmd;
    
    //lib[0]=initBook("Superman", "Stan Lee", 0.25, "Library");
     //lib[1]=initBook("Batman", "Stan Lee", 0.35, "Library");
    //books=3;

    printf("Library 0.6 AC\n");

    do {
      printf("%svaq : %s", GREEN, WHITE);
      scanf("%c%*c", &cmd);
      switch (cmd) {
        case 'a' : lib[books++]=enterBook(); break;
        case 'v' : viewLibrary(lib, books); break;
        case 'q' : break;
        default  : printf("%sPlease use one of a(dd), v(iew) or q(uit)!\n%s", GREY, WHITE);
      }
    } while (cmd!='q');

    printf("Done, bye!\n");
}