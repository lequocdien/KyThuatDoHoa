//Dinh nghia cac kich thuoc
#define WIDTH_PANEL_LEFT  200		//Chieu rong cua panel left (UI co 3 panel: panel left; panel top; panel main)
#define HEIGHT_PANEL_TOP  60		//Chieu cao cua panel top
#define WIDTH_PANEL_RIGHT  200 		//Chieu rong cua panel right
#define WIDTH_PANEL_MAIN  1000		//Chieu rong cua panel right
#define SPACE_BUTTON  10			//Khoang cach giua button theo chieu doc
#define HEIGHT_BUTTON  50			//Chieu cao cua button
#define GOC_TOA_DO_X 400
#define GOC_TOA_DO_Y 700

#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h> 
using namespace std;
#include "globalMethod.h"
#include "GUI.h"
#include "eventMouseClick.h"

        
     
 
int main (){
	       
	initwindow(1600, 850, "Ve hinh co ban", 160, 450);
	initGUI();
	buttonsMouseClick(); 
	
	getch();
	return 0;
	            
          
}
