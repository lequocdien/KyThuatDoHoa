#include "object.h"

//
void initGUIInfoHinhHop(){
	int viTriY = 65;	//NOTE: Update khi thay doi
	settextstyle(10, 0, 1);	//NOTE: Update khi thay doi
	setbkcolor(8);			//NOTE: Update khi thay doi
	setcolor(15);	//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "A (    ;   ;    )"); 	viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "Chieu dai:     ");		viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "Chieu rong:    "); 		viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "Chieu cao:     "); 
}

void initGUIInfoHinhTru(){
	int viTriY = 65;	//NOTE: Update khi thay doi
	settextstyle(10, 0, 1);	//NOTE: Update khi thay doi
	setbkcolor(8);			//NOTE: Update khi thay doi
	setcolor(15);	//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "Tam 1 (    ;   ;    )"); 	viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "Ban kinh:     ");		viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "Chieu cao:    "); 
}

//Ve he toa do 3 chieu
void initHeToaDo3Chieu(int x, int y, int a, int b){
	setfillstyle(1, 12);
	
	//Ve OX
	bar(GOC_TOA_DO_X - 2, GOC_TOA_DO_Y - 2, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, GOC_TOA_DO_Y + 2);	
	
	//Ve OY
	bar(GOC_TOA_DO_X - 2, GOC_TOA_DO_Y - 2, GOC_TOA_DO_X + 2, HEIGHT_PANEL_TOP+2);					  	
	
	//Ve OZ
	setcolor(12);																		
	for(int i = -3; i<=2; i++){
		line(GOC_TOA_DO_X + i, GOC_TOA_DO_Y, WIDTH_PANEL_LEFT + i, GOC_TOA_DO_Y - (GOC_TOA_DO_X - WIDTH_PANEL_LEFT - 10));			
	}
	
	setcolor(14);
	//Chia truc OX
	for(int i = GOC_TOA_DO_X + 50; i < WIDTH_PANEL_MAIN + WIDTH_PANEL_LEFT; i = i + 50){
		line(i, GOC_TOA_DO_Y -5, i, GOC_TOA_DO_Y + 5);
	}
	
	//Chia truc OY
	for(int i = 35; i < GOC_TOA_DO_X - WIDTH_PANEL_LEFT - 10; i = i + 35){ //35 = sqrt(50*50/2)
		line(GOC_TOA_DO_X - i - 15, GOC_TOA_DO_Y - i - 5, GOC_TOA_DO_X - i + 5, GOC_TOA_DO_Y - i - 5);
	}
	
	//Chia truc OZ
	for(int i = GOC_TOA_DO_Y -50; i > HEIGHT_PANEL_TOP; i = i - 50){
		line(GOC_TOA_DO_X - 5, i, GOC_TOA_DO_X + 5, i);
	}
	
	//Add nhan co toa do
	button(635, 75, 645, 85, 15, "Z", 10, 1, 12);
	button(215, 205, 225, 215, 15, "Y", 10, 1, 12);
	button(1075, 635, 1085, 645, 15, "X", 10, 1, 12);
}

//Khoi tao he toa do 3 chieu va luoi
void initWorkStation(){
	initGrid(WIDTH_PANEL_LEFT + 10, HEIGHT_PANEL_TOP + 10, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN - 10, getmaxy() - 10);
	initHeToaDo3Chieu(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy());
}

//Xu ly du lieu dau vao
void luiLaiKhiXoa(int &x, int &y, char kyTuCuoiCung[]){
	settextstyle(10,0,1);
	setcolor(15);
	setbkcolor(8);
	x = x - textwidth(kyTuCuoiCung);
	outtextxy(x, y, "_");
}

void ghiTextTaiViTriXY(int &x, int &y, char s[], int color)
{
	settextstyle(10,0,1);
	setcolor(15);
	setbkcolor(color);
	outtextxy(x, y, s);
	x += textwidth(s);
}

