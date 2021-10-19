/*
 * Filename: inRectangle.c
 *
 * Description: Read coordinates of a point and coordinates of corners of a rectangle, and determines whether the point is in the rectangle.
 * 
 * Author: Darren Fok
 * Date: October 14th, 2021
 */

int inRectangle( float pt[2], float rect[4] ){
    //Determine layout of rectangle (x1y1 in top left, x2y2 in bottom right)
    if(rect[0] < rect[2] && rect[1] < rect[3]){
        //Determine if the x and y of pt are in between the rectangle's x and y coordinates
        if(pt[0] >= rect[0] && pt[0] <= rect[2] && pt[1] >= rect[1] && pt[1] <= rect[3]){
            return 1;
        }
        else{
            return 0;
        }
    }

    //Repeat process with different situations
    //x1y1 in top right, x2y2 in bottom left
    if(rect[0] > rect[2] && rect[1] < rect[3]){
        if(pt[0] <= rect[0] && pt[0] >= rect[2] && pt[1] >= rect[1] && pt[1] <= rect[3]){
            return 1;
        }
        else{
            return 0;
        }
    }

    //x1y1 in bottom right, x2y2 in top left
    if(rect[0] > rect[2] && rect[1] > rect[3]){
        if(pt[0] <= rect[0] && pt[0] >= rect[2] && pt[1] <= rect[1] && pt[1] >= rect[3]){
            return 1;
        }
        else{
            return 0;
        }
    }

    //x1y1 in bottom left, x2y2 in top right
    if(rect[0] < rect[2] && rect[1 > rect[3]]){
        if(pt[0] >= rect[0] && pt[0] <= rect[2] && pt[1] <= rect[1] && pt[1] >= rect[3]){
            return 1;
        }
        else{
            return 0; 
        }
    }

    else if(rect[0] == rect[2] || rect[1] == rect[3]){
        return 0; 
    }
}