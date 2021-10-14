/*
 * Filename: counting.c
 * 
 * Description: Takes an input file and returns number of characters, words and lines
 * 
 * Author: Darren Fok
 * Date: October 14th, 2021
 */

#include <stdio.h>

int isLetter(char input);

int main (void){
    //Fields
    unsigned long charCount = 0; 
    unsigned long wordCount = 0; 
    unsigned long lineCount = 0;
    char aChar = 1;

    while (( aChar = getchar() ) != EOF){
        charCount++;

        //If character is a space, indent, end of string, or a newline, and is not a letter, add one to wordCount
        if((aChar == ' ' || aChar == '\n') && isLetter(aChar) == 0){
            wordCount++;
        }

        //If character is end of string or newline, it indicates that there is a line, thus we can add one to lineCount
        if(aChar == '\n' || aChar == '\0'){
            lineCount++; 
        }
    }
    printf("%lu %lu %lu\n", charCount, wordCount, lineCount);
}

int isLetter(char input){
    int result = 0;

    if( (input >= 65 && input <= 90) || (input >= 97 && input <= 122) || input == 39){
        result = 1;
    }

    return result;
}