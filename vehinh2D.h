#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include "BackGround.h"
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
#define DELAY 10
#include <conio.h>
#define ROUND(a) (int)(a+0.5)
#include <conio.h>
#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void XuatToaDo(int x,int y,int a1,int a2)
{
	int tdx,tdy,tempx,tempy;
	if((x%5)>=3)
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

	//outtextxy(1200,250,"    ");1150,250
	
	settextstyle(1,0,2);
	outtextxy(a1-50,a2+50,"   ");
	outtextxy(a1-50,a2+50,a);
	settextstyle(1,0,2);
	outtextxy(a1+10,a2+50,";");
	settextstyle(1,0,2);
	outtextxy(a1+30,a2+50,"   ");
	outtextxy(a1+30,a2+50,b);
	
	}
	void XuatToaDoClick(int x,int y)
{
	int tdx,tdy,tempx,tempy;
	if((x%5)>=3)
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
	if(tempx<=700)
	{
		tdx=(tempx/5)-140;
		tdy=88-(tempy/5);
	}
	if(tempx>=700)
	{
		tdx=(tempx/5)-140;
		tdy=88-(tempy/5);
	}
	
	char a[4];
	char b[4];
	_itoa(tdx,a,10);
	_itoa(tdy,b,10);
    setbkcolor(8);
    setcolor(YELLOW);
    settextstyle(1,0,2);
    outtextxy(1130,570,"Cac diem khac");
    outtextxy(1130,600,"Toa do x=");
	outtextxy(1280,600,"       ");
	outtextxy(1280,600,a);
	outtextxy(1130,630,"Toa do y=");
	outtextxy(1280,630,"       ");
	outtextxy(1280,630,b);
	
	}
	
