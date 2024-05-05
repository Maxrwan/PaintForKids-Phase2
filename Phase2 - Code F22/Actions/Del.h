#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H

#include "Action.h"

class Del :
    public Action
{
public:
    Del(ApplicationManager* point);
    virtual void ReadActionParameters();
    virtual void Execute();

};

#endif