//Nhan ky tu so tu ban phim (so luong chu so toi da la 3)
int nhanKyTuTuBanPhim(int x, int y){
	char outPut[4];
	char ch[2];
	char temp;
	ch[1] = 0;
	int i = 0;

	settextstyle(10,0,1);
	setcolor(15);
	setbkcolor(8);
	while (true){
		
		outtextxy(x, y, "_");
		fflush(stdin);
		temp = getch();
		
		if (temp >= '0' && temp <= '9'){
			if (i<3)
			{			
				ch[0] = temp;
				ghiTextTaiViTriXY(x, y, ch, 8);
				outPut[i++] = ch[0];
			}
		}
	    else if (temp == 8){
			if(i > 0)
			{
				outtextxy(x, y, " ");
				luiLaiKhiXoa(x, y, ch);
				i--;
			}
		}
		else if (temp == 13)
		{
			outtextxy(x, y, " ");
			break;
		}
	}
	outPut[i] = 0;
	return atoi(outPut);
}

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

//Put 1 hinh tron co ban kinh la 3 Pixel
void putPixel(int x, int y, int color){
	setcolor(color);
	setfillstyle(1, color);
	fillellipse(x, y, 3, 3);
}

void put4Pixels(int x, int y, int toaDoTamX, int toaDoTamY){
	putPixel(x + toaDoTamX, y + toaDoTamY, 1);
	putPixel(-x + toaDoTamX, y + toaDoTamY, 1);
	putPixel(x + toaDoTamX, -y + toaDoTamY, 1);
	putPixel(-x + toaDoTamX, -y + toaDoTamY, 1);
}

// Thuat toan DDA ve duong thang
void lineDDA(int x1, int y1, int x2, int y2, int color){       
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
//        delay(DELAY);  
        x += x_inc;
        y += y_inc;
//        cout<<"x="<<x<<"\ty="<<y<<endl;
		putPixel(LamTronToaDo(x),LamTronToaDo(y),color);
    }
}

