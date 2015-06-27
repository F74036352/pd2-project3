#include "nineblock.h"

NineBlock::NineBlock()
{

}

NineBlock::~NineBlock()
{

}

int NineBlock::condition(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0 && num!=5){
        if((num/10)==0){
            if(R>=2 && C>=2&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10 )
                    && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                    && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                    && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
                return 1;
            }
        }
        /***********************/
        if((num/10)==0){
            if(R<=7 && C>=2&& (num==a[R+2][C]->number||num==a[R+2][C]->number/10 )
                    && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                    && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                    && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
                return 2;
            }
        }
        /***********************/
        if((num/10)==0){
            if(R>=2 && C<=7&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10 )
                    && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                    && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                    && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)){
                return 3;
            }
        }
        /***********************/
        if((num/10)==0){
            if(R<=7 && C<=7&& (num==a[R+2][C]->number||num==a[R+2][C]->number/10 )
                    && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                    && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                    && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)){
                return 4;
            }
        }
    }
}
void NineBlock::spawn(Blank *a[10][10], Blank *focus, int mode)
{

}

void NineBlock::eliminate(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    int C=focus->column;
    Destroy* d;
    focus->number=0;
    int EightN[8]={0};
    if(R>=1 && C>=1 && a[R-1][C-1]->number/10!=0)EightN[0]=a[R-1][C-1]->number%=10;
    if(R>=1 && a[R-1][C]->number/10!=0)          EightN[1]=a[R-1][C]->number%=10;
    if(R>=1 && C<=8 && a[R-1][C+1]->number/10!=0)EightN[2]=a[R-1][C+1]->number%=10;
    if(C>=1 && a[R][C-1]->number/10!=0)          EightN[3]=a[R][C-1]->number%=10;
    if(C<=8 && a[R][C+1]->number/10!=0)          EightN[4]=a[R][C+1]->number%=10;
    if(R<=8 && C>=1 && a[R+1][C-1]->number/10!=0)EightN[5]=a[R+1][C-1]->number%=10;
    if(R<=8 && a[R+1][C]->number/10!=0)          EightN[6]=a[R+1][C]->number%=10;
    if(R<=8 && C<=8 && a[R+1][C+1]->number/10!=0)EightN[7]=a[R+1][C+1]->number%=10;
    /********************************************************************************/
    if(R>=1 && C>=1){
        switch(EightN[0]){
        case 0:
            a[R-1][C-1]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R-1][C-1]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R-1][C-1]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R-1][C-1]);
            delete d;
            break;
        }
    }
    if(R>=1){
        switch(EightN[1]){
        case 0:
            a[R-1][C]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R-1][C]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R-1][C]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R-1][C]);
            delete d;
            break;
        }
    }
    if(R>=1 && C<=8){
        switch(EightN[2]){
        case 0:
            a[R-1][C+1]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R-1][C+1]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R-1][C+1]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R-1][C+1]);
            delete d;
            break;
        }
    }
    if(C>=1){
        switch(EightN[3]){
        case 0:
            a[R][C+1]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R][C-1]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R][C-1]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R][C-1]);
            delete d;
            break;
        }
    }
    if(C<=8){
        switch(EightN[4]){
        case 0:
            a[R-1][C+1]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        }
    }
    if(R<=8 && C>=1){
        switch(EightN[5]){
        case 0:
            a[R][C+1]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        }
    }
    if(R<=8){
        switch(EightN[6]){
        case 0:
            a[R+1][C]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R+1][C]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R+1][C]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R+1][C]);
            delete d;
            break;
        }
    }
    if(R<=8 && C<=8){
        switch(EightN[7]){
        case 0:
            a[R+1][C+1]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R+1][C+1]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R+1][C+1]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R+1][C+1]);
            delete d;
            break;
        }
    }


}

