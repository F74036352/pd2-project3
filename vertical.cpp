#include "vertical.h"

Vertical::Vertical()
{

}

Vertical::~Vertical()
{

}

int Vertical::condition(Blank *a[][], Blank *focus)
{

}

void Vertical::spawn(Blank *a[][], Blank *focus, int mode)
{

}

void Vertical::eliminate(Blank *a[10][10], Blank *focus)
{
    int C=focus->column;
    focus->number=0;
    int TenN[10]={0};
    Destroy* d;
    for(int i=0;i<10;i++){
        if(a[i][C]->number/10!=0){
            TenN[i]=a[i][C]->number%10;
        }
        }
    for(int i=0;i<10;i++)
    {
        switch(TenN[i]){
        case 0:
            a[i][C]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[i][C]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[i][C]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[i][C]);
            delete d;
            break;
        }
    }
}