void goxy(int &x, int &y, char s[],int color)
{
	setcolor(RED);
	setbkcolor(color);
	outtextxy(x, y, s);
	x += textwidth(s);
}
void initGridDai(int x, int y, int a, int b){
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
void initHeToaDoDai(int x, int y, int a, int b){
	int medianX = 500 + WIDTH_PANEL_LEFT;		//NOTE: Cap nhat khi co su thay doi
	int medianY = 380 + HEIGHT_PANEL_TOP;		//NOTE: Cap nhat khi co su thay doi
	setcolor(4);
	line(medianX, y, medianX, b);
	line(x, medianY, a, medianY);
}
void initWorkStationDai(){
	initGridDai(WIDTH_PANEL_LEFT + 10, HEIGHT_PANEL_TOP + 10, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN - 10, getmaxy() - 10);
	initHeToaDoDai(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy());
}
void HeToaDo2ChieuDai()
{
	initHeToaDoDai(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy());
}
void vehcn(int x,int y,int z,int b,int color)
{
	setfillstyle(SOLID_FILL,color);	
	setcolor(BLACK);
	rectangle(x,y,z,b);
	setbkcolor(color);
	bar(x+1,y+1,z,b);
}
int lamtron(int x)
{
	int a,sodu;
	sodu=x%5;
	if(sodu>=3)
	{
		a=x+5-sodu;
	}
	else{
		a=x-sodu;
	}
	return a;
}
void putPixelDai(int x,int y,int color)
{
	int X=lamtron(x);
	int Y=lamtron(y);
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
void lineDDADai(int x1, int y1, int x2, int y2,int Color){       // thuat toan DDA
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
    putpixel(x, y, Color);
      
    int k=1;
    while(k <=step){
        k++;
        x += x_inc;
        y += y_inc;
        putPixelDai(Round(x),Round(y),Color);       
    }
}
void Line_OX(int x1, int x2, int y,int c){
for(int x=x1;x<=x2;x++)
{
   putPixelDai(x,y,c);

   }
}
void pc(int xc,int yc, int x, int y, int c){
 putPixelDai(xc + x, yc + y, c);
 putPixelDai(xc - x, yc - y, c);
 putPixelDai(xc -y, yc +x, c);
 putPixelDai(xc +y, yc -x, c);
}
void Mid_circle(int xc, int yc, int r, int c)
{
  int x, y, d;
  x = 0;
  y = r;
  d = 1- r;
  pc(xc,yc, r,0,c); //ve 4 diem dac biet

  while (x <= y)
  {
    pc(xc,yc, x,y,c);  
    pc(xc,yc, y,x,c);
    if (d< 0)
       d +=2 * x + 3;
    else
   {
      d += 2 * (x-y) + 5;
      y--;
   }
   x++;
   pc(xc,yc, x,y,c);
   pc(xc,yc, y,x,c);

   
 }
 pc(xc,yc, y,y,c); // ve 4 diem phan giac x=y
}

void plot(int xc, int yc, int x, int y, int color)
{
    putPixelDai(xc+x, yc+y, color);
    putPixelDai(xc-x, yc+y, color);
    putPixelDai(xc+x, yc-y, color);
    putPixelDai(xc-x, yc-y, color);
}
void elipMidpoint(int xc,int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    plot(xc, yc, x, y, color);
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
        plot(xc, yc, x, y, color);

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
        plot(xc, yc, x, y, color);
//        plot(xc, yc, x+1, y, color);
//        plot(xc, yc, x+2, y, color);
//        plot(xc, yc, x-1, y, color);
//        plot(xc, yc, x-2, y, color);
    }
}


typedef struct
{
    int x;
    int y;
}Points;
Points XacDinh(Points Tam, int R, int G)
{
    Points Kq;
    Kq.x=Tam.x+R*cos(G*M_PI/180);
    Kq.y=Tam.y+R*sin(G*M_PI/180);
    return Kq;
}
void Vechongchong(Points Tam, int R, int gbd,int color){
    setcolor(color);
    Points d1;
    d1=XacDinh(Tam,R,gbd);
    lineDDADai(Tam.x,Tam.y,d1.x,d1.y,color);
    setfillstyle(SOLID_FILL, RED);
    setcolor(RED);
    circle(Tam.x,Tam.y,10);
    floodfill(Tam.x,Tam.y, RED);
	setbkcolor(RED);
}
void Sticks()
{
	lineDDADai(900,300,900,500,BLUE);
}
void QuatGio()
{
	Points Tam;
    Tam.x=900;
    Tam.y=300;
    int R=100;
    int gbd=270+45;
    int gbd2=90+45;
    int gbd3=0+45;
    int gbd4=180+45;
    int color=0;
    Vechongchong(Tam,R,gbd,color);
    Vechongchong(Tam,R,gbd2,color);

    

    
}
void QuatGioWhite()
{
	Points Tam;
    Tam.x=900;
    Tam.y=300;
    int R=100;
    int gbd=270+45;
    int gbd2=90+45;
    int gbd3=0+45;
    int gbd4=180+45;
    int color=15;
    Vechongchong(Tam,R,gbd,color);
    Vechongchong(Tam,R,gbd2,color);

    

    
}
void Tree()
{
Line_OX(430,550,600,BLUE);
lineDDADai(430,600,490,350,BLUE);
lineDDADai(550,600,490,350,BLUE);
flood(490,440,0,4);
flood(490,400,15,0);
flood(490,400,BROWN,15);
//Elip
elipMidpoint(490,220,180,130,BLUE);
flood(490,220,15,0);
flood(490,220,GREEN,15);
//Canh
//Mid_circle(620,270,10,YELLOW);
//settextstyle(1,0,2);
setbkcolor(8);
setcolor(YELLOW);

settextstyle(1,0,2);
outtextxy(1200,70,"Elip");
settextstyle(1,0,2);
XuatToaDo(490,220,1200,50);
outtextxy(1110,130,"Ban kinh X=36");
outtextxy(1110,150,"Ban kinh Y=26");
}
void Person()
{
	Mid_circle(600+10,480,20,BLUE);
	//xuat toa do
	setbkcolor(8);
    setcolor(YELLOW);
    settextstyle(1,0,2);
    outtextxy(1130,200,"Person's head");
    XuatToaDo(610,480,1200,180);
    outtextxy(1110,250,"Ban kinh R=4");
	//Co
	lineDDADai(595+10,500,595+10,515,BLUE);
	lineDDADai(605+10,500,605+10,515,BLUE);
	//Than
	Line_OX(570+10,597+10,515,BLUE);
	Line_OX(603+10,630+10,515,BLUE);
	lineDDADai(580,513,580,600,BLUE);
	lineDDADai(640,513,640,600,BLUE);
	Line_OX(580,640,600,BLUE);
	//Chan
	Line_OX(640,700,600,BLUE);
	Line_OX(640,700,580,BLUE);
	lineDDADai(700,580,700,600,BLUE);
	lineDDADai(640,515,670,560,BLUE);
	//lineDDA(660,560,670,560,BLUE);
	Line_OX(660,670,560,BLUE);
	lineDDADai(640,530,660,560,BLUE);
	//eye
	Line_OX(615,620,475,BROWN);
	
}

void DrawTree()
{
	Tree();	
	Mid_circle(620,320,10,YELLOW);
	Person();
	initWorkStationDai();
	setbkcolor(8);
	setcolor(YELLOW);
	settextstyle(1,0,2);
	outtextxy(1180,320,"Apple");
	XuatToaDo(620,320,1200,300);
	//QuatGio();


}
void MoveApple()
{
	Points Tam;
    Tam.x=900;
    Tam.y=300;
    int R=100;
    int gbd=270+45;
    int gbd2=90+45;
    int gbd3=0+45;
    int gbd4=180+45;
    int color=0;
	int a=320;
	int b=620;
	int c=0;
	int t=0;
    for(int i=1;i<126;i+=5)
    {
    	setfillstyle(SOLID_FILL, 15);
        setcolor(15);
		circle(620, 310+i, 20);
		floodfill(620, 310+i, 15);
		setbkcolor(15);
		a+=5;
		initWorkStationDai();
    	
        Mid_circle(620,320+i,10,YELLOW);
        if(a>=330&&a<=340)
        {
		    elipMidpoint(490,220,180,130,BLUE);
        	//Tree();
		}
		setbkcolor(8);
	    setcolor(YELLOW);
	    settextstyle(1,0,2);
		XuatToaDo(620,320+i,1200,300);
		t=t+10;
        Vechongchong(Tam,R,gbd+t,color);
        Vechongchong(Tam,R,gbd2+t,color);
        Sticks();
        Vechongchong(Tam,R,gbd+t,15);
        Vechongchong(Tam,R,gbd2+t,15);
        initWorkStationDai();
        //delay(10);
        
		
		
	}
	int e=620;
	if(a==445)
		{
		for(int i=1;i<31;i+=5)
		{
		setfillstyle(SOLID_FILL, 15);
        setcolor(15);
		circle(615+i, a, 20);
		floodfill(615+i, a, 15);
		setbkcolor(15);
		
		b+=5;
		initWorkStationDai();
		Mid_circle(620+i,a,10,YELLOW);
        e++;
        if(e>=620&&e<=640)
        {
        	Mid_circle(600+10,480,20,BLUE);
		}
		setbkcolor(8);
	    setcolor(YELLOW);
	    settextstyle(1,0,2);
        XuatToaDo(620+i,a,1200,300);
		t=t+10;
        Vechongchong(Tam,R,gbd+t,color);
        Vechongchong(Tam,R,gbd2+t,color);
        Sticks();
        Vechongchong(Tam,R,gbd+t,15);
        Vechongchong(Tam,R,gbd2+t,15);
        initWorkStationDai();
		}
	}
	if(b==650)
	{
		for(int i=1;i<151;i+=10)
		{
		setfillstyle(SOLID_FILL, 15);
        setcolor(15);
		circle(b, 430+i, 20);
		floodfill(b, 430+i, 15);
		setbkcolor(15);
		initWorkStationDai();
		Mid_circle(b,445+i,10,YELLOW);
		setbkcolor(8);
	    setcolor(YELLOW);
	    settextstyle(1,0,2);
		XuatToaDo(b,445+i,1200,300);
		t=t+10;
        Vechongchong(Tam,R,gbd+t,color);
        Vechongchong(Tam,R,gbd2+t,color);
        Sticks();
        Vechongchong(Tam,R,gbd+t,15);
        Vechongchong(Tam,R,gbd2+t,15);
        initWorkStationDai();
        // ve lai Person();
    Mid_circle(600+10,480,20,BLUE);
    Line_OX(603+10,630+10,515,BLUE);
    lineDDADai(640,513,640,600,BLUE);
	Line_OX(580,640,600,BLUE);
    Line_OX(640,700,600,BLUE);
	Line_OX(640,700,580,BLUE);
	lineDDADai(700,580,700,600,BLUE);
	lineDDADai(640,515,670,560,BLUE);
	Line_OX(660,670,560,BLUE);
	lineDDADai(640,530,660,560,BLUE);
	c+=10;
		}
		
	}
     if(c==150)
     {
     	
     	
	    setbkcolor(15);
	    setcolor(BLUE);
	    settextstyle(1,0,2);
     	outtextxy(610,430,"WHY???");
     	initWorkStationDai();
	 }
	Tree();
	Person();
	setbkcolor(15);
	setcolor(BLACK);
	settextstyle(1,0,2);
	outtextxy(740,150,"MOI VAT DEU CO");
	outtextxy(740,180,"TRONG LUC!!!");
	QuatGio();
    initWorkStationDai();
}