// Thuat toan DDA ve duong thang net dut
void lineBrokenDDA(int x1, int y1, int x2, int y2, int color){       
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putPixel(LamTronToaDo(x), LamTronToaDo(y), color);
      
    int k=1;
    int dem = 0;
    while(k <=step){
		k++;
//        delay(DELAY);  
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

//Tao cac diem hinh hop chu nhat trong he toa do OXYZ
DIEM_3D* DSDiemTrongOXYZ(int x, int y, int z, int chieuDai, int chieuRong, int chieuCao){
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
	rectangularPoints[2].toaDoZ =z-chieuCao;
	
	rectangularPoints[3].toaDoX =x;
	rectangularPoints[3].toaDoY =y;
	rectangularPoints[3].toaDoZ =z-chieuCao;
	
	rectangularPoints[4].toaDoX =x;
	rectangularPoints[4].toaDoY =y+chieuRong;
	rectangularPoints[4].toaDoZ =z;
	
	rectangularPoints[5].toaDoX =x+chieuDai;
	rectangularPoints[5].toaDoY =y+chieuRong;
	rectangularPoints[5].toaDoZ =z;
	
	rectangularPoints[6].toaDoX =x+chieuDai;
	rectangularPoints[6].toaDoY =y+chieuRong;
	rectangularPoints[6].toaDoZ =z-chieuCao;
	
	rectangularPoints[7].toaDoX =x;
	rectangularPoints[7].toaDoY =y+chieuRong;
	rectangularPoints[7].toaDoZ =z-chieuCao;
	
	return rectangularPoints;
	
}

//Chuyen cac diem tu he toa do OXYZ sang he toa do OXY
DIEM* ConvertToOXY(DIEM_3D *dsDiem){
	static DIEM dsDiemOXY[8];
	for(int i = 0; i< 8; i++){
		dsDiemOXY[i].toaDoX = LamTronToaDo(dsDiem[i].toaDoX - dsDiem[i].toaDoY*sqrt(2)/2);
		dsDiemOXY[i].toaDoY = LamTronToaDo(dsDiem[i].toaDoZ - dsDiem[i].toaDoY*sqrt(2)/2);
	}
	return dsDiemOXY;
}

//Chuyen toa do nguoi dung sang toa do may
DIEM chuyenToaDoNguoiDungSangToaDoMay(int x, int y, int z){
	DIEM diemTrenOX, diemTrenOY, diemTrenOZ, diemTrenOXY, diemBatDauVe;
	
	//Toa do tren OX
	diemTrenOX.toaDoX = LamTronToaDo(GOC_TOA_DO_X + x);
	diemTrenOX.toaDoY = LamTronToaDo(GOC_TOA_DO_Y);
	
	//Toa do tren OY
	diemTrenOY.toaDoX = LamTronToaDo(GOC_TOA_DO_X - sqrt(y*y/2));
	diemTrenOY.toaDoY = LamTronToaDo(GOC_TOA_DO_Y - sqrt(y*y/2));
	
	//Toa do diem tren OZ
	diemTrenOZ.toaDoX = LamTronToaDo(GOC_TOA_DO_X);
	diemTrenOZ.toaDoY = LamTronToaDo(GOC_TOA_DO_Y - z);
	
	//Toa do tren mat phang OXY
	diemTrenOXY.toaDoX = LamTronToaDo(diemTrenOY.toaDoX + x);
	diemTrenOXY.toaDoY = LamTronToaDo(diemTrenOY.toaDoY);
		
	//Toa do diem bat dau ve
	diemBatDauVe.toaDoX = LamTronToaDo(diemTrenOXY.toaDoX);
	diemBatDauVe.toaDoY = LamTronToaDo(diemTrenOXY.toaDoY - z);
	
	putPixel(diemTrenOX.toaDoX, diemTrenOX.toaDoY, 14);
	putPixel(diemTrenOY.toaDoX, diemTrenOY.toaDoY, 14);
	putPixel(diemTrenOXY.toaDoX, diemTrenOXY.toaDoY, 14);
	putPixel(diemBatDauVe.toaDoX, diemBatDauVe.toaDoY, 14);
	putPixel(diemTrenOZ.toaDoX, diemTrenOZ.toaDoY, 14);
	
	lineBrokenDDA(diemTrenOX.toaDoX, diemTrenOX.toaDoY, diemTrenOXY.toaDoX, diemTrenOXY.toaDoY, 14);
	lineBrokenDDA(diemTrenOY.toaDoX, diemTrenOY.toaDoY, diemTrenOXY.toaDoX, diemTrenOXY.toaDoY, 14);
	lineBrokenDDA(diemTrenOXY.toaDoX, diemTrenOXY.toaDoY, diemBatDauVe.toaDoX, diemBatDauVe.toaDoY, 14);
	lineBrokenDDA(GOC_TOA_DO_X, GOC_TOA_DO_Y, diemTrenOXY.toaDoX, diemTrenOXY.toaDoY, 14);
	lineBrokenDDA(diemBatDauVe.toaDoX, diemBatDauVe.toaDoY, diemTrenOZ.toaDoX, diemTrenOZ.toaDoY, 14);
	
	return diemBatDauVe;
}

//Tinh tien
void tinhTien(int &x, int &y, int dx, int dy){
	x = x + dx;
	y = y + dy;
}

void ghiToaDoOXYZ(int viTriBatDauX, int &viTriBatDauY, int giaTriX, int giaTriY, int giaTriZ){
	char tmp[4];
	_itoa(giaTriX, tmp, 10); outtextxy(viTriBatDauX, viTriBatDauY, tmp); outtextxy(viTriBatDauX + 40, viTriBatDauY, ";"); viTriBatDauX = viTriBatDauX + 50;
	_itoa(giaTriY, tmp, 10); outtextxy(viTriBatDauX, viTriBatDauY, tmp); outtextxy(viTriBatDauX + 40, viTriBatDauY, ";"); viTriBatDauX = viTriBatDauX + 50;
	_itoa(giaTriZ, tmp, 10); outtextxy(viTriBatDauX, viTriBatDauY, tmp); outtextxy(viTriBatDauX + 40, viTriBatDauY, ")");
}
//Hien thi thong tin hinh tru
void showInfoHinhHop(int x, int y, int z, int chieuDai, int chieuRong, int chieuCao){
	int viTriY = 185;	//NOTE: Update khi thay doi
	settextstyle(10, 0, 1);	//NOTE: Update khi thay doi
	setbkcolor(8);			//NOTE: Update khi thay doi
	setcolor(15);	//NOTE: Update khi thay doi
	
	//Chuyen cac toa do cua dang so sang dang text
	char tmp[4];
	outtextxy(1105, viTriY, "B ("); ghiToaDoOXYZ(1140, viTriY, x/5 + chieuDai/5, y/5, z/5); viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "C ("); ghiToaDoOXYZ(1140, viTriY, x/5 + chieuDai/5, y/5 + chieuRong/5, z/5); viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "D ("); ghiToaDoOXYZ(1140, viTriY, x/5, y/5 + chieuRong/5, z/5); viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "E ("); ghiToaDoOXYZ(1140, viTriY, x/5, y/5, z/5 + chieuCao/5); viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "F ("); ghiToaDoOXYZ(1140, viTriY, x/5 + chieuDai/5, y/5, z/5 + chieuCao/5); viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "G ("); ghiToaDoOXYZ(1140, viTriY, x/5 + chieuDai/5, y/5 + chieuRong/5, z/5 + chieuCao/5); viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "H ("); ghiToaDoOXYZ(1140, viTriY, x/5, y/5 + chieuRong/5, z/5 + chieuCao/5);
}

