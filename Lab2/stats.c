/*
 * Filename: stats.c
 * 
 * Description: Takes inputted numbers, and outputs minimum, maximum and mean numbers.
 * Author: Darren Fok
 * Date: September 30th, 2021
 */

#include <stdio.h>

int main()
{
    //Fields
    float result = 0;
    float input = 0; 
    float sum = 0;
    double average = 0;
    
    int number = 0;
    double min = 0;
    double max = 0;
    
    int loop = 0; 
    
    //Ask user for input
    printf("Please, enter a number between -100000.00 and 100000.00: ");
    
    //Keep asking user to input number until ctrl+d 
    while((result = scanf("%f", &input)) != EOF){
        //Boundaries for numbers they can input
        if(input >= 100000.00 || input <= -100000.00){
            printf("%f is invalid!", input);
        }
        else{
            //Start with first number as max and min
            if(number == 0){
                min = input;
                max = input;
            }
            //Check if input is the new minimum
            else if(input < min){
                min = input;
            }
            //Check if input is the new maximum
            else if(input > max){
                max = input;
            }
            
            //Add to sum
            sum += input;
            
            number++;
            
            //Ask user for input again
            printf("Please, enter a number between -100000.00 and 100000.00: ");
        }
    }
    //When they hit ctrl+d, break the loop and get the average
    average = sum / number;
    
    //Print out the minimum, maximum and the average
    printf("\nMin: %g, max: %g, mean: %g", min, max, average);
    
    return 0;
}

