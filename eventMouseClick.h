#include "veHinh3D.h"
//Xu ly xu kien khi click vao Grid
void gridMouseClick(){
	while(true)
	{
		delay(0.0001);
		int x, y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if(x >= 210 && x <= 1190 && y >= 70 && y <= getmaxy() - 10){
				cout<<"\tToa do click Work Station ban dau: "<<x<<" "<<y<<endl;
				x = LamTronToaDo(x);
				y = LamTronToaDo(y);
				cout<<"\tToa do click Work Station qua LamTronToaDo(): "<<x<<" "<<y<<endl;
			}
		}
	}
}

//Xu ly su kien click vao cac button
void buttonsMouseClick(){
	while(true)
	{
		delay(0.0001);
		int x, y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			cout<<"To doa click: "<<x<<" "<<y<<endl;
			
			if(x >= 0 && x <= 200 && y >= 210 && y <= 260){
				//Phan xu ly giao dien khi click vao "2D 1"
				button(0, 210, 200, 260, 15, "2D 1", 4, 4, 0);
				button(0, 270, 200, 320, 8, "2D 2", 4, 2, 15);
				button(0, 330, 200, 380, 8, "3D 1", 4, 2, 15);
				button(0, 390, 200, 440, 8, "3D 2", 4, 2, 15);
				button(0, 450, 200, 500, 8, "About", 4, 2, 15);
				button(0, 510, 200, 560, 8, "Help", 4, 2, 15);
				
				//Thay btn Run
				button(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2, "RUN", 10, 4, 14);
				
				//Phan ve, hien thi hinh anh khi click vao "2D 1"
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 	//Reset panel main				
				/*
					PROCESSING by DAI
				*/
				
				
				
			}
			else if(x >= 0 && x <= 200 && y >= 270 && y <= 320){
				
				//Phan xu ly giao dien khi click vao "2D 2"
				button(0, 210, 200, 260, 8, "2D 1", 4, 2, 15);
				button(0, 270, 200, 320, 15, "2D 2", 4, 4, 0);
				button(0, 330, 200, 380, 8, "3D 1", 4, 2, 15);
				button(0, 390, 200, 440, 8, "3D 2", 4, 2, 15);
				button(0, 450, 200, 500, 8, "About", 4, 2, 15);
				button(0, 510, 200, 560, 8, "Help", 4, 2, 15);
				
				//Thay btn Run
				button(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2, "RUN", 10, 4, 14);
				
				//Phan ve, hien thi hinh anh khi click vao "2D 2"
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 	//Reset panel main	
				/*
					PROCESSING by DUONG
				*/
			}
			else if(x >= 0 && x <= 200 && y >= 330 && y <= 380){
				
				//Phan xu ly giao dien khi click vao "3D 1"
				button(0, 210, 200, 260, 8, "2D 1", 4, 2, 15);
				button(0, 270, 200, 320, 8, "2D 2", 4, 2, 15);
				button(0, 330, 200, 380, 15, "3D 1", 4, 4, 0);
				button(0, 390, 200, 440, 8, "3D 2", 4, 2, 15);
				button(0, 450, 200, 500, 8, "About", 4, 2, 15);
				button(0, 510, 200, 560, 8, "Help", 4, 2, 15);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				//Reset panel main	
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 		
				
				//Phan ve, hien thi hinh anh khi click vao "3D 1"
				initWorkStation();	//Khoi tao truc toa do va luoi
				veHinhChuNhat();
				
//				lineDDA(420,250,257,172);
				
//				DIEM a, b;
//				a.toaDoX = 420;
//				a.toaDoY = 250;
//				b.toaDoX = 257;
//				b.toaDoY = 172;
//////				lineDDA1(a,b);
//				lineDDA(a.toaDoX, a.toaDoY, b.toaDoX, b.toaDoY);
				
//				DDALine(a, b);
//				line(rectangularPoints[0].toaDoX, rectangularPoints[0].toaDoY, rectangularPoints[1].toaDoX, rectangularPoints[1].toaDoY);
//				setviewport(800, 400, 900, 500, 1);
//				outtextxy(0,0, "Hello");
				
			}
			else if(x >= 0 && x <= 200 && y >= 390 && y <= 440){
				
				//Phan xu ly giao dien khi click vao "3D 2"
				button(0, 210, 200, 260, 8, "2D 1", 4, 2, 15);
				button(0, 270, 200, 320, 8, "2D 2", 4, 2, 15);
				button(0, 330, 200, 380, 8, "3D 1", 4, 2, 15);
				button(0, 390, 200, 440, 15, "3D 2", 4, 4, 0);
				button(0, 450, 200, 500, 8, "About", 4, 2, 15);
				button(0, 510, 200, 560, 8, "Help", 4, 2, 15);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				//Phan ve, hien thi hinh anh khi click vao "3D 2"
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 	//Reset panel main	
				/*
					Goi ham tai day
					Dien
				*/
			
			}
			else if(x >= 0 && x <= 200 &&  y >= 450 && y <= 500){
				button(0, 210, 200, 260, 8, "2D 1", 4, 2, 15);
				button(0, 270, 200, 320, 8, "2D 2", 4, 2, 15);
				button(0, 330, 200, 380, 8, "3D 1", 4, 2, 15);
				button(0, 390, 200, 440, 8, "3D 2", 4, 2, 15);
				button(0, 450, 200, 500, 15, "About", 4, 4, 0);
				button(0, 510, 200, 560, 8, "Help", 4, 2, 15);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 	//Reset panel main	
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 300, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 330, 7, "Copyright © 2019 by", 9, 2, 14);
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 330, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 360, 7, "1. Le Quoc Dien - N16DCCN023", 9, 2, 14);
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 360, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 390, 7, "2. Phung Van Dai - N16DCCN034", 9, 2, 14);
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 390, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 420, 7, "3. Vu Van Duong - N16DCCN035", 9, 2, 14);
			
			}
			else if(x >= 0 && x <= 200 && y >= 510 && y <= 560){
				button(0, 210, 200, 260, 8, "2D 1", 4, 2, 15);
				button(0, 270, 200, 320, 8, "2D 2", 4, 2, 15);
				button(0, 330, 200, 380, 8, "3D 1", 4, 2, 15);
				button(0, 390, 200, 440, 8, "3D 2", 4, 2, 15);
				button(0, 450, 200, 500, 8, "About", 4, 2, 15);
				button(0, 510, 200, 560, 15, "Help", 4, 4, 0);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 	//Reset panel main	
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 350, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 380, 7, "Tu mo di giup cai lol", 9, 2, 14);
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
	}
}


