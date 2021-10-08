#include <stdio.h>

int main (void){
    
    int result = 0; 
    int array[80] = {};
    int max = 0; //stores the maximum height
    int input = 0; 
    int count = 0; //counts how many values are inputted
    int loop = 0;
    
    //Prompt user to input 80 values.
    printf("Please, input 80 or less values.\n");
    
    //Allow input until user inputs ctrl+d, however cannot exceed 80.
    /*for(int loop = 0; (result = scanf("%d", &input)) != EOF; loop++){
        if(loop >= 80){
            printf("Sorry, you cannot input more than 80 values.");
        }
        else{
            array[loop] = input;
            count++;
        }
    }*/
    
    while((result = scanf("%d", &input)) != EOF && loop < 80){
        array[loop] = input;
        count++;
        loop++;
    }    
    
    printf("\n");
        
    //Find maximum value input (also maximum height of a column)
    for(int loop = 0; loop < count; loop++){
        if (array[loop] > max){
            max = array[loop];
        }
    }
    
    //Flips printed graphic upside down
    for(int loop = 0; loop < count; loop++){
        array[loop] = max-array[loop];
    }
    
    //Print the graphic
    for(int loop = 0; loop < max; loop++){ //deals with the height
        for(int loop2 = 0; loop2 < count; loop2++){ //deals with the width
            if(array[loop2] > 0){
                printf(" ");
            }
            else if(array[loop2] <= 0){
                printf("#");
            }
        }
        printf("\n");
        for(int loop2 = 0; loop2 < count; loop2++){
            array[loop2]--;
        }
    }
    return 0;
}