//Ve hinh hop chu nhat (input is 4 arguments)
void veHinhChuNhat(int x, int y, int z, int chieuDai, int chieuRong, int chieuCao){
	
	//Tinh toan cac diem con lai cua hinh hop dua tren diem bat dau, chieu dai, chieu rong, chieu cao.	
	DIEM_3D* dsDiemOXYZ = DSDiemTrongOXYZ(GOC_TOA_DO_X, 0, GOC_TOA_DO_Y, chieuDai, chieuRong, chieuCao); 
	cout<<"\t\tDANH SACH CAC DIEM CUA HINH HOP CHU NHAT TRONG HE TOA DO OXYZ"<<endl;
	for(int i = 0; i<8; i++){
		cout<<"\t"<<dsDiemOXYZ[i].toaDoX<<"; "<<dsDiemOXYZ[i].toaDoY<<"; "<<dsDiemOXYZ[i].toaDoZ<<endl;
	}
	
	//Chuyen diem tu he toa do OXYZ sang he toa do OXY
	DIEM* dsDiemOXY = ConvertToOXY(dsDiemOXYZ);
	cout<<"\t\tDANH SACH CAC DIEM CUA HINH HOP CHU NHAT TRONG HE TOA DO OXY CHUA TINH TIEN"<<endl;
	for(int i = 0; i<8; i++){
		cout<<"\t"<<dsDiemOXY[i].toaDoX<<"; "<<dsDiemOXY[i].toaDoY<<endl;
	}
	
	//Tao diem bat dau ve tai vi tri co toa do (x, y, z) trong he toa do nguoi dung
	DIEM diemBatDauVe = chuyenToaDoNguoiDungSangToaDoMay(x, y, z);
	
	//Tinh tien hinh hop tu goc toa do den diem nguoi dung chi dinh - chuyen toan bo cac diem cua hinh hop 
	int dx = diemBatDauVe.toaDoX - GOC_TOA_DO_X;
	int dy = diemBatDauVe.toaDoY - GOC_TOA_DO_Y;
	for(int i = 0; i<8; i++){
		tinhTien(dsDiemOXY[i].toaDoX, dsDiemOXY[i].toaDoY, dx, dy);
	}
	cout<<"\t\tDANH SACH CAC DIEM CUA HINH HOP CHU NHAT TRONG HE TOA DO OXY DA TINH TIEN"<<endl;
	for(int i = 0; i<8; i++){
		cout<<"\t"<<dsDiemOXY[i].toaDoX<<"; "<<dsDiemOXY[i].toaDoY<<endl;
	}
	
	//Hien cac diem cua hinh hop
	for(int i = 0; i<8; i++){
		setcolor(2);
		setfillstyle(1, 1);
		fillellipse(dsDiemOXY[i].toaDoX, dsDiemOXY[i].toaDoY, 3, 3);
		delay(100);
	}
	
	//Noi cac dinh
	lineDDA(dsDiemOXY[0].toaDoX, dsDiemOXY[0].toaDoY, dsDiemOXY[1].toaDoX, dsDiemOXY[1].toaDoY, 1);
	lineDDA(dsDiemOXY[1].toaDoX, dsDiemOXY[1].toaDoY, dsDiemOXY[2].toaDoX, dsDiemOXY[2].toaDoY, 1);
	lineDDA(dsDiemOXY[2].toaDoX, dsDiemOXY[2].toaDoY, dsDiemOXY[3].toaDoX, dsDiemOXY[3].toaDoY, 1);
	lineDDA(dsDiemOXY[3].toaDoX, dsDiemOXY[3].toaDoY, dsDiemOXY[0].toaDoX, dsDiemOXY[0].toaDoY, 1);
	
	lineBrokenDDA(dsDiemOXY[4].toaDoX, dsDiemOXY[4].toaDoY, dsDiemOXY[5].toaDoX, dsDiemOXY[5].toaDoY, 1);
	lineBrokenDDA(dsDiemOXY[5].toaDoX, dsDiemOXY[5].toaDoY, dsDiemOXY[6].toaDoX, dsDiemOXY[6].toaDoY, 1);
	lineDDA(dsDiemOXY[6].toaDoX, dsDiemOXY[6].toaDoY, dsDiemOXY[7].toaDoX, dsDiemOXY[7].toaDoY, 1);
	lineDDA(dsDiemOXY[7].toaDoX, dsDiemOXY[7].toaDoY, dsDiemOXY[4].toaDoX, dsDiemOXY[4].toaDoY, 1);
	
	lineDDA(dsDiemOXY[0].toaDoX, dsDiemOXY[0].toaDoY, dsDiemOXY[4].toaDoX, dsDiemOXY[4].toaDoY, 1);
	lineBrokenDDA(dsDiemOXY[1].toaDoX, dsDiemOXY[1].toaDoY, dsDiemOXY[5].toaDoX, dsDiemOXY[5].toaDoY, 1);
	lineDDA(dsDiemOXY[2].toaDoX, dsDiemOXY[2].toaDoY, dsDiemOXY[6].toaDoX, dsDiemOXY[6].toaDoY, 1);
	lineDDA(dsDiemOXY[3].toaDoX, dsDiemOXY[3].toaDoY, dsDiemOXY[7].toaDoX, dsDiemOXY[7].toaDoY, 1);
	
	//Hien thi thong tin cac diem con lai cua hinh hop
	showInfoHinhHop(x, y, z, chieuDai, chieuRong, chieuCao);
}
	

