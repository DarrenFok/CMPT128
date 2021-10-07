/*
 * Filename: pyramid.c
 * 
 * Description: Takes inputted width, breath, and height and prints out a pyramid graphic.
 * 
 * Author: Darren Fok
 * Date: October 6th, 2021
 */
#include <stdio.h>

int main ( void ){
    int int1;
    int int2;
    int int3;
    int firstRow;
    int height;
    int width;
    int lastRow;
    
    
    printf("Please, type 3 integers and press ENTER: ");
    scanf("%d %d %d", &int1, &int2, &int3);
    
    //First row 
    for(firstRow = 0; firstRow < int1; firstRow++){
        printf("#");
    }
    
    printf("\n");
    
    //Middle rows
    for(height = 0; height < int2-2; height++){
        printf("#");
        for(width = 0; width < int1-2; width++){
            printf(".");
        }
        printf("#\n");
    }
    
    //Last rows
    for(lastRow = 0; lastRow < int1; lastRow++){
        printf("#");
    }
}