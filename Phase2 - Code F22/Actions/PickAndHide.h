#ifndef PICK_AND_HIDE
#define PICK_AND_HIDE

#include "Action.h"

class PickAndHide : public Action
{
	Point p;
	CFigure* reference;
	ActionType mode;

public:
	PickAndHide(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif // PICK_AND_HIDE


