//Ve giao dien
void initGUI()
{
	//Draw panel left
	rectangleSolid(0, 0, WIDTH_PANEL_LEFT, getmaxy(), 8);
	
	//Chua biet chu thich gi, nhung nhin vao mau xanh goc trai tren
	rectangleSolid(0, 0, WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, 2);
	
	//Draw buttons
	int currentPosition = SPACE_FIRST_BUTTON - SPACE_BUTTON;	//NOTE: Update khi thay doi
	char* nameButton[] = {"2D 1", "2D 2", "3D 1", "3D 2", "About", "Help"};
	for(int i = 0; i < 6; i++){
		button(0, currentPosition + SPACE_BUTTON, WIDTH_PANEL_LEFT, currentPosition + SPACE_BUTTON + HEIGHT_BUTTON, 8, nameButton[i], 4, 2, 15);
		currentPosition = currentPosition + SPACE_BUTTON + HEIGHT_BUTTON;
	}		
	
	//Draw panel top
	button(WIDTH_PANEL_LEFT, 0, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, HEIGHT_PANEL_TOP, 8, "VE HINH CO BAN", 5, 5, 14);
	
	//Draw panel main (mau trang)
	rectangleSolid(WIDTH_PANEL_LEFT, HEIGHT_PANEL_TOP, WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, getmaxy(), 15);
	
	//Draw panel right
	rectangleSolid(WIDTH_PANEL_LEFT + WIDTH_PANEL_MAIN, 0, getmaxx(), getmaxy(), 8);
	
	//Dong chu Copyright © 2019
	button(0, getmaxy() - HEIGHT_BUTTON, WIDTH_PANEL_LEFT, getmaxy(), 8, "© 2019", 1, 1, 15);
}
