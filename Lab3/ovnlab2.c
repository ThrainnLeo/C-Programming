#include <stdio.h>
#include <string.h>

// Definierar konstanter för längd på olika strängar och maximalt antal bilar och våningar
#define MODELLEN 40
#define REGNUMMAX 6
#define MAXCARS 5
#define MAXFLOORS 3

// Färgkoder för terminalutskrifter
#define RED    "\e[31m"            // Felmeddelanden
#define GREEN  "\e[32m"            // Användarläge
#define YELLOW "\e[33m"            // Rubriker
#define BLUE   "\e[34m"            // Admin-läge
#define PURPLE "\e[35m"            // Debug-meddelanden
#define CYAN   "\e[36m"            // Reserv
#define GREY   "\e[37m"            // Informationsmeddelanden
#define WHITE  "\e[0m"             // Återställ till vitt

// Definierar en struktur för att representera en bil
typedef struct {
    char manufacturer[MODELLEN];    // Tillverkarens namn
    char modelname[MODELLEN];       // Modellnamn
    char regnum[REGNUMMAX];         // Registreringsnummer
    int horsepower;                 // Hästkrafter
    int buildyear;                  // Byggår
} Car;

// Definierar en struktur för att representera en våning i garaget
typedef struct {
    Car cars[MAXCARS];              // Array av bilar på denna våning
    int carcount;                   // Antal bilar på denna våning
} Floor;

// Funktioner som används i programmet
void addCar(Floor garage[], int currentFloor);
void viewCar(Floor garage[], int currentFloor);
void bubbleSort(Car garage[], int carcount);
void printCar(Car garage[], int i);
void searchCar(Floor garage[], int currentFloor);
int NEWsearch (Car garage[], int searchmode, int carcount);
void removeCar(Floor garage[], int currentFloor);

int main(void) {
    printf("\nWelcome to the car database!\n");

    int menuchoice;                 // Variabel för att lagra användarens menyval
    int floorChoice = 0;            // Variabel för att lagra vald våning

    Floor garage[MAXFLOORS];        // Skapar ett garage med flera våningar

    // Initialiserar bilräknare för varje våning till 0
    for (int i = 0; i < MAXFLOORS; i++) {
        garage[i].carcount = 0;
    }

    printf("Entering the main menu:\n");

    // Huvudmenyn loop
    do {
        printf("====Main Menu====\n");
        printf("1: Select floor\n");
        printf("2: Add car\n");
        printf("3: View cars\n");
        printf("4: Search for car\n");
        printf("5: Remove car\n");
        printf("6: Quit\n");

        printf("Your choice : ");
        scanf(" %d", &menuchoice);

        switch (menuchoice) {
            // Välj våning
            case 1:
                printf("Select floor (0-%d): ", MAXFLOORS - 1);
                scanf(" %d", &floorChoice);
                if (floorChoice < 0 || floorChoice >= MAXFLOORS) {
                    printf("Invalid floor choice!\n");
                    floorChoice = 0;
                }
                break;
            // Lägg till bil
            case 2: addCar(garage, floorChoice); break;
            // Visa bilar
            case 3: viewCar(garage, floorChoice); break;
            // Sök efter bil
            case 4: searchCar(garage, floorChoice); break;
            // Ta bort bil
            case 5: removeCar(garage, floorChoice); break;
            // Avsluta programmet
            case 6: printf("Exiting program\nBye!\n"); return 0;
            // Hantera ogiltiga val
            default: printf("Invalid Choice!\n");
        }
    } while (menuchoice != 6);

    return 0;
}

// Funktion för att lägga till en bil i garaget
void addCar(Floor garage[], int currentFloor) {
    printf("\n====Add Car Menu====\n");

    char addmorecars; // Variabel för att avgöra om användaren vill lägga till fler bilar

    do {
        // Kontrollera om våningen är full
        if (garage[currentFloor].carcount >= MAXCARS) {
            printf("%sThe garage on floor %d is full!\n%s", RED, currentFloor, WHITE);
            return;
        }

        // Läs in bilens detaljer från användaren
        printf("What is the manufacturers name? : ");
        scanf("%s", garage[currentFloor].cars[garage[currentFloor].carcount].manufacturer);
        printf("What is the model name? : ");
        scanf("%s", garage[currentFloor].cars[garage[currentFloor].carcount].modelname);
        printf("How much horsepower does the car have? : ");
        scanf("%d", &garage[currentFloor].cars[garage[currentFloor].carcount].horsepower);
        printf("What year was the car built? : ");
        scanf("%d", &garage[currentFloor].cars[garage[currentFloor].carcount].buildyear);
        printf("What is the cars registration plate? (Ex. ABC123) : ");
        scanf("%s", garage[currentFloor].cars[garage[currentFloor].carcount].regnum);

        // Öka antalet bilar på denna våning
        garage[currentFloor].carcount++;

        // Fråga användaren om de vill lägga till en till bil
        printf("\nWould you like to add another car? You have %d cars left to add on floor %d!\n", (MAXCARS - garage[currentFloor].carcount), currentFloor);
        printf("Yes(y), No(n) : ");
        scanf(" %c", &addmorecars);

    } while (addmorecars == 'y' || addmorecars == 'Y');
}

