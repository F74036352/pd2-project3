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

            if(R>=2 && C>=2&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                    && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                    && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                    && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
                return 1;
            }

        /***********************/

            if(R<=7 && C>=2&& (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                    && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                    && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                    && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
                return 2;
            }

        /***********************/

            if(R>=2 && C<=7&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                    && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                    && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                    && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)){
                return 3;
            }

        /***********************/

            if(R<=7 && C<=7&& (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                    && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                    && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                    && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)){
                return 4;
            }
         /***********************************/
            if(R>=1 && R<=8 && C>=2&& (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                    && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                    && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                    && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)){
                return 5;
            }
            /***********************************/
               if(R<=8 && C>=2 && C<=7 &&(num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                       && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                       && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                       && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)){
                   return 6;
               }
               /***********************************/
                  if(R>=2 && C>=1 && C<=8 &&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                          && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                          && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                          && (num==a[R-2][C]->number||num==a[R-2][C]->number/10)){
                      return 7;
                  }
                  /***********************************/
                     if(R<=7 && C>=1 && C<=8 &&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                             && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                             && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                             && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)){
                         return 8;
                     }

    }
    else if(num/10!=0){
        num/=10;
        if(R>=2 && C>=2&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
            return 9;
        }

    /***********************/

        if(R<=7 && C>=2&& (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)){
            return 10;
        }

    /***********************/

        if(R>=2 && C<=7&& (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)){
            return 11;
        }

    /***********************/

        if(R<=7 && C<=7&& (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)){
            return 12;
        }
     /***********************************/
        if(R>=1 && R<=8 && C>=2&& (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                && (num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)){
            return 13;
        }
        /***********************************/
           if(R<=8 && C>=2 && C<=7 &&(num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                   && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                   && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                   && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)){
               return 14;
           }
           /***********************************/
              if(R>=2 && C>=1 && C<=8 &&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                      && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                      && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                      && (num==a[R-2][C]->number||num==a[R-2][C]->number/10)){
                  return 15;
              }
              /***********************************/
                 if(R<=7 && C>=1 && C<=8 &&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                         && (num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                         && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                         && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)){
                     return 16;
                 }

    }
}
void NineBlock::spawn(Blank *a[10][10], Blank *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    int FiveN[5]={0};
    switch(mode){//switch
        case 1:
        focus->number=focus->number*10+3;
        if(C<=8 && num==a[R][C+1]->number||num==a[R][C+1]->number/10)
        {a[R][C+1]->number=0;}

        if(R<=8 && num==a[R+1][C]->number||num==a[R+1][C]->number/10)
        {a[R+1][C]->number=0;}

        if(a[R][C-2]->number/10!=0)FiveN[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)FiveN[1]=a[R][C-1]->number%10;
        FiveN[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0)FiveN[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)FiveN[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++){
            Destroy *d;
            switch(FiveN[i]){
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
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
            for(int i=0;i<2;i++){
                Destroy *d;
                switch(FiveN[i]){
                case 0:
                    a[R-2+i][C]->number=0;
                    break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R-2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2-i][C]);
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
        /**********************/
        case 2:
        focus->number=focus->number*10+3;
        if(C<=8 && num==a[R][C+1]->number||num==a[R][C+1]->number/10)
        {a[R][C+1]->number=0;}
        ;
        if(R>=1 && num==a[R-1][C]->number||num==a[R-1][C]->number/10)
        {a[R-1][C]->number=0;}

        if(a[R][C-2]->number/10!=0)FiveN[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)FiveN[1]=a[R][C-1]->number%10;
        FiveN[2]=a[R][C]->number;
        if(a[R+2][C]->number/10!=0)FiveN[3]=a[R+2][C]->number%10;
        if(a[R+1][C]->number/10!=0)FiveN[4]=a[R+1][C]->number%10;

        for(int i=0;i<2;i++){
            Destroy *d;
            switch(FiveN[i]){
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
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
            for(int i=0;i<2;i++){
                Destroy *d;
                switch(FiveN[i]){
                case 0:
                    a[R+2-i][C]->number=0;
                    break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new NineBlock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
               }
            }
        break;
        /**********************/
        case 3:
        focus->number=focus->number*10+3;
        if(C>=1 && num==a[R][C-1]->number||num==a[R][C-1]->number/10)
        {a[R][C-1]->number=0;}

        if(R<=8 && num==a[R+1][C]->number||num==a[R+1][C]->number/10)
        {a[R+1][C]->number=0;}

        if(a[R][C+2]->number/10!=0)FiveN[0]=a[R][C+2]->number%10;
        if(a[R][C+1]->number/10!=0)FiveN[1]=a[R][C+1]->number%10;
        FiveN[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0)FiveN[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)FiveN[4]=a[R-1][C]->number%10;

        for(int i=0;i<2;i++){
            Destroy *d;
            switch(FiveN[i]){
            case 0:
                a[R][C+2-i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C+2-i]);
                delete d;
                break;
           }
        }
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
        break;
        /**********************/
        case 4:
        focus->number=focus->number*10+3;
        if(C>=1 && num==a[R][C-1]->number||num==a[R][C-1]->number/10)
        {a[R][C-1]->number=0;}

        if(R>=1 && num==a[R-1][C]->number||num==a[R-1][C]->number/10)
        {a[R-1][C]->number=0;}

        if(a[R][C+2]->number/10!=0)FiveN[0]=a[R][C+2]->number%10;
        if(a[R][C+1]->number/10!=0)FiveN[1]=a[R][C+1]->number%10;
        FiveN[2]=a[R][C]->number;
        if(a[R+2][C]->number/10!=0)FiveN[3]=a[R+2][C]->number%10;
        if(a[R+1][C]->number/10!=0)FiveN[4]=a[R+1][C]->number%10;

        for(int i=0;i<2;i++){
            Destroy *d;
            switch(FiveN[i]){
            case 0:
                a[R][C+2-i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C+2-i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C+2-i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C+2-i]);
                delete d;
                break;
           }
        }
            for(int i=0;i<2;i++){
                Destroy *d;
                switch(FiveN[i]){
                case 0:
                    a[R+2-i][C]->number=0;
                    break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new NineBlock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
               }
            }
        break;
        /*******************************************************/
    }//switch

}

void NineBlock::eliminate(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    int C=focus->column;
    Destroy* d;
    focus->number=0;
    int EightN[8]={0};
    if(R>=1 && C>=1 && a[R-1][C-1]->number/10!=0)EightN[0]=a[R-1][C-1]->number%10;
    if(R>=1 && a[R-1][C]->number/10!=0)          EightN[1]=a[R-1][C]->number%10;
    if(R>=1 && C<=8 && a[R-1][C+1]->number/10!=0)EightN[2]=a[R-1][C+1]->number%10;
    if(C>=1 && a[R][C-1]->number/10!=0)          EightN[3]=a[R][C-1]->number%10;
    if(C<=8 && a[R][C+1]->number/10!=0)          EightN[4]=a[R][C+1]->number%10;
    if(R<=8 && C>=1 && a[R+1][C-1]->number/10!=0)EightN[5]=a[R+1][C-1]->number%10;
    if(R<=8 && a[R+1][C]->number/10!=0)          EightN[6]=a[R+1][C]->number%10;
    if(R<=8 && C<=8 && a[R+1][C+1]->number/10!=0)EightN[7]=a[R+1][C+1]->number%10;
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

