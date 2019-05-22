/*Moving a car*/
#define WIDTH_PANEL_LEFT  200		//Chieu rong cua panel left (UI co 3 panel: panel left; panel top; panel main)
#define HEIGHT_PANEL_TOP  60		//Chieu cao cua panel top
#define WIDTH_PANEL_RIGHT  200 		//Chieu rong cua panel right
#define WIDTH_PANEL_MAIN  900		//Chieu rong cua panel right
#define SPACE_FIRST_BUTTON  170		//Khoang cach giua btn 2D1 voi mep tren cua man hinh graphic
#define SPACE_BUTTON  10			//Khoang cach giua button theo chieu doc
#define HEIGHT_BUTTON  50			//Chieu cao cua button
#define GOC_TOA_DO_X 400
#define GOC_TOA_DO_Y 600
#define ROUND(a) (int)(a+0.5)

#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<time.h> 
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;


	

int LamTronToaDoDuong(int toaDo){
	int soDu = toaDo % 5;
	if(soDu >= 3){
		return toaDo + 5 - soDu;
	}
	else if(soDu < 3){
		return toaDo - soDu;
	}
}


void initGridDuong(int x, int y, int a, int b){
	setcolor(0);	//Xac dinh mau ve la mau BLACK
	
	for(int i = x; i<= a; i){
		line(i, y, i, b);
		i = i + 5;
	}
	for(int i = y; i<= b; i){
		line(x, i, a, i);
		i = i + 5;
	}	
}

void initHeToaDoDuong(int x, int y, int a, int b){
	int medianX = 500 + WIDTH_PANEL_LEFT;		//NOTE: Cap nhat khi co su thay doi
	int medianY = 380 + HEIGHT_PANEL_TOP;		//NOTE: Cap nhat khi co su thay doi
	setcolor(4);
	line(medianX, y, medianX, b);
	line(x, medianY, a, medianY);
}

void initWorkStationDuong(){
	initGridDuong(WIDTH_PANEL_LEFT + 10, HEIGHT_PANEL_TOP + 10, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN - 10, getmaxy() - 10);
	initHeToaDoDuong(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy());
}


void floodDuong(int x, int y, int new_col, int old_col) 
{ 
    
	// check current pixel is old_color or not 
    if (getpixel(x, y) == old_col) { 
  //delay(0);
        // put new pixel with new color 
        putpixel(x, y, new_col); 
  
        // recursive call for bottom pixel fill 
        floodDuong(x + 1, y, new_col, old_col); 
  
        // recursive call for top pixel fill 
        floodDuong(x - 1, y, new_col, old_col); 
  
        // recursive call for right pixel fill 
        floodDuong(x, y + 1, new_col, old_col); 
  
        // recursive call for left pixel fill 
        floodDuong(x, y - 1, new_col, old_col); 
    } 
}

void putpixelDuong(int x, int y, int color){
	int X=LamTronToaDoDuong(x);
	int Y=LamTronToaDoDuong(y);
	
	    putpixel (X+1,Y,color);  
        putpixel (X+2,Y,color);
        putpixel (X,Y,color);
        putpixel (X-1,Y,color);
        putpixel (X-2,Y,color);
        
        putpixel (X,Y-1,color);
        putpixel (X+1,Y-1,color);
        putpixel (X+2,Y-1,color);
        putpixel (X-1,Y-1,color);
        putpixel (X-2,Y-1,color);
        
        putpixel (X,Y+1,color);
        putpixel (X+1,Y+1,color);
        putpixel (X+2,Y+1,color);
        putpixel (X-1,Y+1,color);
        putpixel (X-2,Y+1,color);
        
        putpixel (X,Y+2,color);
        putpixel (X+1,Y+2,color);
        putpixel (X+2,Y+2,color);
        putpixel (X-1,Y+2,color);
        putpixel (X-2,Y+2,color);
        
        putpixel (X,Y-2,color);
        putpixel (X+1,Y-2,color);
        putpixel (X+2,Y-2,color);
        putpixel (X-1,Y-2,color);
        putpixel (X-2,Y-2,color);
	
	}

