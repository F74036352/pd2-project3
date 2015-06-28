#ifndef VER3_H
#define VER3_H
#include "destroy.h"
#include "vertical.h"
#include "nineblock.h"
#include "star.h"
#include "hor3.h"

class ver3:public Destroy
{
public:
    ver3();
    virtual~ver3();
    virtual int condition(Blank* a[10][10],Blank*focus);
    virtual void spawn(Blank* a[10][10],Blank*focus,int mode);
    virtual void eliminate(Blank*a[10][10],Blank* focus);
};

#endif // VER3_H
