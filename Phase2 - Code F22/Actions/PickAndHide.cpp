#include "PickAndHide.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) : Action(pApp) {}

void PickAndHide::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Type, Fill, or Both?");
	mode = pManager->GetUserAction();
	reference = pManager->GetRandom();
}

void PickAndHide::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Creates play toolbar and deselects figures if any are selected;
	pOut->CreatePlayToolBar();
	pManager->DeselectFigures();

	pOut->ClearDrawArea();

	pManager->UpdateInterface();

}
