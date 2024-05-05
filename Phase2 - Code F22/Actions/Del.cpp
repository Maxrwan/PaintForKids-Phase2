#include "Del.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"


Del::Del(ApplicationManager* point) :Action(point) {}

void Del::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Delete Figures");


}

void Del::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->RemoveFigure();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
}