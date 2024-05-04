#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectAction.h"
#include "Actions/PickAndHide.h"
#include <cstdlib>
#include <ctime>


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	for (int i = 0; i < MaxFigCount; i++)
		SelectedFig[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case SELECT: //select
			pAct = new SelectAction(this);
			break;

		case TO_PLAY:
			pAct = new PickAndHide(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->WithinFigure(x, y))
		{
			return FigList[i];
		}
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

void ApplicationManager::SelectedFigSetter(CFigure* pSelected)
{
	SelectedFig[SelectedFigCount] = pSelected;
	SelectedFigCount++;
}

void ApplicationManager::DeselectFigures()
{
	for (int i = 0; i < SelectedFigCount; i++)
	{
		SelectedFig[i]->SetSelected(false);
		SelectedFig[i] = NULL;
	}
	SelectedFigCount = 0;
}

CFigure* ApplicationManager::GetRandom()
{
	if (FigCount != 0) 
	{
		srand(time(NULL));
		return FigList[rand() % FigCount];
	}
	return nullptr;
}

int ApplicationManager::GetFigCount() const
{
	return FigCount;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
