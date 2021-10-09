#include <stdio.h>

int main (void){
    int prime[] = {};
    int result = 0; 
    int input = 0; 
    int sum = 0; 
    int count = 0;
    
    //Prompt user to enter prime numbers
    printf("Please, enter prime numbers ONLY:\n");
    
    //Put everything into array
    for(int loop = 0; (result = scanf("%d", &input)) != EOF; loop++){
        prime[loop] = input;
        count++;
    }
    
    //Print test 
    for(int loop = 0; loop < count; loop++){
            printf("%d", prime[loop]);
    }
    
    //Get sum of everything in the array
    for(int loop = 0; loop < count; loop++){
        sum += prime[loop];
    }
    
    //Print sum
    printf("The sum is %d", sum);
    
}