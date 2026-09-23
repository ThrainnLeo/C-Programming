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

typedef struct{
    char game_n[GAME_N];
    int grade;
}Game;

typedef struct {  
    char name[USER_N];
    char user_pass[PASSWORD];  
    Game gamearray[GAMEARR];
    int count;
}User;

void readData(User users[],int *pCount, char filename[]); //En funktion som läser in datan som användaren matar in 
void writeData(User users[], int *pCount, char filename[]); //En funktion som skriver ut den data som användaren har angett
void admin(User users[], int *pCount);          //admin
void userlogin(User password[], int *pCount);  //admin
void search_player(User users[], Game gamearray[], int *pCount);  //admin // oklart med parametrana
void add_user(User users[], int *pCount);       //admin
void remove_user(User users[], int *pCount);    //admin
void print_users(User users[], int *pCount);    //admin
void print_all(User users[], int *pCount);      //admin
void player(User *users);                        //spelare 
void print_game(User users);                    //spelare 
void add_game(User *users);                     //spelare
void remove_game(User *users, int *count);       //spelare
void search_game(User users, int count);        //spelare
void sort(User *users);                         //spelare


int main(){
    char filename[100];
    FILE *f;
    User users[MAX_USERS];
    Game gamearray[GAMEARR]; 
    int pCount = 0;
    char input[USER_N];
    char username;

    printf("Welcome to boardgame rating\n");
    printf("Witch file do you want to use: ");
    scanf("%s", filename);

    //startmenyn
    readData(users, &pCount, filename); //läser data från filen
    while(1){
        printf("Please enter user name, admin or quit\n");
        scanf("%s", input);

        if(strcmp(input, "quit") == 0){
            writeData(users, &pCount, filename); //skriver ut data till filen
            printf("Exiting program, saving files to %s.\n", filename);
            return 0;
        }else if(strcmp(input, "admin") == 0){
            admin(users, &pCount);
        }else{
            userlogin(users, &pCount);

        }
    }
}

void readData(User users[], int *pCount, char filename[]){
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        printf("Could not open the file\n");
        return;
    }
    //skriv något för att läsa antalet användare
    fscanf(f, "%d:", pCount);
    for(int i = 0; i < *pCount; i++){
        fscanf(f, "%s  %s\n", users[i].name, users[i].user_pass);
        fscanf(f, "%d\n ", &users[i].count);
        for(int j = 0; j < users[i].count; j++){
            fscanf(f, "%s  %d\n", users[i].gamearray[j].game_n,&users[i].gamearray[j].grade);
        }
        fscanf(f,"\n");

    }
    fclose(f);
}

