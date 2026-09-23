// Uppgiften är att skapa en databas med användares brädspelsbetyg. Programmet har två
// inloggningsmöjligheter såsom administratör och såsom användare. Som administratör kan man lägga
// till och ta bort användare. Som användare kan man lägga till och ta bort brädspel och betyg. Alla
// användare och deras brädspel och betyg sparas i en textfil när programmet avslutas och kan läsas in
// när programmet startas

// Skapa ett spel-struct som innehåller spelets namn och ett betyg (lägg array på 40 täcken och består av ett ord)
// Betyg 1-10
// Skapa ett användar stuct som innehåller användarnamn(max 40 tecken och ett ord)
// En array med 20 spel-strucktar och ett heltal som håller reda på antalet spel användaren har lagt in 
// Lagra alla användare i en array med plats för 30 användar-structar
// Skriv (#define) för alla maxtak
// 

#include <stdio.h>
#include <string.h>
// #include <stdlib>

// #define GAMESIZE 20
#define GAME_NSIZE 41
#define UN_SIZE 41
#define USERSIZE 30
#define GAMESIZE 20

//Definera struct
typedef struct {
    char Game_Name[GAME_NSIZE];
    int Grade[10];
} Games;
//Definera struct 
typedef struct{
   char UserName[UN_SIZE];
    char game[GAMESIZE]; 
    int games;
} User;

// void login(){
//     FILE *fptr;
//     fptr = fopen("login.txt","r");// oklar med den med 
// }
// void read(){
//     FILE *fptr;
//     fptr = fopen("Data.txt", "r"); //oklart om detta ska vara rätt
// }
void addgames(){
    char another;
    FILE *fptr;
    Games game;
    fptr = fopen("User_games.txt", "w"); //vet inte om jag ska lägga in det som står i dokumentet här eller i main
    
    do{
        printf("Welcome to user rating file\n");
        printf("Enter a new game: \n");
        scanf("%s", game.Game_Name);
        printf("Please grade this game: \n");
        scanf("%d", game.Grade);

        for(int i=0; i<11; i++){
            scanf("%d", &game.Grade[i]);
        }

        if (fptr == NULL){
            printf("Cant open file\n");
        }else{
            fprintf(fptr, "%s %d\n", game.Game_Name, game.Grade);
            printf("Game grading stored successfully\n");
        }
        printf("Do you whant to grade another game?\n");
        scanf("%s", &another);
    }
    while(another == 'y'|| another=='Y');
    fclose(fptr);
}
void adduser(int gamelib[], int *count){
    char another;
    FILE *fptr;
    User user;
    fptr = fopen("Admin_record.txt", "w");

    do{
        printf("Welcome to Admin records\n");
        printf("Enter a new user\n");
        scanf("%s", user.UserName);
        printf("How many games does this user have?\n");
        scanf("%d", &user.game[*count]);

        for(int i=0; i<21;i++){
            scanf("%d", &user.game[i]);
        }

        if (fptr == NULL){
            printf("Cant open file\n");
        }else{
            fprintf(fptr, "%s %d\n", &user.UserName, &user.game[*count]);
            printf("Users games are stored successfully\n");
        }
    }
    while(another == 'y'|| another == 'Y');
    fclose(fptr);



}
// void admin(...);
// void user(...);


int main(){
    int input;
    

    printf("Welcome user please select something on the menu\n");
    
    do{
        printf("1. Add games\n");
        printf("2. Add Users\n");

        switch(input){
            case 1: addgames(); break;
            case 2: adduser(UN_SIZE, GAMESIZE); break; 
        }
    }while(input != 2);
return 0;
//Deklarera en int på antalet användare


//En string som innehåller namnet på textfilen som användaren har anget 

//Deklarera en array av användar-structar

}