//Ve hinh Ellipse co net dut phia tren
void veHinhEllipseCoNetDut(int cx, int cy, int a, int b){
	int dem = 0;
	int x = 0;
	int y = b;
	int A = a*a;
	int B = b*b;
	int DX = 0;
	int DY = 2 * a * a * y;
	double p = B + A / 4 - A * b;
    int Dx = 0;
    int Dy = 2 * A * y;
    put4Pixels(x, y, cx, cy);
    while (Dx < Dy)
    {
        x++;
        Dx += 2 * B;
        if (p < 0)
            p += B + Dx;
        else
        {
            y--;
            Dy -= 2 *A;
            p += B+ Dx - Dy;
        }
        if(dem < 25)
        {
			//TODO
			putPixel(x + cx, -y + cy, 1);
			putPixel(-x + cx, -y + cy, 1);
		}
		dem = dem + 1;
		if(dem == 50)
		{
			dem = 0;
		}
		//TODO
		putPixel(x + cx, y + cy, 1);
		putPixel(-x + cx, y + cy, 1);
    }
    while (y > 0)
    {
        y--;
        Dy -= A * 2;
        if (p > 0)
            p += A- Dy;
        else
        {
            x++;
            Dx += B * 2;
            p +=A - Dy + Dx;
        }
        put4Pixels(x, LamTronToaDo(y), cx, cy);
    }
}

