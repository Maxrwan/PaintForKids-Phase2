#ifndef PICK_AND_HIDE
#define PICK_AND_HIDE

#include "Action.h"

class PickAndHide : public Action
{
private:
	Point p;
	color fillcolor;
	bool isFilled;
	string figureType;
	ActionType mode;
	int correct;

public:
	PickAndHide(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif // PICK_AND_HIDE


