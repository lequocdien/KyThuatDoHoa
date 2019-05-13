#include "object.h"

//Tra ve 1 diem ma co tao do x, toa do y deu chia het cho 5
int LamTronToaDo(int toaDo){
	int soDu = toaDo % 5;
	if(soDu >= 3){
		return toaDo + 5 - soDu;
	}
	else if(soDu < 3){
		return toaDo - soDu;
	}
}

//Tao cac diem hinh hop chu nhat trong he toa do OXYZ
DIEM_3D* DSDiemTrongOXYZ(int x, int y, int z, int chieuRong, int chieuDai, int chieuCao){
	//Thu tu cac dinh dat theo nguoc chieu kim dong ho, dinh 0 la dinh ben trai-phia tren-phia truoc
	static DIEM_3D rectangularPoints[8];
	
//	rectangularPoints[0].toaDoX =x;
//	rectangularPoints[0].toaDoY =y;
//	rectangularPoints[0].toaDoZ =z;
//	
//	rectangularPoints[1].toaDoX =x+chieuDai;
//	rectangularPoints[1].toaDoY =y;
//	rectangularPoints[1].toaDoZ =z;
//	
//	rectangularPoints[2].toaDoX =x+chieuDai;
//	rectangularPoints[2].toaDoY =y+chieuRong;
//	rectangularPoints[2].toaDoZ =z;
//	
//	rectangularPoints[3].toaDoX =x;
//	rectangularPoints[3].toaDoY =y+chieuRong;
//	rectangularPoints[3].toaDoZ =z;
//	
//	rectangularPoints[4].toaDoX =x;
//	rectangularPoints[4].toaDoY =y;
//	rectangularPoints[4].toaDoZ =z+chieuCao;
//	
//	rectangularPoints[5].toaDoX =x+chieuDai;
//	rectangularPoints[5].toaDoY =y;
//	rectangularPoints[5].toaDoZ =z+chieuCao;
//	
//	rectangularPoints[6].toaDoX =x+chieuDai;
//	rectangularPoints[6].toaDoY =y+chieuRong;
//	rectangularPoints[6].toaDoZ =z+chieuCao;
//	
//	rectangularPoints[7].toaDoX =x;
//	rectangularPoints[7].toaDoY =y+chieuRong;
//	rectangularPoints[7].toaDoZ =z+chieuCao;
	
	rectangularPoints[0].toaDoX =x;
	rectangularPoints[0].toaDoY =y;
	rectangularPoints[0].toaDoZ =z;
	
	rectangularPoints[1].toaDoX =x+chieuDai;
	rectangularPoints[1].toaDoY =y;
	rectangularPoints[1].toaDoZ =z;
	
	rectangularPoints[2].toaDoX =x+chieuDai;
	rectangularPoints[2].toaDoY =y;
	rectangularPoints[2].toaDoZ =z+chieuCao;
	
	rectangularPoints[3].toaDoX =x;
	rectangularPoints[3].toaDoY =y;
	rectangularPoints[3].toaDoZ =z+chieuCao;
	
	rectangularPoints[4].toaDoX =x;
	rectangularPoints[4].toaDoY =y-chieuRong;
	rectangularPoints[4].toaDoZ =z;
	
	rectangularPoints[5].toaDoX =x+chieuDai;
	rectangularPoints[5].toaDoY =y-chieuRong;
	rectangularPoints[5].toaDoZ =z;
	
	rectangularPoints[6].toaDoX =x+chieuDai;
	rectangularPoints[6].toaDoY =y-chieuRong;
	rectangularPoints[6].toaDoZ =z+chieuCao;
	
	rectangularPoints[7].toaDoX =x;
	rectangularPoints[7].toaDoY =y-chieuRong;
	rectangularPoints[7].toaDoZ =z+chieuCao;
	
	return rectangularPoints;
	
}

