/* Detta är en lab som heter bilgrage
    -Det ska fungera som ett bibliotek av bilar
    -Du har tre våningar som du kodar med hjälp av två structar
    -En struct ska vara info och den andra ska vara struct av en struct (också med info)
    -*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 30
#define PLATE_MAX 7
#define MAX_CAR 5
#define MAX_FLOORNAME 30
#define MAX_FLOOR 3

typedef struct{
    char name[NAME_MAX];
    char plate[PLATE_MAX];
    int price;
}car;

typedef struct{
    car cararray[MAX_CAR];
    int car_count;
    char floor_name[MAX_FLOORNAME];
}floor;

void add_car(floor *current_floor);
void remove_car(floor floorarray[], int *floor_count);
void add_floor(floor floorarray[], int *floor_count);
void remove_floor(floor floorarray[], int *floor_count);
void show_info(floor floorarray[], int floor_count);

int main(){
    floor floorarray[MAX_FLOOR];
    int current_floor;
    int floor_count = 0;
    int input;
    

 printf("_____Startmeny_____\n");
        printf("1. Add a floor\n");
        printf("2. Remove a floor\n");
        printf("3. Add a car\n");
        printf("4. Remove a car\n");
        printf("5. Show all info\n"); 
        printf("6. Exit\n");
    //stratmeny
    do{
        printf("Choose something on the startmeny\n");
        scanf("%d", &input);
        
        switch(input){
        case 1: add_floor(floorarray, &floor_count);
        break;
        case 2: remove_floor(floorarray, &floor_count);
        break;
        case 3: add_car(&floorarray[current_floor]);
        break;
        case 4: remove_car(floorarray, &floor_count);
        break;
        case 5: show_info(floorarray, floor_count); 
        break;
        case 6: printf("Exiting program\n");
        break;
        default: printf("Enter a valid number\n");
    }
    } while(input == 6);

}

void add_floor(floor floorarray[], int *floor_count){
    char floor_name[MAX_FLOORNAME];
     while(1){
        printf("Please enter a floor (press q to quit)\n");
        scanf("%s", floorarray->floor_name);
        floor_count++;
        if(*floor_count >= MAX_FLOOR){
            printf("Maximum number of floors reached\n");
        }else {
            printf("Enter floor name (press q to quit)");
            // char floor_names[MAX_FLOORNAME];
            scanf("%s", floor_name);

            if(strcmp(floor_name, "q")==0){
                break;
            }
        }
        int exists = 0;
        for(int i = 0; i < *floor_count; i++){
            if(strcmp(floorarray[i].floor_name,floor_name)==0){
                exists = 1;
                break; 
            }
        }
        if(exists){
            printf("This floor name alredy exists\n");
        } else{
            strcpy(floorarray[*floor_count].floor_name, floor_name);
            floorarray[*floor_count].car_count = 0;
            floor_count++;
            printf("Floor added successfully\n");
        }
    }
}

void remove_floor(floor floorarray[], int *floor_count){
    printf("____Remove floor meny\n");
    if(*floor_count == 0){
        printf("No floors to remove\n");
        return;
    }

    printf("Pleaes enter a floor index to remove (0 to %d)\n", *floor_count - 1);
    int index;
    scanf("%d", &index);

    if(index < 0 || index >= *floor_count){
        printf("This is a invalid floor index\n");
        return;
    }

    for(int i = index; i < *floor_count - 1; i++){
        floorarray[i] = floorarray[i + 1];
    }
    (*floor_count)--;
    printf("Floor removed\n");

    printf("Return\n");
}

void add_car(floor *current_floor){
    printf("____Add car meny____\n");

    if(current_floor -> car_count >= MAX_CAR){
        printf("The floor has reached the maximum number of cars\n");
        return;
    }
    car *new_car = &current_floor ->cararray[current_floor -> car_count];

    printf("Enter the brand: \n");
    scanf("%s", new_car -> name);
    printf("Enter the plate number: \n");
    scanf("%s", new_car -> plate);
    printf("Enter the price: \n");
    scanf("%d", &new_car -> price);

    current_floor -> car_count++;
    printf("The car was added successfully\n");
}

void remove_car(floor floorarray[], int *floor_count){
    printf("____Remove car meny____\n");

    char delete_car_again; // inte färdig 
    char delete_car;

    do{
        if(*floor_count<1){
            printf("There are no cars to remove\n");
            break;
        }
    } while(delete_car_again == 'y' || delete_car_again == 'Y');
}

void show_info(floor floorarray[], int floor_count){
    if(floor_count == 0){
        printf("There are no floors to show\n");
        return;
    }

    for(int i = 0; i < floor_count; i++){
        printf("Floor %d: %s\n", i, floorarray[i].floor_name);
        printf("Number of cars: %d\n", floorarray[i].car_count);

        for(int j = 0; j < floorarray[i].car_count; j++){
            car current_car = floorarray[i].cararray[j];
            printf("    Car %d: \n", j);
            printf("    Brand: %s\n", current_car.name);
            printf("    Plate: %s\n", current_car.plate);
            printf("    Price: %d\n", current_car.price);
        }
        printf("\n");
    }
}