#include "PickAndHide.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) : Action(pApp) {}

void PickAndHide::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	correct = 0;

	pOut->PrintMessage("Choose Shape as reference.");
	pIn->GetPointClicked(p.x, p.y);
	CFigure* figure = pManager->GetFigure(p.x, p.y);
	while (figure == NULL)
	{
		pOut->PrintMessage("Please choose a shape. ");
		pIn->GetPointClicked(p.x, p.y);
		figure = pManager->GetFigure(p.x, p.y);
	}
	fillcolor = figure->getColor();		//border color of shape
	isFilled = figure->getFilled();		//filled or not filled
	figureType = figure->getType();		//what kind of shape is it

	pOut->PrintMessage("Type, Fill, or Color?");
	mode = NOTHING;

	while (mode == NOTHING)
	{
		mode = pManager->GetUserAction();

		if (mode == FIGURE)
		{
			mode = FIGURE;
			pOut->PrintMessage("Choose all same shapes.");
		}
		else if (mode == COLOR)
		{
			mode = COLOR;
			pOut->PrintMessage("Choose all same colored shapes. ");
		}
		else if (mode == TYPE)
		{
			mode = TYPE;
			pOut->PrintMessage("Choose all filled or non-filled shapes. ");
		}
		else
		{
			mode = NOTHING;
			pOut->PrintMessage("Please choose a mode to play.");
		}
	}
}

void PickAndHide::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Creates play toolbar and deselects figures if any are selected;
	pOut->CreatePlayToolBar();
	pManager->DeselectFigures();

	ReadActionParameters();

	if ((pManager->GetFigCount()) > 0)
	{
		for (int i = 0; i < (pManager->GetFigCount()); i++)
		{
			pIn->GetPointClicked(p.x, p.y);
			CFigure* fig = pManager->GetFigure(p.x, p.y);

			switch (mode)
			{
			case FIGURE:	//what kind of shape
				if ((fig->getType()) == figureType)
					correct++;
			case TYPE:	//filled or not 
				if ((fig->getFilled()) == isFilled)
					correct++;
			case COLOR:		//what border color
				if ((fig->getColor()) == fillcolor)
					correct++;
			}
		}
	}
	pOut->ClearDrawArea();

	pManager->UpdateInterface();

}
