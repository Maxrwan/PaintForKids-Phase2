#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select: Click on any item. ");
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	ReadActionParameters();

	CFigure* figure = pManager->GetFigure(p.x, p.y);

	if (figure == NULL)
	{
		pOut->PrintMessage("Select Cancelled.");
		pManager->DeselectFigures();
	}
	else 
	{
		if (figure->IsSelected())
		{
			pOut->PrintMessage("Deselected");
			figure->SetSelected(false);
		}
		else
		{
			figure->SetSelected(true);
			figure->PrintInfo(pOut);
			pManager->SelectedFigSetter(figure);
		}
	}
}
