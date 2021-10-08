/*
 * Filename: scrambled.c
 * 
 * Description: Takes two arrays and one integer that indicates size, compares them, and determines whether they have the same contents or not.
 * 
 * Author: Darren Fok
 * Date: October 8th, 2021
 */

#include <stdio.h>

//These arrays will count the number of instances each number from 0-99 appears.
int counterArray1[100] = {0};
int counterArray2[100] = {0};

int scrambled (unsigned int arr1[], unsigned int arr2[], unsigned int size){
    if(size == 0){ //check if array sizes are 0
        return 1;
    }
    else{
        //Count instances of each number and add to arr1
        for(int loop = 0; loop < size; loop++){
            counterArray1[arr1[loop]] += 1;
        }
        
        //Count instances of each number and add to arr2
        for(int loop = 0; loop < size; loop++){
            counterArray2[arr2[loop]] += 1;
        }
        
        /* //Test if counterArrays work by printing 
        for(int loop = 0; loop < 100; loop++){
            printf("%d", counterArray1[loop]);
        }
        
        printf("\n");
        
        for(int loop = 0; loop < 100; loop++){
            printf("%d", counterArray2[loop]);
        }
        */
        
        //Compare two counterArrays
        for(int loop = 0; loop < 100; loop++){
            if(counterArray1[loop] != counterArray2[loop]){
                return 0;
            }
        }
        return 1;
    }
}

