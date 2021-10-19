#include <stdio.h>
#include "inRectangle.h"

int inRectangle( float pt[2], float rect[4]);

int main ( void ){
    //define rectangle from 
    float rect[4] = {1.0, 1.0, 2.0, 2.0};

    //define point inside first rectangle
    float p_in[2] = {1.5, 1.5};

    float p_out[2] = {2.5, 0.5};

    float p_edge[2] = {1.0, 1.0};

    //test 1: if it returns false for when it should be true (since point is inside rectangle)
    if(inRectangle(p_in, rect) == 0){
        puts("error: should return true for p_in");
        return 1;
    }

    //test 2: if it doesn't return false for when it should be false (since point is outside of rectangle)
    if(inRectangle(p_out, rect) != 0){
        puts("error: should return false for p_out.");
        return 1;
    }

    //test 3: if it returns false for when it should be true (since point is on the edge of rectangle, therefore it is true)
    if(inRectangle(p_edge, rect) == 0){
        puts("error: should return true for p_edge");
        return 1;
    }

    //test 4: should return true since it is inside point.
    if(inRectangle(p_out, rect) != 1){
        puts("This statement is true.");
    }

    return 0; 
}
