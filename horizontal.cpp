#include "horizontal.h"

Horizontal::Horizontal()
{

}

Horizontal::~Horizontal()
{

}

int Horizontal::condition(Blank *a[10][10], Blank *focus)
{

}

void Horizontal::spawn(Blank *a[10][10], Blank *focus, int mode)
{

}

void Horizontal::eliminate(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    focus->number=0;
    int TenN[10]={0};
    Destroy* d;
    for(int i=0;i<10;i++){
        if(a[R][i]->number/10!=0){
            TenN[i]=a[R][i]->number%10;
        }
        }
    for(int i=0;i<10;i++)
    {
        switch(TenN[i]){
        case 0:
            a[R][i]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        }
    }
}

