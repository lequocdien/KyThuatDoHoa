#include "veHinh3D.h"
#include "vehinh2D.h"
#include "2D2.h"
//Xu ly xu kien khi click vao Grid
void gridMouseClick(){
	while(true)
	{
		delay(0.0001);
		int x, y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if(x >= WIDTH_PANEL_LEFT + 10 && x <= WIDTH_PANEL_MAIN - 10 && y >= HEIGHT_PANEL_TOP + 10 && y <= getmaxy() - 10){
				cout<<"\tToa do click Work Station ban dau: "<<x<<" "<<y<<endl;
				x = LamTronToaDo(x);
				y = LamTronToaDo(y);
				cout<<"\tToa do click Work Station qua LamTronToaDo(): "<<x<<" "<<y<<endl;
			}
		}
	}
}
int trangthai=-1;
//Xu ly su kien click vao cac button
void buttonsMouseClick(){
	while(true)
	{
		delay(0.0001);
		int x, y;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if(x>=200&&x<=1110&&y>50&&y<=680)
			{
			cout<<"To doa click: "<<x<<" "<<y<<endl;
			XuatToaDoClick(x,y);
		    }
			if(x >= 0 && x <= 200 && y >= SPACE_FIRST_BUTTON && y <= SPACE_FIRST_BUTTON + 50){
				//Phan xu ly giao dien khi click vao "2D 1"
				button(0, SPACE_FIRST_BUTTON, 200, SPACE_FIRST_BUTTON + 50, 15, "2D 1", 4, 4, 0);
				button(0, SPACE_FIRST_BUTTON + 60, 200, SPACE_FIRST_BUTTON + 110, 8, "2D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 120, 200, SPACE_FIRST_BUTTON + 170, 8, "3D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 180, 200, SPACE_FIRST_BUTTON + 230, 8, "3D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 240, 200, SPACE_FIRST_BUTTON + 290, 8, "About", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 300, 200, SPACE_FIRST_BUTTON + 350, 8, "Help", 4, 2, 15);
				
				//Thay btn Run
				button(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2, "RUN", 10, 4, 14);
				
				//Phan ve, hien thi hinh anh khi click vao "2D 1"
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 	//Reset panel main				
				rectangleSolid(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, 0, getmaxx(), getmaxy(), 8);
				/*
					PROCESSING by DAI
				*/
				initWorkStationDai();
				//HeToaDo2ChieuDai();
				DrawTree();
				QuatGio();
				Sticks();
				trangthai=1;
				
				
			}
			else if(x>=0&&x<=200&&y>=0&&y<=60&&trangthai==1)
						{
							QuatGioWhite();
						    MoveApple();
							//QuatGio();	
						    trangthai=-1;
						}
			else if(x >= 0 && x <= 200 && y >= SPACE_FIRST_BUTTON + 60 && y <= SPACE_FIRST_BUTTON + 110){
				
				//Phan xu ly giao dien khi click vao "2D 2"
				button(0, SPACE_FIRST_BUTTON, 200, SPACE_FIRST_BUTTON + 50, 8, "2D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 60, 200, SPACE_FIRST_BUTTON + 110, 15, "2D 2", 4, 4, 0);
				button(0, SPACE_FIRST_BUTTON + 120, 200, SPACE_FIRST_BUTTON + 170, 8, "3D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 180, 200, SPACE_FIRST_BUTTON + 230, 8, "3D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 240, 200, SPACE_FIRST_BUTTON + 290, 8, "About", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 300, 200, SPACE_FIRST_BUTTON + 350, 8, "Help", 4, 2, 15);
				
				//Thay btn Run
				button(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2, "RUN", 10, 4, 14);
				
				//Phan ve, hien thi hinh anh khi click vao "2D 2"
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 	//Reset panel main	
				rectangleSolid(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, 0, getmaxx(), getmaxy(), 8);
				
				initWorkStationDuong();
			
				maybay(1);	
				
				trangthai=0;
				/*
					PROCESSING by DUONG
				*/
			}
			else if(x>=0 && x<= 200 && y>=0 && y<=60 && trangthai==0){
							//	cout<<"ok run";
								moveDuong(1);
								trangthai=-1;
			}
			
			else if(x >= 0 && x <= 200 && y >= SPACE_FIRST_BUTTON + 120 && y <= SPACE_FIRST_BUTTON + 170){
				trangthai=-1;
				cout<<"\t\t\t\t=================3D1================="<<endl;
				//Phan xu ly giao dien khi click vao "3D 1"
				button(0, SPACE_FIRST_BUTTON, 200, SPACE_FIRST_BUTTON + 50, 8, "2D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 60, 200, SPACE_FIRST_BUTTON + 110, 8, "2D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 120, 200, SPACE_FIRST_BUTTON + 170, 15, "3D 1", 4, 4, 0);
				button(0, SPACE_FIRST_BUTTON + 180, 200, SPACE_FIRST_BUTTON + 230, 8, "3D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 240, 200, SPACE_FIRST_BUTTON + 290, 8, "About", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 300, 200, SPACE_FIRST_BUTTON + 350, 8, "Help", 4, 2, 15);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				//Reset panel main	
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 		
				
				//Reset panel right
				rectangleSolid(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, 0, getmaxx(), getmaxy(), 8);
				
				//Khoi tao truc toa do va luoi
				initWorkStation();	
				
				//Khoi tao phan information
				initGUIInfoHinhHop();
				
				//Lay cac input tu nguoi dung
				int inPut[6];
				int toaDoX = 1140;
				int toaDoY = 65;
				for(int i = 0; i<6; i++){
					if(i == 0 || i == 1 || i == 2){
						inPut[i] = nhanKyTuTuBanPhim(toaDoX, toaDoY);
						if(i == 0 || i == 1){
							outtextxy(toaDoX + 45, toaDoY, ";");
						}
						else{
							outtextxy(toaDoX + 45, toaDoY, ")");
						}
						toaDoX = toaDoX + 60;
					}
					else{
						toaDoX = 1230;
						toaDoY = toaDoY + 30;
						inPut[i] = nhanKyTuTuBanPhim(toaDoX, toaDoY);
					}
					
				}
				cout<<"\t\tINPUT"<<endl;
				for(int i = 0; i<6; i++){
					cout<<"\t"<<inPut[i]<<endl;
				}
				
				//Ve hinh chu nhat
				veHinhChuNhat(inPut[0]*5, inPut[1]*5, inPut[2]*5, inPut[3]*5, inPut[4]*5, inPut[5]*5);
//				veHinhChuNhat(40, 30, 20, 50, 30, 40);
				
			}
			else if(x >= 0 && x <= 200 && y >= SPACE_FIRST_BUTTON + 180 && y <= SPACE_FIRST_BUTTON + 230){
				trangthai=-1;
				cout<<"\t\t\t\t=================3D2================="<<endl;
				//Phan xu ly giao dien khi click vao "3D 2"
				button(0, SPACE_FIRST_BUTTON, 200, SPACE_FIRST_BUTTON + 50, 8, "2D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 60, 200, SPACE_FIRST_BUTTON + 110, 8, "2D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 120, 200, SPACE_FIRST_BUTTON + 170, 8, "3D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 180, 200, SPACE_FIRST_BUTTON + 230, 15, "3D 2", 4, 4, 0);
				button(0, SPACE_FIRST_BUTTON + 240, 200, SPACE_FIRST_BUTTON + 290, 8, "About", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 300, 200, SPACE_FIRST_BUTTON + 350, 8, "Help", 4, 2, 15);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				//Reset panel main	
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 		
				
				//Reset panel right
				rectangleSolid(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, 0, getmaxx(), getmaxy(), 8);
				
				//Khoi tao truc toa do va luoi
				initWorkStation();	
				
				//Khoi tao phan information
				initGUIInfoHinhTru();
				
				//Lay cac input tu nguoi dung
				int inPut[5];
				int toaDoX = 1185;
				int toaDoY = 65;
				for(int i = 0; i<5; i++){
					if(i == 0 || i == 1 || i == 2){
						inPut[i] = nhanKyTuTuBanPhim(toaDoX, toaDoY);
						if(i == 0 || i == 1){
							outtextxy(toaDoX + 35, toaDoY, ";");
						}
						else{
							outtextxy(toaDoX + 35, toaDoY, ")    ");
						}
						toaDoX = toaDoX + 45;
					}
					else{
						toaDoX = 1230;
						toaDoY = toaDoY + 30;
						inPut[i] = nhanKyTuTuBanPhim(toaDoX, toaDoY);
					}
					
				}
				cout<<"\t\tINPUT"<<endl;
				for(int i = 0; i<5; i++){
					cout<<"\t"<<inPut[i]<<endl;
				}
				
				//Ve hinh tru
				veHinhTru(inPut[0]*5, inPut[1]*5, inPut[2]*5, inPut[3]*5, inPut[4]*5);
//				veHinhTru(40, 30, 20, 20, 50);
			}
			else if(x >= 0 && x <= 200 &&  y >= SPACE_FIRST_BUTTON + 240 && y <= SPACE_FIRST_BUTTON + 290){
				trangthai=-1;
				button(0, SPACE_FIRST_BUTTON, 200, SPACE_FIRST_BUTTON + 50, 8, "2D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 60, 200, SPACE_FIRST_BUTTON + 110, 8, "2D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 120, 200, SPACE_FIRST_BUTTON + 170, 8, "3D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 180, 200, SPACE_FIRST_BUTTON + 230, 8, "3D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 240, 200, SPACE_FIRST_BUTTON + 290, 15, "About", 4, 4, 0);
				button(0, SPACE_FIRST_BUTTON + 300, 200, SPACE_FIRST_BUTTON + 350, 8, "Help", 4, 2, 15);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				//Reset panel main
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15); 		
				
				//Reset panel right
				rectangleSolid(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, 0, getmaxx(), getmaxy(), 8);
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 250, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 280, 7, "Copyright © 2019 by", 9, 2, 1);
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 280, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 310, 7, "1. Le Quoc Dien - N16DCCN023", 9, 2, 1);
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 310, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 340, 7, "2. Phung Van Dai - N16DCCN035", 9, 2, 1);
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 340, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 370, 7, "3. Vu Van Duong - N16DCCN034", 9, 2, 1);
			
			}
			else if(x >= 0 && x <= 200 && y >= SPACE_FIRST_BUTTON + 300 && y <= SPACE_FIRST_BUTTON + 350){
				trangthai=-1;
				button(0, SPACE_FIRST_BUTTON, 200, SPACE_FIRST_BUTTON + 50, 8, "2D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 60, 200, SPACE_FIRST_BUTTON + 110, 8, "2D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 120, 200, SPACE_FIRST_BUTTON + 170, 8, "3D 1", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 180, 200, SPACE_FIRST_BUTTON + 230, 8, "3D 2", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 240, 200, SPACE_FIRST_BUTTON + 290, 8, "About", 4, 2, 15);
				button(0, SPACE_FIRST_BUTTON + 300, 200, SPACE_FIRST_BUTTON + 350, 15, "Help", 4, 4, 0);
				
				//Xoa btn RUN
				rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
				
				//Reset panel main
				rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15);	
				
				//Reset panel right
				rectangleSolid(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, 0, getmaxx(), getmaxy(), 8);
				
				button(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP + 350, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP + 250, 7, "Help yourself !", 9, 2, 1);
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
	}
}


