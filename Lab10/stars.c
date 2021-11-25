/* 
 *  stars.c
 *
 *  Description: Prints rows of stars with size in ascending order until it reaches max, where it prints rows in descending size order
 *
 *  Author: Darren Fok and Anushka Kulesakara
 *  Date: December 1st, 2021
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
