#ifndef NINEBLOCK_H
#define NINEBLOCK_H
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"

class NineBlock:public Destroy
{
public:
    NineBlock();
    virtual~NineBlock();
    virtual int condition(Blank* a[10][10],Blank*focus);
    virtual void spawn(Blank* a[10][10],Blank*focus,int mode);
    virtual void eliminate(Blank*a[10][10],Blank* focus);
};

#endif // NINEBLOCK_H
