#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_PLAY;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 65;
	UI.ColorWidth = 50;
	UI.PaletteWidth = UI.ColorWidth * COLOR_COUNT;
	UI.PaletteHeight = 50;
	UI.PaletteCapacity = UI.width / UI.ColorWidth;

	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.ToolBarColor = WHITE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");
	
	CreateDrawToolBar();
	//CreatePlayToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight + 5);

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_square.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_circle.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_tri.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_hex.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_BORD_COLOR] = "images\\MenuItems\\Change_Border_Color.jpg";
	MenuItemImages[ITM_FILL_COLOR] = "images\\MenuItems\\Change_Filling_Color.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Clear.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_BACK_FRONT] = "images\\MenuItems\\Back_Front.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list
	color Palette[COLOR_COUNT];
	Palette[Blue] = BLUE;
	Palette[Red] = RED;
	Palette[Pink] = PINK;
	Palette[Green] = GREEN;
	Palette[Brown] = BROWN;
	Palette[Place_Holder] = UI.BkGrndColor;


	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight + 5);
	for (int i = 0; i < COLOR_COUNT; i++)
	{
		pWind->SetPen(Palette[i], 1);
		pWind->SetBrush(Palette[i]);
		pWind->DrawRectangle(i * UI.ColorWidth, UI.ToolBarHeight + 5, (i + 1) * UI.ColorWidth, UI.PaletteHeight + UI.ToolBarHeight);
	}


	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight + 5, UI.width, UI.ToolBarHeight + 5);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu

	//BACKGROUND RECTANGLE
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight + 5);

	//ITEMS
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICK_HIDE] = "images\\MenuItems\\Play.jpg";
	MenuItemImages[ITM_FIGURE] = "images\\MenuItems\\Figure.jpg";
	MenuItemImages[ITM_TYPE] = "images\\MenuItems\\Type.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Color.jpg";
	MenuItemImages[ITM_RETURN] = "images\\MenuItems\\Return.jpg";


	//PRINTING ITEMS
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight + 5);

	//Line under toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight + 5, UI.width, UI.ToolBarHeight + 5);

	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 4 + UI.LineUnderTBWidth, COLOR_COUNT * UI.ColorWidth, UI.PaletteHeight + UI.ToolBarHeight + 5 + UI.LineUnderTBWidth);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth + 5 + UI.PaletteHeight, UI.width, UI.height - UI.StatusBarHeight);
	pWind->DrawRectangle(COLOR_COUNT * UI.ColorWidth, UI.ToolBarHeight + UI.LineUnderTBWidth + 5 + UI.PaletteHeight, UI.width, UI.height - UI.StatusBarHeight);
	pWind->DrawRectangle((COLOR_COUNT - 1) * UI.ColorWidth, UI.ToolBarHeight + UI.LineUnderTBWidth + 5, UI.width, UI.ToolBarHeight + UI.PaletteHeight + 5 + UI.LineUnderTBWidth);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

//RECTANGLE 
void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

//TRIANGLE
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

//SQUARE 

void Output::DrawSqr(Point P1, int length, GfxInfo SqrGfxInfo, bool selected) const 
{
	Point p1;
	p1.x = P1.x - (length / 2);
	p1.y = P1.y - (length / 2);

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;

	Point P2;
	P2.x = p1.x + length;
	P2.y = p1.y + length;

	pWind->DrawRectangle(p1.x, p1.y, P2.x, P2.y, style);
}

//CIRCLE

void Output::DrawCirc(Point P1, Point P2, GfxInfo CircleGfxinfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxinfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxinfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxinfo.FillClr);
	}
	else
		style = FRAME;
	int radius;
	radius = ((P2.x - P1.x) ^ 2) + ((P2.y - P1.y) ^ 2);

	pWind->DrawCircle(P1.x, P1.y, radius, style);
}

//HEXAGON 

/*void Output::DrawHex(Point* vertices, int numVertices, GfxInfo polygonGfxInfo, bool selected = false) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = polygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (polygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(polygonGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int x[6];
	int y[6];
	for (int i = 0; i < 6; ++i) {
		x[i] = vertices[i].x;
		y[i] = vertices[i].y;
	}

	pWind->DrawPolygon(x, y, 6, style);

}
*/

void Output::DrawHex(Point P1, int length, GfxInfo polygonGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = polygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (polygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(polygonGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int x[6];
	x[0] = P1.x - (length / 2);
	x[1] = P1.x + (length / 2);
	x[2] = P1.x + length;
	x[3] = P1.x + (length / 2);
	x[4] = P1.x - (length / 2);
	x[5] = P1.x - length;
	int y[6];
	y[0] = P1.y + (length / 2);
	y[1] = P1.y + (length / 2);
	y[2] = P1.y;
	y[3] = P1.y - (length / 2);
	y[4] = P1.y - (length / 2);
	y[5] = P1.y;

	pWind->DrawPolygon(x, y, 6, style);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

