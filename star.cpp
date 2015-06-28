#include "star.h"
#include "horizontal.h"
#include "vertical.h"
#include "nineblock.h"
star::star()
{

}

star::~star()
{

}

int star::condition(Blank* a[10][10],Blank*focus){
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0 && num!=5){
        if((num/10)==0){
            if(R>=2 && R<=7&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10 )
                    && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                    && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                    && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)){
                return 1;
            }
            if(C>=2 && C<=7&& (num==a[R][C-2]->number||num==a[R][C-2]->number/10 )
                    && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                    && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                    && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)){
                return 2;
            }
        }
        else if((num/10)!=0){
            num/=10;
            if(R>=2 && R<=7&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10 )
                    && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                    && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                    && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)){
                return 3;
            }
            if(C>=2 && C<=7&& (num==a[R][C-2]->number||num==a[R][C-2]->number/10 )
                    && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                    && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                    && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)){
                return 4;
            }

        }
    }
    return 0;
}

void star::spawn(Blank *a[10][10], Blank *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    int FiveN[5]={0};//紀錄有無炸彈
    switch(mode){
    case 1://
        focus->number=5;
        if(C>=2 &&(num==a[R][C-2]->number||num==a[R][C-2]->number/10)&&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
            a[R][C-2]->number=0;
            a[R][C-1]->number=0;
        }
        if(C<=7 &&(num==a[R][C+1]->number||num==a[R][C+1]->number/10)&&(num==a[R][C+2]->number||num==a[R][C+2]->number/10)){
            a[R][C+1]->number=0;
            a[R][C+2]->number=0;
        }
        if(a[R-2][C]->number/10!=0)FiveN[0]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)FiveN[1]=a[R-1][C]->number%10;
        FiveN[2]=a[R][C]->number;
        if(a[R+1][C]->number/10!=0)FiveN[3]=a[R+1][C]->number%10;
        if(a[R+2][C]->number/10!=0)FiveN[4]=a[R+2][C]->number%10;

        for(int i=0;i<5;i++)
        {
            Destroy* d;
            switch (FiveN[i]) {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1://若為炸彈，則引爆
                d=new Vertical;
                d->eliminate(a,a[R-2+i][C]);
                delete d;

                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;

                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
        /*********************/
    case 2:
        focus->number=5;
        if(R>=2 &&(num==a[R-2][C]->number||num==a[R-2][C]->number/10)&&(num==a[R-1][C]->number||num==a[R-1][C]->number/10)){
            a[R-2][C]->number=0;
            a[R-1][C]->number=0;
        }
        if(R<=7 &&(num==a[R+1][C]->number||num==a[R+1][C]->number/10)&&(num==a[R+2][C]->number||num==a[R+2][C]->number/10)){
            a[R+1][C]->number=0;
            a[R+2][C]->number=0;
        }
        if(a[R][C-2]->number/10!=0)FiveN[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)FiveN[1]=a[R][C-1]->number%10;
        FiveN[2]=a[R][C]->number;
        if(a[R][C+1]->number/10!=0)FiveN[3]=a[R][C+1]->number%10;
        if(a[R][C+2]->number/10!=0)FiveN[4]=a[R][C+2]->number%10;

        for(int i=0;i<5;i++)
        {
            Destroy* d;
            switch (FiveN[i]) {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1://若為炸彈，則引爆
                d=new Vertical;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        break;
        /*******************************/
    case 3://
        num/=10;

        if(C>=2 &&(num==a[R][C-2]->number||num==a[R][C-2]->number/10)&&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
            a[R][C-2]->number=0;
            a[R][C-1]->number=0;
        }
        if(C<=7 &&(num==a[R][C+1]->number||num==a[R][C+1]->number/10)&&(num==a[R][C+2]->number||num==a[R][C+2]->number/10)){
            a[R][C+1]->number=0;
            a[R][C+2]->number=0;
        }
        if(a[R-2][C]->number/10!=0)FiveN[0]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)FiveN[1]=a[R-1][C]->number%10;
        FiveN[2]=a[R][C]->number%10;
        if(a[R+1][C]->number/10!=0)FiveN[3]=a[R+1][C]->number%10;
        if(a[R+2][C]->number/10!=0)FiveN[4]=a[R+2][C]->number%10;

        for(int i=0;i<5;i++)
        {
            Destroy* d;
            switch (FiveN[i]) {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1://若為炸彈，則引爆
                d=new Vertical;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
        /**************************/
    case 4:
        num/=10;

        if(R>=2 &&(num==a[R-2][C]->number||num==a[R-2][C]->number/10)&&(num==a[R-1][C]->number||num==a[R-1][C]->number/10)){
            a[R-2][C]->number=0;
            a[R-1][C]->number=0;
        }
        if(R<=7 &&(num==a[R+1][C]->number||num==a[R+1][C]->number/10)&&(num==a[R+2][C]->number||num==a[R+2][C]->number/10)){
            a[R+1][C]->number=0;
            a[R+2][C]->number=0;
        }
        if(a[R][C-2]->number/10!=0)FiveN[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)FiveN[1]=a[R][C-1]->number%10;
        FiveN[2]=a[R][C]->number%10;
        if(a[R][C+1]->number/10!=0)FiveN[3]=a[R][C+1]->number%10;
        if(a[R][C+2]->number/10!=0)FiveN[4]=a[R][C+2]->number%10;

        for(int i=0;i<5;i++)
        {
            Destroy* d;
            switch (FiveN[i]) {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1://若為炸彈，則引爆
                d=new Vertical;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        break;
    }
}

void star::eliminate(Blank *a[10][10], Blank *focus)
{

}
