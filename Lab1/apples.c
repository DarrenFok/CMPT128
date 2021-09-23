#include <stdio.h> 
#include <math.h>

int main (void) {
    //Fields
    int numApples = 0; //Total number of apples
    int inEachBag = 0; //Amount of apples in each bag
    int bagsProduced = 0;
    int leftOver = 0;
    int result = 0; 

    //Prompt user to input amount of apples then amount in each bag
    printf("Please, enter the number of apples available and the numbers of apples each bag holds: \n");

    while ((result = scanf("%d %d", &numApples, &inEachBag)) != EOF){
        //Print number of apples and amount in each bag to user
        printf("Number of apples available => %d, number of apples each bag holds => %d.\n", numApples, inEachBag);

        //Calculate amount of bags
        bagsProduced = floor(numApples / inEachBag);

        //Calculate amount of leftovers
        leftOver = floor(numApples % inEachBag);

        //Print results
        printf("Number of bags produced => %d, number of apples left over => %d.\n", bagsProduced, leftOver);

        printf("Please, enter the number of apples available and the numbers of apples each bag holds: \n");
    }

    printf("Done.\n");
    return 0; 
}
    