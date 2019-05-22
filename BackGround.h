
// A C program to make a rainbow. This program would only 
// work in Turbo C compiler in DOS compatible machine 
#include<stdio.h> 
#include<graphics.h> 
#include<dos.h> 
  







void flood(int x, int y, int new_col, int old_col) 
{ 
    
	// check current pixel is old_color or not 
    if (getpixel(x, y) == old_col) { 
  //delay(0);
        // put new pixel with new color 
        putpixel(x, y, new_col); 
  
        // recursive call for bottom pixel fill 
        flood(x + 1, y, new_col, old_col); 
  
        // recursive call for top pixel fill 
        flood(x - 1, y, new_col, old_col); 
  
        // recursive call for right pixel fill 
        flood(x, y + 1, new_col, old_col); 
  
        // recursive call for left pixel fill 
        flood(x, y - 1, new_col, old_col); 
    } 
} 
  





