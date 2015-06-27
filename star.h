#ifndef STAR_H
#define STAR_H
#include "destroy.h"


class star:public Destroy
{
public:
    star();
    virtual~star();
    virtual int condition(Blank* a[10][10],Blank*focus);
    virtual void spawn(Blank* a[10][10],Blank*focus,int mode);
    virtual void eliminate(Blank*a[10][10],Blank* focus);
};

#endif // STAR_H