// Funktion för att visa alla bilar på en våning
void viewCar(Floor garage[], int currentFloor) {
    printf("\n====Car View Menu====\n");

    // Kontrollera om det finns några bilar att visa
    if (garage[currentFloor].carcount < 1) {
        printf("%sThere are no cars to view on floor %d!%s\n", RED, currentFloor, WHITE);
        return;
    }

    // Sortera bilarna innan de visas
    bubbleSort(garage[currentFloor].cars, garage[currentFloor].carcount);

    // Visa varje bil
    for (int i = 0; i < garage[currentFloor].carcount; i++) {
        printf("Info for Car %d:\n", i + 1);
        printCar(garage[currentFloor].cars, i);
    }
}

// Funktion för att sortera bilarna i alfabetisk ordning efter tillverkarens namn
void bubbleSort(Car garage[], int carcount) {
    Car tmpCar; // Temporär bilvariabel för att byta plats på bilar

    // Bubble sort-algoritmen
    for (int times = 0; times < carcount; times++)
        for (int i = 0; i < carcount - 1 - times; i++)
            if (strcmp(garage[i].manufacturer, garage[i + 1].manufacturer) > 0) {
                tmpCar = garage[i];
                garage[i] = garage[i + 1];
                garage[i + 1] = tmpCar;
            }
}

// Funktion för att skriva ut information om en bil
void printCar(Car garage[], int i) {
    printf("    Manufacturer is %s.\n", garage[i].manufacturer);
    printf("    Model name is %s.\n", garage[i].modelname);
    printf("    Amount of horsepower is %d.\n", garage[i].horsepower);
    printf("    Build year is %d.\n", garage[i].buildyear);
    printf("    The registration number is %s.\n", garage[i].regnum);
    printf("--------------\n");
}

// Funktion för att söka efter en bil på en våning
void searchCar(Floor garage[], int currentFloor) {
    printf("\n====Car Search Menu====\n");

    char searchcar_again; // Variabel för att avgöra om användaren vill söka efter fler bilar

    do {
        // Kontrollera om det finns några bilar att söka efter
        if (garage[currentFloor].carcount < 1) {
            printf("%sThere are no cars to search for on floor %d!\n%s", RED, currentFloor, WHITE);
            break;
        }

        // Anropa sökfunktionen
        NEWsearch(garage[currentFloor].cars, 1, garage[currentFloor].carcount);

        // Fråga användaren om de vill söka efter en till bil
        printf("Do you want to search again? Yes(y), No(n) : ");
        scanf(" %c", &searchcar_again);
    } while (searchcar_again == 'y' || searchcar_again == 'Y');
}

// Funktion för att söka efter en bil baserat på registreringsnummer
int NEWsearch(Car garage[], int searchmode, int carcount) {
    int carsfound; // Räknare för hittade bilar
    int carindex;  // Index för den hittade bilen

    char userchoice[REGNUMMAX]; // Användarens söksträng

    do {
        carindex = -1;
        carsfound = 0;

        // Läs in användarens söksträng
        printf("Search for a car: ");
        scanf("%s", userchoice);

        // Gå igenom alla bilar och jämför registreringsnummer
        for (int i = 0; i < carcount; i++) {
            if (strstr(garage[i].regnum, userchoice)) {
                carsfound++;
                printCar(garage, i);
                carindex = i;
            }
        }

        // Kontrollera om fler än en bil hittades och om användaren måste söka igen
        if (carsfound > 1 && searchmode == 0) {
            printf("You did not find one unique car! %d cars found.\n", carsfound);
        }

        if (carsfound < 1) {
            printf("No cars found!\n");
        }

    } while (carsfound > 1 && searchmode == 0);

    return carindex;
}

// Funktion för att ta bort en bil från garaget
void removeCar(Floor garage[], int currentFloor) {
    printf("\n====Delete Car Menu====\n");

    char deletecar_again; // Variabel för att avgöra om användaren vill ta bort fler bilar
    char deletecar_userchoice; // Variabel för att lagra användarens val att ta bort bil

    do {
        // Kontrollera om det finns några bilar att ta bort
        if (garage[currentFloor].carcount < 1) {
            printf("%sThere are no cars to delete on floor %d!\n%s", RED, currentFloor, WHITE);
            break;
        }

        // Anropa sökfunktionen för att hitta bilen att ta bort
        int index = NEWsearch(garage[currentFloor].cars, 0, garage[currentFloor].carcount);

        if (index == -1) break;

        // Bekräfta borttagningen med användaren
        printf("Do you want to delete the car with registration %s?\n", garage[currentFloor].cars[index].regnum);
        printf("Yes (y) or No (n): ");
        scanf(" %c", &deletecar_userchoice);

        if (deletecar_userchoice == 'n' || deletecar_userchoice == 'N') {
            printf("Car not deleted.\n");
            break;
        } else {
            // Flytta alla bilar efter den borttagna bilen en position framåt
            for (int i = index; i < garage[currentFloor].carcount - 1; i++) {
                garage[currentFloor].cars[i] = garage[currentFloor].cars[i + 1];
            }
            // Minska antalet bilar på denna våning
            garage[currentFloor].carcount--;
            printf("Car removed\n");
            break;
        }

        // Fråga användaren om de vill ta bort fler bilar
        printf("Do you want to delete more cars? Yes(y)/No(n) : ");
        scanf(" %c", &deletecar_again);
    } while (deletecar_again == 'y' || deletecar_again == 'Y');
}