//Chuyen cac diem tu he toa do OXYZ sang he toa do OXY
DIEM* ConvertToOXY(DIEM_3D *dsDiem){
	static DIEM dsDiemOXY[8];
	for(int i = 0; i< 8; i++){
		dsDiemOXY[i].toaDoX = LamTronToaDo(dsDiem[i].toaDoX - dsDiem[i].toaDoZ*sqrt(2)/2);
		dsDiemOXY[i].toaDoY = LamTronToaDo(dsDiem[i].toaDoY - dsDiem[i].toaDoZ*sqrt(2)/2);
	}
	return dsDiemOXY;
}

//Chuyen cac diem tu he toa do OXY sang he toa do OXYZ
//DIEM_3D* ConvertToOXY(DIEM *dsDiem){
//	static DIEM_3D dsDiemOXYZ[8];
//	for(int i = 0; i< 8; i++){
//		dsDiemOXYZ[i].toaDoX = dsDiem[i].toaDoX - LamTronDiem(dsDiem[i].toaDoY*sqrt(2)/2);
//		dsDiemOXYZ[i].toaDoY = dsDiem[i].toaDoZ - LamTronDiem(dsDiem[i].toaDoY*sqrt(2)/2);
//	}
//	return dsDiemOXYZ;
//}

//Put 1 hinh tron co ban kinh la 3 Pixel
void putPixel(int x, int y, int color){
	setcolor(color);
	setfillstyle(1, color);
	fillellipse(x, y, 3, 3);
}

// Thuat toan DDA ve duong thang
void lineDDA(int x1, int y1, int x2, int y2){       
	int color = 1;
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putPixel(LamTronToaDo(x),LamTronToaDo(y),color);
      
    int k=1;
    while(k <=step){
        k++;
        delay(1);  
        x += x_inc;
        y += y_inc;
//        cout<<"x="<<x<<"\ty="<<y<<endl;
		putPixel(LamTronToaDo(x),LamTronToaDo(y),color);
    }
}

// Thuat toan DDA ve duong thang net dut
void lineBrokenDDA(int x1, int y1, int x2, int y2){       
	int color = 1;
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putPixel(LamTronToaDo(x),LamTronToaDo(y),color);
      
    int k=1;
    int dem = 0;
    while(k <=step){
		k++;
        delay(1);  
        x += x_inc;
        y += y_inc;
//        cout<<"x="<<x<<"\ty="<<y<<endl;
        if(dem < 25)
        {
			putPixel(LamTronToaDo(x),LamTronToaDo(y),color);
		}
		dem = dem + 1;
		if(dem == 50)
		{
			dem = 0;
		}
    }
}

