#include <stdio.h>
#include <math.h>
#define VALUES 10


void view(int storage[], int size);
void enter(int storage[], int size, int *pSpot);
void compute(int storage[], int calc);
void reset(int storage[], int size, int *pSpot);
int minV(int storage[], int calc);
int maxV (int storage[], int calc);
float avrV (int storage[], int calc);
void normA(int storage[], int normV[], int calc);


int main (void){

    char input = 'q';
    int pSpot = 0;
    int num[VALUES] = {0};

    printf("Measurment tool\n");
    printf("VECRQ\n : x");
    printf("Please use:\n v to View\n e to Enter\n c to Compute\n r to Reset\n q to Quit\n");

    do{
        scanf("%c", &input);
        switch (input){
            case 'v': view(num, VALUES); break;
            case 'e': enter(num, VALUES, &pSpot); break;
            case 'c': compute(num, pSpot); break;
            case 'r': reset(num, VALUES, &pSpot); break;
            case 'q': break;
            default  : printf("Please use:\n v to View\n e to Enter\n c to Compute\n r to Reset\n q to Quit\n"); break;
        }
    }while(input!='q');
}

void view(int storage[], int size){

}
void enter(int storage[], int size, int *pSpot){
    for(int i = *pSpot; i < size; i++){
        printf("Enter messurment #%d: ", i + 1);
        scanf("%d", &storage[i]);
        (*pSpot)++;
        if(storage[i]==0){
            (*pSpot)--;
            break;
        }
    }

}
void compute(int storage[], int calc){
    if (calc > 0){
        int normV[calc]; 
        normA(storage, normV, calc);
        printf("Max value: %d\n", maxV(storage, calc));
        printf("Min value: %d\n", minV(storage, calc));
        printf("Avrage value: %.2f\n", avrV(storage, calc));
        view(storage, calc);
    }else{
        printf("There is no data to compute\n");
    }
    return;
}
void reset(int storage[], int size, int *pSpot){
    for(int i = 0; i < size; i++){
        storage[i]=0;
    }
    *pSpot = 0;
    printf("Reset!\n");
}

int minV(int storage[], int calc){
    int min;
    min = storage[0];
    for(int i = 1; i < calc; i++){
        if (storage[i] < min){
            min = storage[i];
        }
    }
    return min;
}

int maxV (int storage[], int calc){
    int max;
    max = storage[0];
    for(int i = 1; i < calc; i++){
        if(storage[i] > max){
            max = storage[i];
        }
    }
    return max;
}

float avrV (int storage[], int calc){
    int sum = 0;
    float avr;
    for(int i = 0; i < calc; i++){
        sum += storage[i];
    }
    avr = sum/calc;
    return avr;
}

void normA(int storage[], int normV[], int calc){
    for(int i = 0; i < calc; i++){
        normV[i] = round(storage[i] - avrV(storage, calc));
    }
    return;
}

