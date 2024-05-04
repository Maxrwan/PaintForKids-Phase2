#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQR: return DRAW_SQR;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_SELECT: return SELECT;
			case ITM_BORD_COLOR: return CHANGE_BORDER_COLOR;
			case ITM_FILL_COLOR: return CHANGE_FILL_COLOR;
			case ITM_DELETE: return DELETE_ITMS;
			case ITM_CLEAR: return CLEAR; 
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_BACK_FRONT: return SEND_BACK_BRING_FRONT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EXIT: return EXIT;	
			case ITM_PLAY: return TO_PLAY;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		if (y > UI.ToolBarHeight && y < (UI.ToolBarHeight + UI.PaletteHeight) && x < UI.PaletteWidth) {
			int ClickedItemOrder = (x / UI.ColorWidth);

			switch (ClickedItemOrder) {
			case Blue: return B;
			case Red: return R;
			case Pink: return P;
			case Green: return G;
			case Brown: return BR;

			default: return DRAWING_AREA;
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= (UI.ToolBarHeight + UI.PaletteHeight) && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}

		if (y >= (UI.ToolBarHeight ) && y < UI.height - UI.StatusBarHeight && x > UI.PaletteWidth)
		{
			return DRAWING_AREA;
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PICK_HIDE: return PICK_HIDE;
			case ITM_FIGURE: return FIGURE;
			case ITM_TYPE: return TYPE;
			case ITM_COLOR: return COLOR;
			case ITM_RETURN: return TO_DRAW;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

		return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
