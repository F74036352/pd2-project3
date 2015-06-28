#include "vertical.h"

Vertical::Vertical()
{

}

Vertical::~Vertical()
{

}

int Vertical::condition(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0 && num!=5){
        if(num<10){
        if(R>=1 && R<=7 &&(num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                        &&(num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                        &&(num==a[R+2][C]->number||num==a[R+2][C]->number/10)){
            return 1;
        }
        if(R>=2 && R<=8 &&(num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                        &&(num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                        &&(num==a[R+1][C]->number||num==a[R+1][C]->number/10)){
            return 2;
        }
    }
    }
    return 0;
}

void Vertical::spawn(Blank *a[10][10], Blank *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    int FiveN[4]={0};
    Destroy *d;
    switch(mode){//switch


        case 1:
        focus->number=focus->number*10+1;

        if(a[R-1][C]->number/10!=0)FiveN[0]=a[R-1][C]->number%10;
        FiveN[1]=a[R][C]->number;
        if(a[R+1][C]->number/10!=0)FiveN[2]=a[R+1][C]->number%10;

        if(a[R+2][C]->number/10!=0)FiveN[3]=a[R+2][C]->number%10;
            switch(FiveN[0]){
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
            switch(FiveN[1]){
            case 0:
                a[R][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
           }
                switch(FiveN[2]){
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
                switch(FiveN[3]){
                case 0:
                    a[R+2][C]->number=0;
                    break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2][C]);
                    delete d;
                    break;
                case 3:
                    d=new NineBlock;
                    d->eliminate(a,a[R+2][C]);
                    delete d;
                    break;
               }

        break;
        /**********************/
    case 2:
    focus->number=focus->number*10+1;
    if(a[R-2][C]->number/10!=0)FiveN[0]=a[R-2][C]->number%10;
    if(a[R-1][C]->number/10!=0)FiveN[1]=a[R-1][C]->number%10;
    FiveN[2]=a[R][C]->number;
    if(a[R+1][C]->number/10!=0)FiveN[3]=a[R+1][C]->number%10;

    for(int i=0;i<2;i++){
        Destroy *d;
        switch(FiveN[i]){
        case 0:
            a[R-2+i][C]->number=0;
            break;
        case 1:
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

            Destroy *d;
            switch(FiveN[2]){
            case 0:
                a[R][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R+1][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
           }
            switch(FiveN[3]){
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



    break;

        /*******************************************************/


    }//switch

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

