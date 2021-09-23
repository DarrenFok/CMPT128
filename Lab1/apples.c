/*
 * Filename: apples.c
 * 
 * Description: Takes inputted amount of apples and amount of apples in each bag and outputs how many bags and leftover apples there would be.
 * 
 * Author: Darren Fok
 * Date: September 23rd, 2021
 */

#include <stdio.h> 
#include <math.h>

int main (void) {
    //Fields
    int numApples = 0; //Total number of apples
    int inEachBag = 0; //Amount of apples in each bag
    int bagsProduced = 0; //Number of bags
    int leftOver = 0; //Number of leftovers
    int result = 0; 

    //Prompt user to input amount of apples then amount in each bag
    printf("Please, enter the number of apples available and the numbers of apples each bag holds: \n");

    //Allow for user input and loop process as long as user input is not ctrl+d
    while ((result = scanf("%d %d", &numApples, &inEachBag)) != EOF){
        //Print number of apples and amount in each bag to user
        printf("Number of apples available => %d, number of apples each bag holds => %d.\n", numApples, inEachBag);

        //Calculate amount of bags
        bagsProduced = floor(numApples / inEachBag);

        //Calculate amount of leftovers
        leftOver = floor(numApples % inEachBag);

        //Print results
        printf("Number of bags produced => %d, number of apples left over => %d.\n", bagsProduced, leftOver);

        //Prompt user to input amount of apples then amount in each bag (included in loop)
        printf("Please, enter the number of apples available and the numbers of apples each bag holds: \n");
    }

    //Print "Done."
    printf("Done.\n");
    return 0; 
}
    