//Ve hinh hop chu nhat (input is 4 arguments)
void veHinhChuNhat(){
//	DIEM_3D* dsDiemOXYZ = DSDiemTrongOXYZ(450, 45, 400, 250, 400, 300);
	DIEM_3D* dsDiemOXYZ = DSDiemTrongOXYZ(670, 700, 200, 100, 400, 100); 
	
	cout<<"\t\tDANH SACH CAC DIEM CUA HINH HOP CHU NHAT TRONG HE TOA DO OXYZ"<<endl;
	for(int i = 0; i<8; i++){
		cout<<"\t"<<dsDiemOXYZ[i].toaDoX<<"; "<<dsDiemOXYZ[i].toaDoY<<"; "<<dsDiemOXYZ[i].toaDoZ<<endl;
	}
	
	DIEM* dsDiemOXY = ConvertToOXY(dsDiemOXYZ);
	cout<<"\t\tDANH SACH CAC DIEM CUA HINH HOP CHU NHAT TRONG HE TOA DO OXY"<<endl;
	for(int i = 0; i<8; i++){
		cout<<"\t"<<dsDiemOXY[i].toaDoX<<"; "<<dsDiemOXY[i].toaDoY<<endl;
	}
	
	//Hien cac diem
	for(int i = 0; i<8; i++){
		setcolor(2);
		setfillstyle(1, 1);
		fillellipse(dsDiemOXY[i].toaDoX, dsDiemOXY[i].toaDoY, 3, 3);
		delay(100);
	}
	
	//Noi cac dinh
	lineDDA(dsDiemOXY[0].toaDoX, dsDiemOXY[0].toaDoY, dsDiemOXY[1].toaDoX, dsDiemOXY[1].toaDoY);
	lineBrokenDDA(dsDiemOXY[1].toaDoX, dsDiemOXY[1].toaDoY, dsDiemOXY[2].toaDoX, dsDiemOXY[2].toaDoY);
	lineBrokenDDA(dsDiemOXY[2].toaDoX, dsDiemOXY[2].toaDoY, dsDiemOXY[3].toaDoX, dsDiemOXY[3].toaDoY);
	lineDDA(dsDiemOXY[3].toaDoX, dsDiemOXY[3].toaDoY, dsDiemOXY[0].toaDoX, dsDiemOXY[0].toaDoY);
	
	lineDDA(dsDiemOXY[4].toaDoX, dsDiemOXY[4].toaDoY, dsDiemOXY[5].toaDoX, dsDiemOXY[5].toaDoY);
	lineDDA(dsDiemOXY[5].toaDoX, dsDiemOXY[5].toaDoY, dsDiemOXY[6].toaDoX, dsDiemOXY[6].toaDoY);
	lineDDA(dsDiemOXY[6].toaDoX, dsDiemOXY[6].toaDoY, dsDiemOXY[7].toaDoX, dsDiemOXY[7].toaDoY);
	lineDDA(dsDiemOXY[7].toaDoX, dsDiemOXY[7].toaDoY, dsDiemOXY[4].toaDoX, dsDiemOXY[4].toaDoY);
	
	lineDDA(dsDiemOXY[0].toaDoX, dsDiemOXY[0].toaDoY, dsDiemOXY[4].toaDoX, dsDiemOXY[4].toaDoY);
	lineDDA(dsDiemOXY[1].toaDoX, dsDiemOXY[1].toaDoY, dsDiemOXY[5].toaDoX, dsDiemOXY[5].toaDoY);
	lineBrokenDDA(dsDiemOXY[2].toaDoX, dsDiemOXY[2].toaDoY, dsDiemOXY[6].toaDoX, dsDiemOXY[6].toaDoY);
	lineDDA(dsDiemOXY[3].toaDoX, dsDiemOXY[3].toaDoY, dsDiemOXY[7].toaDoX, dsDiemOXY[7].toaDoY);
}

//void a(){
//	int viTriY = HEIGHT_PANEL_TOP + 50;
//	for(int i = 0; i<8; i++){
//		rectangularPoints[i].toaDoX = getNumberCharacter();
//		rectangularPoints[i].toaDoY = getNumberCharacter();
//		button(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, viTriY, getmaxx(), viTriY + 30, 8, "Diem: (...;...;...)", 9, 1, 15);
//		viTriY = viTriY + 40;
//	}
//}

//void DDALine(DIEM a, DIEM b){
//	//TODO: Kiem tra a va b diem nao nam truoc
//	DIEM nextPoint = a;
//	if(a.toaDoX > b.toaDoX && a.toaDoY > b.toaDoY){
//		while(nextPoint.toaDoX >= b.toaDoX){
//			putPixel(nextPoint, 1);
//			nextPoint.toaDoX = nextPoint.toaDoX - 5;
//			nextPoint.toaDoY = nextPoint.toaDoY - 13/87;
//			LamTronDiem(nextPoint);
//			delay(200);
//		}
//	}
//	else if(a.toaDoX <= b.toaDoX && a.toaDoY <= b.toaDoY){
//		while(nextPoint.toaDoX >= b.toaDoX){
//			putPixel(nextPoint, 1);
//			nextPoint.toaDoX = nextPoint.toaDoX + 1;
//			nextPoint.toaDoY = nextPoint.toaDoY + 1;
//			LamTronDiem(nextPoint);
//			delay(200);
//		}
//	}
//	else if(a.toaDoX >= b.toaDoX && a.toaDoY <= b.toaDoY){
//		while(nextPoint.toaDoX >= b.toaDoX){
//			putPixel(nextPoint, 1);
//			nextPoint.toaDoX = nextPoint.toaDoX + 1;
//			nextPoint.toaDoY = nextPoint.toaDoY + 1;
//			delay(200);
//		}
//	}
//	else if(a.toaDoX <= b.toaDoX && a.toaDoY <= b.toaDoY){
//		while(nextPoint.toaDoX >= b.toaDoX){
//			putPixel(nextPoint, 1);
//			nextPoint.toaDoX = nextPoint.toaDoX + 1;
//			nextPoint.toaDoY = nextPoint.toaDoY + 1;
//			delay(200);
//		}
//	}
//}