//Ve hinh Ellipse
void veHinhEllipse(int cx, int cy, int a, int b){
	int dem = 0;
	int x = 0;
	int y = b;
	int A = a*a;
	int B = b*b;
	int DX = 0;
	int DY = 2 * a * a * y;
	double p = B + A / 4 - A * b;
    int Dx = 0;
    int Dy = 2 * A * y;
    put4Pixels(x, y, cx, cy);
    while (Dx < Dy)
    {
        x++;
        Dx += 2 * B;
        if (p < 0)
            p += B + Dx;
        else
        {
            y--;
            Dy -= 2 *A;
            p += B+ Dx - Dy;
        }
		put4Pixels(x,LamTronToaDo(y), cx, cy);
    }
    while (y > 0)
    {
        y--;
        Dy -= A * 2;
        if (p > 0)
            p += A- Dy;
        else
        {
            x++;
            Dx += B * 2;
            p +=A - Dy + Dx;
        }
        put4Pixels(x, LamTronToaDo(y), cx, cy);
    }
}

//Hien thi thong tin hinh tru
void showInfoHinhTru(int x, int y, int z, int banKinhDay, int chieuCao){
	int viTriY = 155;	//NOTE: Update khi thay doi
	settextstyle(10, 0, 1);	//NOTE: Update khi thay doi
	setbkcolor(8);			//NOTE: Update khi thay doi
	setcolor(15);	//NOTE: Update khi thay doi
	
	//Chuyen cac toa do cua dang so sang dang text
	char tmp[4];
	outtextxy(1105, viTriY, "Tam 2 ("); ghiToaDoOXYZ(1180, viTriY, x/5, y/5, z/5 + chieuCao/5); viTriY = viTriY + 30;
	outtextxy(1105, viTriY, "R1 = "); _itoa(banKinhDay/5*1.22, tmp, 10); outtextxy(1160, viTriY, tmp);	viTriY = viTriY + 30;		//NOTE: Update khi thay doi
	outtextxy(1105, viTriY, "R2 = "); _itoa(banKinhDay/5*0.71, tmp, 10); outtextxy(1160, viTriY, tmp);
}

//Ve hinh tru
void veHinhTru(int x, int y, int z, int banKinhDay, int chieuCao){
	DIEM tamDay = chuyenToaDoNguoiDungSangToaDoMay(x, y, z);
	veHinhEllipseCoNetDut(tamDay.toaDoX, tamDay.toaDoY, banKinhDay*1.22, banKinhDay*0.71);
	veHinhEllipse(tamDay.toaDoX, tamDay.toaDoY - chieuCao, banKinhDay*1.22, banKinhDay*0.71);
	lineDDA(tamDay.toaDoX + banKinhDay*1.22, tamDay.toaDoY, tamDay.toaDoX + banKinhDay*1.22, tamDay.toaDoY - chieuCao, 1);
	lineDDA(tamDay.toaDoX - banKinhDay*1.22, tamDay.toaDoY, tamDay.toaDoX - banKinhDay*1.22, tamDay.toaDoY - chieuCao, 1);
	
	//Hien thi thong tin cac diem con lai cua hinh hop
	showInfoHinhTru(x, y, z, banKinhDay, chieuCao);

}
