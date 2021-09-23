#include <stdio.h>

/* Outputs on stdout the memory size (in bits) of ten numerical data types in c) */

int main (void)  {
    //unsigned char
    printf("An unsigned char is stored in %lu bytes. \n", sizeof(char));

    //signed char
    printf("A signed char is stored in %ld bytes. \n", sizeof(char));

    //unsigned short
    printf("An unsigned short is stored in %lu bytes. \n", sizeof(short));

    //signed short
    printf("A signed short is stored in %ld bytes. \n", sizeof(short));

    //unsigned int 
    printf("An unsigned int is stored in %lu bytes. \n", sizeof(int));

    //signed int 
    printf("A signed int is stored in %ld bytes. \n", sizeof(int));

    //unsigned long
    printf("An unsigned long is stored in %lu bytes. \n", sizeof(long));

    //signed long
    printf("A signed long is stored in %ld bytes. \n", sizeof(long));

    //float
    printf("A float is stored in %lu bytes. \n", sizeof(float));

    //double 
    printf("A double is sotred in %lu bytes. \n", sizeof(double));

    return 0;
}