void writeData(User users[], int *pCount, char filename[]){
    FILE *f = fopen(filename, "w");
    // if(f == NULL){
    //     printf("Could not open the file\n");
    //     return;
    // }
    //skriv något för att skriva antalet användare
    fprintf(f, "%d\n ", *pCount);
    for(int i = 0; i < *pCount; i++){
        fprintf(f, "%s  %s\n", users[i].name, users[i].user_pass);
        fprintf(f, "%d\n", users[i].count);
        for(int j = 0; j < users[i].count; j++){
            fprintf(f, "%10s  %-5d\n", users[i].gamearray[j].game_n,users[i].gamearray[j].grade);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

void search_player(User users[], Game gamearray[], int *pCount){ 
    char username;
    
    printf("Please enter a username: \n");
    scanf("%s", &username);

    for(int i = 0; i < *pCount; i++){
        if(strcmp(users[i].name, &username)==0){
            player(&users[i]);
            break;
        }else{
            printf("There are no users in the system\n");
        }
    }
}

void userlogin(User users[], int *pCount){
    char username[USER_N];
    char password[PASSWORD];
    int i;
    
    printf("Enter a password: \n");
    scanf("%s", password);

    for(i = 0; i < *pCount; i++){
        if( strcmp(users[i].user_pass, password) == 0){
            player(&users[i]);
            return;
        }
    }
    printf("wrong password!\n");
}

void player(User *users){
    int input;

    printf("Player meny\n");
    printf("_________________________________\n");

    do{
        printf("    1) Print game: \n");
        printf("    2) Add game: \n");
        printf("    3) Search games: \n");
        printf("    4) Remove games: \n");
        printf("    5) sort games: \n");
        printf("    6) Exit: \n");

        printf("Your choise: \n");
        scanf("%d", &input);

        switch(input){
            case 1: 
                print_game(*users); 
                break;
            case 2: 
                add_game(users); 
                break;
            case 3: 
                search_game(*users, users->count); 
                break;
            case 4: 
                remove_game(users, &users->count); 
                break;
            case 5:
                sort(users);
                break;
            case 6: 
                printf("Exiting user meny\n");
                return;
            default: 
                printf("Enter a valid value!\n"); 
                break;
        }
    }while(input != 6);
}

void print_game(User users){ 
    printf("____________________________________________\n");
    if(users.count <= 0){
        printf("There are no games registered!\n");
    }else{
        printf(" %s\n", users.name);
        for(int i = 0; i < users.count; i++){
            printf("        %-10s", users.gamearray[i].game_n);
            printf("                 %5d", users.gamearray[i].grade);
            printf("\n");
        }
    }
    printf("____________________________________________\n");
}

void add_game(User *users){
    if(users->count >= MAX_GAMES){
        printf("You have reached maximum limit of games!\n");
        return;
    }
    do{
        printf("Enter a game name: \n");
        scanf("%s", users->gamearray[users->count].game_n);
        printf("Rating (1 - 10): \n");
        scanf("%d", &users->gamearray[users->count].grade);
        if(users->gamearray[users->count].grade < 1 || users->gamearray[users->count].grade > 10){
            printf("Enter a valid grade between 1 and 10\n");
        }
    }while(users->gamearray[users->count].grade < 1 || users->gamearray[users->count].grade>10);
    users->count++;
}

void remove_game(User *users, int *pCount){
    Game gamearray[MAX_GAMES];
    char game_name[GAME_N];

    printf("Please enter a game name: \n");
    scanf("%s", game_name);

    for(int i = 0; i < *pCount; i++){
        if(strcmp(users->gamearray[i].game_n, game_name) == 0){
            for(int j = i; j < *pCount - 1; j++){
                users->gamearray[j] = users->gamearray[j + 1];
            }
            (*pCount)--;
            printf("Game removed successfully!\n");
            printf("\n");
            return;
        }else{
            printf("Game not found!\n");

        }
    }
}

void search_game(User users, int count){
    Game gamearray[MAX_GAMES];
    char game_name[GAME_N];

    printf("Please enter a game name: \n");
    scanf("%s", game_name);
    printf("______________________________________\n");

    for(int i=0; i < count; i++){
        if(strcmp(users.gamearray[i].game_n, game_name) == 0){
            printf("%s      %d\n", users.gamearray[i].game_n, users.gamearray[i].grade);
            return;
        }
    }
    printf("Game not found!\n");
    printf("\n");
}

void sort(User *users){ //måste ta bort spelar menyn när den frågar om hur den ska sortera 
    char input;

    printf("Do you want to sort games by name or grade? (n/g)\n");
    scanf(" %c", &input);

    if(input == 'n'){
        for(int i=0; i < users->count - 1; i++){
            for(int j = i + 1; j < users->count; j++){
                if(strcmp(users->gamearray[i].game_n, users->gamearray[j].game_n) > 0){
                    Game temp = users->gamearray[j];
                    users->gamearray[i] = users->gamearray[j];
                    users->gamearray[j] = temp;
                }
            }
        }
    }else if(input == 'g'){
        for(int i=0; i<users->count - 1; i++){
            for(int j=i; j<users->count; j++){
                if(users->gamearray[i].grade < users->gamearray[j].grade){
                    Game temp = users->gamearray[i];
                    users->gamearray[i] = users->gamearray[j];
                    users->gamearray[j] = temp;
                }
            }
        }
    }
}

void admin(User users[], int *pCount){
    int input;
    printf("Administration\n");
    printf("_____________________________________________\n");

    do{ //admin menyn
        printf("    1) Add user \n");
        printf("    2) Remove User \n");
        printf("    3) Print all users \n");
        printf("    4) Print all users and all their ratings \n");
        printf("    5) Exit \n");

        printf("Your choice: \n");
        scanf("%d", &input);

        switch (input){ 
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
        return;
    }
    printf("Enter username: \n");  
    scanf("%s", users[*pCount].name);
    printf("Enter password: \n");
    scanf("%s", users[*pCount].user_pass);

    users[*pCount].count = 0;
    (*pCount)++;
    return;
}

void remove_user(User users[], int *pCount){ // Det ska finnas en varning innan användaren raderar spelare!!!!
    char username[USER_N];
    char confirm;

    printf("Please enter a username: \n");
    scanf("%s", username);

    for(int i = 0;  i < *pCount; i++){
        if(strcmp(users[i].name, username) == 0){
            printf("Are you sure you want to remove this player (y/n)?\n");
            scanf(" %c", &confirm);
            if(confirm == 'y' || confirm == 'Y'){
                for(int j = i; j < *pCount - 1; j++){
                    users[j] = users[j + 1];
                }
                (*pCount)--;
                printf("User removed\n");
                printf("\n");
            }else{
                printf("User removal cancelled!\n");
            }
            return;
        }
    }
    printf("User not found\n");

}
void print_users(User users[], int *pCount){
    printf("Users:\n");
    printf("____________________\n");

    if(*pCount <= 0){
        printf("There are no users registrered:\n");
    }else{
        for(int i = 0; i < *pCount; i++){
            printf(" %s\n", users[i].name);
        }
        printf("____________________\n");
        printf("\n");
    }
}

void print_all(User users[], int *pCount){ //den printar inte spel och betyg!!!!!! 
    if(*pCount <= 0){
        printf("There are no players in the system:\n");
    }else{
        printf("Users and boardgames:\n");
        printf("_________________________________\n");
        for(int i = 0; i < *pCount; i++){
            printf(" %s\n", users[i].name);
            for(int j = 0; j < users[i].count; j++){
                printf("    %-10s", users[i].gamearray[j].game_n);
                printf("            %5d\n", users[i].gamearray[j].grade);
            }
        }
    }
    printf("_________________________________\n");
}