#include <stdio.h>
#define PI 3.1415
int main(int argc, char **arvg){
    
    int r = 10;
    printf("Km per hour to miles per seconds\n");
    printf("Sphere r=%dcm have V = %-6.2fcm3\n", r,3*PI*r*r*r/4);
    
    printf("Program completed, Bye!\n");
    return 0;
}