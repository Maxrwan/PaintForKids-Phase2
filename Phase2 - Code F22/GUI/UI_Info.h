#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu

	//TODO: Add more items names here

	ITM_SQR,

	ITM_CIRCLE,

	ITM_TRIANGLE,

	ITM_HEXAGON,

	ITM_SELECT,

	ITM_BORD_COLOR,

	ITM_FILL_COLOR,

	ITM_DELETE,

	ITM_CLEAR,

	ITM_COPY,

	ITM_CUT,

	ITM_PASTE,

	ITM_BACK_FRONT,

	ITM_SAVE,

	ITM_LOAD,

	ITM_EXIT,    //Exit item

	ITM_PLAY,    //GO TO PLAY MODE NEW 
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here ALL ITEMS ARE NEW 
	ITM_PICK_HIDE,

	ITM_FIGURE, 

	ITM_TYPE,

	ITM_COLOR,

	ITM_RETURN,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorPalette
{

	Blue,

	Red,

	Pink,

	Green,

	Brown,

	Place_Holder,

	COLOR_COUNT

};






__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		LineUnderTBWidth,	//line Under the Toolbar Pen Width
		MenuItemWidth,		//Width of each item in toolbar menu
		ColorWidth,         //Width of each color in the palette
		PaletteWidth,       //Width of Palette (All colors)
		PaletteHeight,      //Height of color palette
	PaletteCapacity;        //Number of colors in the palette
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif