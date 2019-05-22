//Dinh nghia cac kich thuoc
#define WIDTH_PANEL_LEFT  200		//Chieu rong cua panel left (UI co 3 panel: panel left; panel top; panel main)
#define HEIGHT_PANEL_TOP  60		//Chieu cao cua panel top
#define WIDTH_PANEL_RIGHT  200 		//Chieu rong cua panel right
#define WIDTH_PANEL_MAIN  900		//Chieu rong cua panel main
#define SPACE_FIRST_BUTTON  170		//Khoang cach giua btn 2D1 voi mep tren cua man hinh graphic
#define SPACE_BUTTON  10			//Khoang cach giua button theo chieu doc
#define HEIGHT_BUTTON  50			//Chieu cao cua mot button
#define GOC_TOA_DO_X 660
#define GOC_TOA_DO_Y 660
#define DELAY 0

       
  
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h> 
using namespace std;
#include "globalMethod.h"
#include "GUI.h"
#include "eventMouseClick.h"

 
int main (){
	
	initwindow(1350, 700, "Ve hinh co ban", 160, 450); 
	initGUI();
	buttonsMouseClick(); 
	
	getch();
	return 0;   
	                                                                                
}
