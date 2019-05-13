////////////////////////////////////////////////////////LE QUOC DIEN//////////////////////////////////////////////////////////////////////////
//Ve mot hinh chu nhat dac
void rectangleSolid(int x, int y, int a, int b, int bgColor){
	setfillstyle(1, bgColor);	
	bar(x, y, a, b);
}

//Ve mot button
void button(int x, int y, int a, int b, int backgroundColor, char* nameButton, int font, int fontSize, int textColor){
/*	
	BANG GIA TRI FONT TRONG HAM settextstyle()
		DEFAULT_FONT            0
		TRIPLEX_FONT            1
		SMALL_FONT              2
		SANS_SERIF_FONT         3
		GOTHIC_FONT             4
		SCRIPT_FONT             5
		SIMPLEX_FONT            6 
		TRIPLEX_SCR_FONT        7
		COMPLEX_FONT            8
		EUROPEAN_FONT           9
		BOLD_FONT              10
		
*/
	//Ve hinh chu nhat
	rectangleSolid(x, y, a, b, backgroundColor);
	
	//Ghi ten button
	settextstyle(font, 0, fontSize);
	setbkcolor(backgroundColor);
	setcolor(textColor);
	outtextxy(x+(a-x-textwidth(nameButton))/2, y+(b-y-textheight(nameButton))/2, nameButton);
}

//Ve Gird
void initGrid(int x, int y, int a, int b){
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

//Ve he toa do 3 chieu
void initHeToaDo3Chieu(int x, int y, int a, int b){
	setfillstyle(1, 12);
	bar(GOC_TOA_DO_X - 2, GOC_TOA_DO_Y - 2, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, GOC_TOA_DO_Y + 2);	//Ve OX
	bar(GOC_TOA_DO_X - 2, GOC_TOA_DO_Y - 2, GOC_TOA_DO_X + 2, HEIGHT_PANEL_TOP+2);					  	//Ve OY
	
	setcolor(12);																		//Ve OZ
	for(int i = -3; i<=2; i++){
		line(GOC_TOA_DO_X + i, GOC_TOA_DO_Y, WIDTH_PANEL_LEFT + i, GOC_TOA_DO_Y - (GOC_TOA_DO_X - WIDTH_PANEL_LEFT - 10));			
	}
}

//Khoi tao he toa do 3 chieu va luoi
void initWorkStation(){
	initGrid(WIDTH_PANEL_LEFT + 10, HEIGHT_PANEL_TOP + 10, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN - 10, getmaxy() - 10);
	initHeToaDo3Chieu(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy());
}

//Lay cac ky tu so tren ban phim
int getNumberCharacter(){
	fflush(stdin);
	char character;
	char* arrCharacters = new char;
	int i = 0;
	while(true){
		delay(0.00001);
		character = getch();
		if((int)character == 13){
			return (atoi(arrCharacters));
		}
		else if((int)character >= 48 && (int)character <= 57){
			*(arrCharacters+i) = character;
			i++;
		}
	}
	
}

