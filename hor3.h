#ifndef HOR3_H
#define HOR3_H
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"
#include "star.h"
#include "ver3.h"

class hor3:public Destroy
{
public:
    hor3();
    virtual~hor3();
    virtual int condition(Blank* a[10][10],Blank*focus);
    virtual void spawn(Blank* a[10][10],Blank*focus,int mode);
    virtual void eliminate(Blank*a[10][10],Blank* focus);
};

#endif // HOR3_H
