/*Variabler: 
  Funktioner:
  Konstanter:
  Strukturer: spel (namn och betyg), Användare (använd_namn och spel (max 20st) och heltal för antal spel)
  Admin: Kan man lägga till och ta bort spelare. 
  Användare: Kan man lägga till och ta bort brädspel samt betyg (sparas i textfil)
  Data: Alla användare, brädspel och betyg ska sparas i en textfil*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GAME_N 40
#define USER_N 40
#define MAX_USERS 30
#define MAX_GAMES 20
#define PASSWORD 40
#define GAMEARR 20

typedef struct{ //spelstructen för spelets namn och betygen
    char game_n[GAME_N];
    int grade;
}Game;

typedef struct { //användarstructen för användarens namn, lösenord, antal spel som användaren har lagt in och en räknare 
    char name[USER_N];
    char user_pass[PASSWORD]; //måste vara med 
    Game gamearray[GAMEARR];
    int count;
}User;

void readData(User users[],int *pCount); //En funktion som läser in datan som användaren matar in 
void writeData(User users[], int *pCount); //En funktion som skriver ut den data som användaren har angett
void admin(User users[], int *pCount);          //admin
void adminlogin(User password[], int *pCount);  //admin
void search_player(User users[], Game gamearray[], int *pCount);  //admin // oklart med parametrana
void add_user(User users[], int *pCount);       //admin
void remove_user(User users[], int *pCount);    //admin
void print_users(User users[], int *pCount);    //admin
void print_all(User users[], int *pCount);      //admin
void player(User users[], Game gamearray[], int *pCount);  //spelare // oklart med parametrana
void print_game(Game gamearray[], int *pCount);         //spelare 
void add_game(Game gamearray[], int *pCount);           //spelare
void remove_game(Game gamearray[], int *pCount);        //spelare
void search_game(Game gamearray[], int *pCount);        //spelare


int main(){
    printf("Hej hej");
    // char filename[100];
    FILE *f;
    User users[MAX_USERS];
    Game gamearray[GAMEARR]; 
    int pCount = 0; //är detta rätt????
    char input[USER_N];
    char username;

    //startmenyn
    readData(users, &pCount); //läser data från filen
    while(1){
        printf("Please enter user name, admin or quit\n");
        scanf("%s", input);

        if(strcmp(input, "quit") == 0){
            writeData(users, &pCount); //skriver ut data till filen
            printf("Exiting program\n");
            return 0;
        }else if(strcmp(input, "admin") == 0){
            admin(users, &pCount); 
        }else{
            // search_player(users, gamearray, &pCount); //Detta bör göras i en funktion som returnerar
                                                      //true om användaren finns annars false (ska man använda bool?)
            scanf("%s", &username);

        for(int i = 0; i < pCount; i++){
        if(strcmp(users[i].name, &username)==0){
            player(users, gamearray, &pCount);
            break;
        }else{
            printf("There are no users in the system\n");
        }
    } 
        }
    }
}

void readData(User users[], int *pCount){
    printf("Hej hej");
    FILE *f = fopen("userdata.txt", "r");
    if(f == NULL){
        printf("Could not open the file\n");
        return;
    }
    //skriv något för att läsa antalet användare
    fscanf(f, "%d\n", pCount);
    for(int i = 0; i < *pCount; i++){
        fscanf(f, "%s\n", users[i].name);
        fscanf(f, "%s\n", users[i].user_pass);
        fscanf(f, "%d\n ", &users[i].count);
        for(int j = 0; j < users[i].count; j++){
            fscanf(f, "%s\n", users[i].gamearray[j]. game_n);
            fscanf(f, "%d\n", &users[i].gamearray[j].grade);
        }

    }
    fclose(f);
    printf("Hej Hej");
}

void writeData(User users[], int *pCount){
    FILE *f = fopen("userdata.txt", "w");
    if(f == NULL){
        printf("Could not open the file\n");
        return;
    }
    //skriv något för att skriva antalet användare
    fprintf(f, "%d\n", *pCount);
    for(int i = 0; i < *pCount; i++){
        fprintf(f, "%s\n", users[i].name);
        fprintf(f, "%s\n", users[i].user_pass);
        fprintf(f, "%d\n", users[i].count);
        for(int j = 0; j < users[i].count; j++){
            fprintf(f, "%s\n", users[i].gamearray[j].game_n);
            fprintf(f, "%d\n", users[i].gamearray[j].grade);
        }
    }


    fclose(f);
}

void search_player(User users[], Game gamearray[], int *pCount){ //kolla varningen i kompilatorn, vet inte hur parametrana ska vara 
    char username;
    
    printf("Please enter a username: \n");
    scanf("%s", &username);

    for(int i = 0; i < *pCount; i++){
        if(strcmp(users[i].name, &username)==0){
            player(users, gamearray, pCount);
            break;
        }else{
            printf("There are no users in the system\n");
        }
    }
}

void adminlogin(User password[], int *pCount){ //vet inte hur jag ska göra här sparar det till senare 

}

void player(User users[], Game gamearray[], int *pCount){ // oklart med parametrana
    int input;
    printf("Player meny\n");

    do{ // player meny
        printf("1. Print game: \n");
        printf("2. Add game: \n");
        printf("3. Search games: \n");
        printf("4. Remove games: \n");
        printf("5. Exit: \n");

        printf("Your choise: \n");
        scanf("%d", &input);

        switch(input){
            case 1: 
                print_game(gamearray, pCount); 
                break;
            case 2: 
                add_game(gamearray, pCount); 
                break;
            case 3: 
                search_game(gamearray, pCount); 
                break;
            case 4: 
                remove_game(gamearray, pCount); 
                break;
            case 5: 
                printf("Exiting user meny\n");
                return;
            default: 
                printf("Enter a valid value!\n"); 
                break;
        }
    }while(input != 5);
}

void print_game(Game gamearray[], int *pCount){ //väntar med den efter att jag har gjort de andra funktionerna 
    printf("_______________\n");
    if(pCount <= 0){
        printf("There are no games registered!\n");
    }else{
        for(int i=0; i<*pCount; i++){
            printf("Game: %s", gamearray[i].game_n);
            printf("Grade: %d", gamearray[i].grade);
        }
    }
}

void add_game(Game gamearray[], int *pCount){
    if(*pCount >= MAX_GAMES){
        printf("You have reached maximum limit of games!\n");
    }

    printf("Enter a game name: \n");
    scanf("%s", gamearray[*pCount].game_n);
    printf("Grade this game: \n");
    scanf("%d", &gamearray[*pCount].grade);

    // users[*pCount].count = 0; //måste jag göra samma här som med admin???
    // (*pCount)++;
    // return;
}

void remove_game(Game gamearray[], int *pCount){
    char game_name[GAME_N];
    printf("Please enter a game name: \n");
    scanf("%s", game_name);

    for(int i=0; i<*pCount; i++){
        if(strcmp(gamearray[i].game_n, game_name) == 0){
            for(int j=i; j < *pCount; j++){
                gamearray[j] = gamearray[j + 1];
            }
            (*pCount)--;
            printf("Game removed successfully!\n");
            return;
        }
    }
    printf("Game not found!\n");
}

void search_game(Game gamearray[], int *pCount){
    char game_name[GAME_N];
    printf("Please enter a game name: \n");
    scanf("%s", game_name);

    for(int i=0; i<*pCount; i++){
        if(strcmp(gamearray[i].game_n, game_name) == 0){
            printf("Game: %s", gamearray[i].game_n);
        }
    }
}

void admin(User users[], int *pCount){
    int input;
    printf("Administration\n");

    do{ //admin menyn
        printf("1. Add user: \n");
        printf("2. Remove User: \n");
        printf("3. Print all users: \n");
        printf("4. Print all users and all their ratings: \n");
        printf("5. Exit: \n");

        printf("Your choice: \n");
        scanf("%d", &input);

        switch (input){ // Allt verkar vara klart men det är något kink med antalet users när man tar bort eller lägger till spelare 
            case 1: add_user(users, pCount);
            break;
            case 2: remove_user(users, pCount);
            break;
            case 3: print_users(users, pCount);
            break;
            case 4: print_all(users, pCount); 
            break;
            case 5: printf("Exiting admin meny\n");
            return;
            default: printf("Invalid choise\n"); break;
        }
    }while(input != 5);
}

void add_user(User users[], int *pCount){ 
    if(*pCount >= MAX_USERS){ 
        printf("You have reached the maximum number of users!\n");
    }
    printf("Enter username: \n");  
    scanf("%s", users[*pCount].name);
    printf("Enter password: \n");
    // scanf("%s", users[*pCount].user_pass); // Ska lägga till lösen grejen sen 
    users[*pCount].count = 0;
    (*pCount)++;
    return;
}

void remove_user(User users[], int *pCount){ // det är något fel här (spelarstructen försvinner ej typ)
    char username[USER_N];
    printf("Please enter a username: \n");
    scanf("%s", username);

    for(int i = 0;  i < *pCount; i++){
        if(strcmp(users[i].name, username) == 0){
            for(int j = i; j < *pCount - 1; j++){
                users[j] = users[j + 1];
            }
            (*pCount)--;
            printf("User removed successfully!\n");
            return;
        }
    }
    printf("User not found\n");
}

void print_users(User users[], int *pCount){
    printf("____________________\n");

    if(pCount <= 0){
        printf("There are no users in the system:\n");
    }else{
        for(int i = 0; i < *pCount; i++){
            printf("User: %s\n", users[i].name);
        }
        printf("____________________\n");
        printf("\n");
    }
}

void print_all(User users[], int *pCount){
    if(pCount <= 0){
        printf("There are no players in the system:\n");
    }else{
        for(int i = 0; i < *pCount; i++){
            printf("User: %s\n", users[i]. name);
            for(int j = 0; j < users[i].count; j++){
                printf("Game: %s, Grade: %d\n", users[i].gamearray[j].game_n, users[i].gamearray[j].grade);
            }
        }
    }
}
