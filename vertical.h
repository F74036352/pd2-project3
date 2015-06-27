#ifndef VERTICAL_H
#define VERTICAL_H
#include "destroy.h"
#include "horizontal.h"
#include "nineblock.h"

class Vertical:public Destroy
{
public:
    Vertical();
    virtual~Vertical();
    virtual int condition(Blank* a[10][10],Blank*focus);
    virtual void spawn(Blank* a[10][10],Blank*focus,int mode);
    virtual void eliminate(Blank*a[10][10],Blank* focus);
};

#endif // VERTICAL_H
