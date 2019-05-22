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








