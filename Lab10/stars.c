/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/* 
 *  stars.c
 *
 *  Description: 
 *
 *  Author: 
 *  Date: 
 */

#include <stdio.h> 

void stars( unsigned int current, unsigned int max ) {

    // Base case
    if(current > max){
        return;
    }
    // Recursive case
    else{
        for(unsigned int i = 1; i <= current; i++){
            printf("*");
        }
        printf("\n");
        
        stars(current+1, max);
        
        for(int j = 1; j <= current; j++){
            printf("*");
        }
        printf("\n");
    }

}

int main( void ) {

    unsigned int start = 0, max = 0;  

    printf( "How many stars should we start with?  " );
    scanf("%d", &start );
    printf( "What is the maximum number of stars we should print? " );
    scanf("%d", &max );
    stars( start, max );

    return 0;
}
