#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "destroy.h"
#include "vertical.h"
#include "nineblock.h"

class Horizontal:public Destroy
{
public:
    Horizontal();
    virtual~Horizontal();
    virtual int condition(Blank* a[10][10],Blank*focus);
    virtual void spawn(Blank* a[10][10],Blank*focus,int mode);
    virtual void eliminate(Blank*a[10][10],Blank* focus);
};

#endif // HORIZONTAL_H
