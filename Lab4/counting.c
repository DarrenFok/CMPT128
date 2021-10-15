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
    int word = 1; //Starts with being non-letter

    while (( aChar = getchar() ) != EOF){
        charCount++;

        //If character is end of string or newline, it indicates that there is a line, thus we can add one to lineCount
        if(aChar == '\n' || aChar == '\0'){
            lineCount++; 
            word = 1;
        }

        //If character is a letter...
        else if( (isLetter(aChar) == 1) ){
            //Determine whether it is the first letter ('1' means yes, since it says previous character was not)
            if(word == 1){ 
                //Add to word count at beginning of the word
                wordCount++;
                //Keep simultaenous letters as 0, until it gets set back to 1 (meaning the word has ended since '1' means not letter)
                word = 0; 
            }
        }

        //If character is anything else, set to 1 so we can signify a new word
        else{ 
            word = 1;
        }
    }
    printf("%lu %lu %lu\n", charCount, wordCount, lineCount);

    return 0;
}

int isLetter(char input){
    int result = 0;

    if( (input >= 65 && input <= 90) || (input >= 97 && input <= 122) || input == 39){
        result = 1;
    }

    return result;
}