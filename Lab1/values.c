#include <stdio.h>
#include <math.h>

//reads floating point and rounds it to ceil, floor and round.

int main (void) {
    //Fields
    double value = 0.0; 
    double result1;
    double result2;
    double result3;

    //Ask for user input
    printf("Please enter your number... ");

    //Allow for user input
    scanf("%le", &value);

    //Round numbers with ceil, floor, round
    result1 = ceil(value);
    result2 = floor(value);
    result3 = round(value);

    //Print our results
    printf("The ceil value of %f is %f\n", value, result1);
    printf("The floor value of %f is %f\n", value, result2);
    printf("The round value of %f is %f\n", value, result3);

    return 0; 
}