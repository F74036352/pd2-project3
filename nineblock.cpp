#include "nineblock.h"

NineBlock::NineBlock()
{

}

NineBlock::~NineBlock()
{

}

int NineBlock::condition(Blank *a[][], Blank *focus)
{

}

void NineBlock::spawn(Blank *a[][], Blank *focus, int mode)
{

}

void NineBlock::eliminate(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    int C=focus->column;
    focus->number=0;
    int EightN[8]={0};
    if(R>=1 && C>=1 && a[R-1][C-1]->number/10!=0)EightN[0]=a[R-1][C-1]->number=%10;
    if(R>=1 && a[R-1][C]->number/10!=0)          EightN[1]=a[R-1][C]->number=%10;
    if(R>=1 && C<=8 && a[R-1][C+1]->number/10!=0)EightN[2]=a[R-1][C+1]->number=%10;
    if(C>=1 && a[R][C-1]->number/10!=0)          EightN[3]=a[R][C-1]->number=%10;
    if(C<=8 && a[R][C+1]->number/10!=0)          EightN[4]=a[R][C+1]->number=%10;
    if(R<=8 && C>=1 && a[R+1][C-1]->number/10!=0)EightN[5]=a[R+1][C-1]->number=%10;
    if(R<=8 && a[R+1][C]->number/10!=0)          EightN[6]=a[R+1][C]->number=%10;
    if(R<=8 && C<=8 && a[R+1][C+1]->number/10!=0)EightN[7]=a[R+1][C+1]->number=%10;
}