//void VeHinhHop(){
//	//Noi dinh 0 voi dinh 1
//	line(ToaDoCacDiemXTrong2Chieu[0], ToaDoCacDiemYTrong2Chieu[0], ToaDoCacDiemXTrong2Chieu[1], ToaDoCacDiemYTrong2Chieu[1]);
//	delay(200);
//	//Noi dinh 1 voi dinh 2
//	line(ToaDoCacDiemXTrong2Chieu[1], ToaDoCacDiemYTrong2Chieu[1], ToaDoCacDiemXTrong2Chieu[2], ToaDoCacDiemYTrong2Chieu[2]);
//	//Noi dinh 2 voi dinh 3 
//	line(ToaDoCacDiemXTrong2Chieu[2], ToaDoCacDiemYTrong2Chieu[2], ToaDoCacDiemXTrong2Chieu[3], ToaDoCacDiemYTrong2Chieu[3]);
//	//Noi dinh 3 voi dinh 0
//	line(ToaDoCacDiemXTrong2Chieu[3], ToaDoCacDiemYTrong2Chieu[3], ToaDoCacDiemXTrong2Chieu[0], ToaDoCacDiemYTrong2Chieu[0]);
//	//Noi dinh 4 voi dinh 5
//	line(ToaDoCacDiemXTrong2Chieu[4], ToaDoCacDiemYTrong2Chieu[4], ToaDoCacDiemXTrong2Chieu[5], ToaDoCacDiemYTrong2Chieu[5]);
//	//Noi dinh 5 voi dinh 6
//	line(ToaDoCacDiemXTrong2Chieu[5], ToaDoCacDiemYTrong2Chieu[5], ToaDoCacDiemXTrong2Chieu[6], ToaDoCacDiemYTrong2Chieu[6]);
//	//Noi dinh 6 voi dinh 7
//	line(ToaDoCacDiemXTrong2Chieu[6], ToaDoCacDiemYTrong2Chieu[6], ToaDoCacDiemXTrong2Chieu[7], ToaDoCacDiemYTrong2Chieu[7]);
//	//Noi dinh 7 voi dinh 4
//	line(ToaDoCacDiemXTrong2Chieu[7], ToaDoCacDiemYTrong2Chieu[7], ToaDoCacDiemXTrong2Chieu[4], ToaDoCacDiemYTrong2Chieu[4]);
//	//Noi dinh 0 voi dinh 4
//	line(ToaDoCacDiemXTrong2Chieu[0], ToaDoCacDiemYTrong2Chieu[0], ToaDoCacDiemXTrong2Chieu[4], ToaDoCacDiemYTrong2Chieu[4]);
//	//Noi dinh 1 voi dinh 5
//	line(ToaDoCacDiemXTrong2Chieu[1], ToaDoCacDiemYTrong2Chieu[1], ToaDoCacDiemXTrong2Chieu[5], ToaDoCacDiemYTrong2Chieu[5]);
//	//Noi dinh 2 voi dinh 6
//	line(ToaDoCacDiemXTrong2Chieu[2], ToaDoCacDiemYTrong2Chieu[2], ToaDoCacDiemXTrong2Chieu[6], ToaDoCacDiemYTrong2Chieu[6]);
//	//Noi dinh 3 voi dinh 7
//	line(ToaDoCacDiemXTrong2Chieu[3], ToaDoCacDiemYTrong2Chieu[3], ToaDoCacDiemXTrong2Chieu[7], ToaDoCacDiemYTrong2Chieu[7]);
//}  