void DDADuong(int X0, int Y0, int X1, int Y1,int color) 
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0;
    for (int i = 0; i <= steps; i++) 
    { 
        putpixelDuong (X,Y,color);
        
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
                             // generation step by step 
    } 
} 
  
 
 void plotDuong(int xc, int yc, int x, int y, int color)
{	
    putpixelDuong(xc+x-1, yc+y, color);//goc phan tu phias duoi ben phai
    
    putpixelDuong(xc-x-1, yc+y, color);//goc phan tu phia duoi ben trai
    
    putpixelDuong(xc+x-1, yc-y, color);//goc phan tu phia tren ben phai
    
    putpixelDuong(xc-x-1, yc-y, color);//goc phan tu phia tren ben trai
   
    
       
}
void elipMidpointDuong(int xc,int yc, int a, int b, int color)
{
	
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    plotDuong(xc, yc, x, y, color);
    p = ROUND(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        plotDuong(xc, yc, x, y, color);
    }
    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        y--;
        fy -= 2*a2;
        
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        plotDuong(xc, yc, x, y, color);
    }
}


void XuatToaDoDuong(int x,int y,int u, int v, char *s)
{
	int tdx,tdy,tempx,tempy;
	if((x%5)>=3)// lam tron den 5
	{
		tempx=x+5;
	}
	else
	{
		tempx=x;
	}
	if((y%5)>=3)
	{
		tempy=y+5;
	}
	else
	{
		tempy=y;
	}

	tdx=(tempx/5)-140;
	tdy=88-(tempy/5);
					
	char a[4];
	char b[4];
	_itoa(tdx,a,10);
	_itoa(tdy,b,10);
	
	setbkcolor(8);
	setcolor(14);
	settextstyle(1,0,2); 
	outtextxy(u,v,"             ");
	outtextxy(u,v,s);
	outtextxy(u+45,v,"(");
	outtextxy(u+60,v,a);
	outtextxy(u+110,v,";");
	outtextxy(u+120,v,"            ");
	outtextxy(u+120,v,b);
	outtextxy(u+170,v,")");	
	}
	
	
	void XuatTTEllipDuong(int x,int y,int r1,int r2, int u, int v, char *s)
{
	int tdx,tdy,tempx,tempy;
	int bk1,bk2;
	if((x%5)>=3)// lam tron den 5
	{
		tempx=x+5;
	}
	else
	{
		tempx=x;
	}
	if((y%5)>=3)
	{
		tempy=y+5;
	}
	else
	{
		tempy=y;
	}

	tdx=(tempx/5)-140;
	tdy=88-(tempy/5);			
	
	bk1=r1/5;
	bk2=r2/5;
	
	char a[4];
	char b[4];
	char a1[4];
	char b1[4];
	_itoa(tdx,a,10);
	_itoa(tdy,b,10);
	_itoa(bk1,a1,10);
	_itoa(bk2,b1,10);
	
	setbkcolor(8);
	setcolor(14);
	settextstyle(1,0,2); 
	outtextxy(u,v,"              ");
	outtextxy(u,v,s);
	outtextxy(u+80,v,"(");
	outtextxy(u+95,v,a);
	outtextxy(u+140,v,";");
	outtextxy(u+150,v,"        ");
	outtextxy(u+150,v,b);
	outtextxy(u+185,v,";");	
	outtextxy(u+80,v+25,"                ");
	outtextxy(u+90,v+25,a1);
	outtextxy(u+110,v+25,";");
	outtextxy(u+120,v+25,b1);
	outtextxy(u+160,v+25,")");
	}
	
	void denduong(){
		srand(time(NULL)); 
		int mau=rand()%16;
		
		setfillstyle(SOLID_FILL,mau);	
		setcolor(mau);
		setbkcolor(mau);
		
		elipMidpointDuong(300,630,10,10,mau);
		fillellipse(300,630,10,10);		
		
		elipMidpointDuong(960,630,10,10,mau);
		fillellipse(960,630,10,10);	
		
		elipMidpointDuong(380,340,10,10,mau);
		fillellipse(380,340,10,10);	
		
		elipMidpointDuong(870,340,10,10,mau);
		fillellipse(870,340,10,10);	

		elipMidpointDuong(445,115,10,10,mau);
		fillellipse(445,115,10,10);	
		
		elipMidpointDuong(805,115,10,10,mau);
		fillellipse(805,115,10,10);	
		
	}

	void duongbang(int color)
	{
		//duong bang
		DDADuong(470,70,300,680,color);// TRAI
		DDADuong(780,70,960,680,color);// PHAI
	}

	void maybay(int color)
	{
		duongbang(6);
		elipMidpointDuong(630,480,22,180,color);// than may bay
		XuatTTEllipDuong(630,480,22,180,1110,150,"Ellip");
		
		//canh ben phai
		DDADuong(650,410,810,510,color);
		DDADuong(810,510,820,535,color);
		DDADuong(820,535,650,500,color); 
		XuatToaDoDuong(820,535,1110,265,"CP");
		
	
		//canh ben trai
		DDADuong(610,410,445,510,color); 
		DDADuong(445,510,435,535,color);
		DDADuong(435,535,610,500,color);
		
		XuatToaDoDuong(435,535,1110,220,"CT");
		
		//duoi ben trai
		DDADuong(625,645,555,660,color);
		DDADuong(555,660,560,635,color);
		DDADuong(560,635,615,610,color);
		
		XuatToaDoDuong(555,660,1110,310,"DT");
		
		//duoi ben phai
		DDADuong(635,645,700,660,color);
		DDADuong(700,660,695,635,color);
		DDADuong(695,635,645,610,color);	
		
		XuatToaDoDuong(700,660,1110,355,"DP");
		
		denduong();
		
		floodDuong(635,440,0,4);//chuyen do thanh den
		floodDuong(585,440,0,4);
		floodDuong(675,440,0,4);
		floodDuong(700,500,0,4);
		
		floodDuong(635,440,15,0);//chuyen den thanh trang
		floodDuong(585,440,15,0);
		floodDuong(675,440,15,0);
		floodDuong(700,500,15,0);
		floodDuong(585,635,15,0);
		floodDuong(665,635,15,0);
		
		
		floodDuong(630,470,12,15);//to mau may bay
		floodDuong(705,480,12,15);
		floodDuong(560,480,12,15);
		floodDuong(585,635,12,15);
		floodDuong(655,625,12,15);
		
	
	}
	
	void moveDuong(int color){
		
		int multi=5;
		float k=1;// gia tri de thu nho
		float j=0;// gia tri de dich chuyen 1 px sang ben phai truc oy
		for(int i=0;i<=170;i+=multi){// gia tri de dich chuyen len phia tren
		//dich chuyen len tren truoc -> thu nho may bay -> dich chuyen sang phai
		if(i>160){
		//Draw panel top
		button(WIDTH_PANEL_LEFT, 0, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP, 8, "VE HINH CO BAN", 5, 5, 14);
		}
		denduong();
		//delay(10);		

		elipMidpointDuong((630*k)+j,((480-i)*k),22*k,180*k,color);// than may bay
		
			
		//canh ben phai
		DDADuong((650*k)+j,(410-i)*k,(810*k)+j,(510-i)*k,color);
		DDADuong((810*k)+j,(510-i)*k,(820*k)+j,(535-i)*k,color);
		DDADuong((820*k)+j,(535-i)*k,(650*k)+j,(500-i)*k,color); 
	
		//canh ben trai
		DDADuong((610*k)+j,(410-i)*k,(445*k)+j,(510-i)*k,color); 
		DDADuong((445*k)+j,(510-i)*k,(435*k)+j,(535-i)*k,color);
		DDADuong((435*k)+j,(535-i)*k,(610*k)+j,(500-i)*k,color);
		
		//duoi ben trai
		DDADuong((625*k)+j,(645-i)*k,(555*k)+j,(660-i)*k,color);
		DDADuong((555*k)+j,(660-i)*k,(560*k)+j,(635-i)*k,color);
		DDADuong((560*k)+j,(635-i)*k,(615*k)+j,(610-i)*k,color);
		
		//duoi ben phai
		DDADuong((635*k)+j,(645-i)*k,(700*k)+j,(660-i)*k,color);
		DDADuong((700*k)+j,(660-i)*k,(695*k)+j,(635-i)*k,color);
		DDADuong((695*k)+j,(635-i)*k,(640*k)+j,(610-i)*k,color);	
		
		
//		flood(630,470-i,color,15);
//		flood(705,480-i,color,15);
//		flood(560,480-i,color,15);
//		flood(585,635-i,color,15);
//		flood(655,625-i,color,15);
		

		
		XuatTTEllipDuong((630*k)+j,((480-i)*k),22*k,180*k,1110,150,"Ellip");
		XuatToaDoDuong((820*k)+j,(535-i)*k,1110,265,"CP");
		XuatToaDoDuong((435*k)+j,(535-i)*k,1110,220,"CT");
		XuatToaDoDuong((555*k)+j,(660-i)*k,1110,310,"DT");
		XuatToaDoDuong((700*k)+j,(660-i)*k,1110,355,"DP");
	    delay(500);
		
		setfillstyle(SOLID_FILL,15);
		if(i<170){
			bar((420*k)+j,(280-i)*k,(835*k)+j,(670-i)*k);
			initWorkStationDuong();	
		}
	
		k-=(0.003*multi);
		j+=(1.9*multi);
		
		if(i>160){
		//Draw panel top
		button(WIDTH_PANEL_LEFT, 0, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP, 8, "VE HINH CO BAN", 5, 5, 14);
		}
		
	}
	}


