#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),score(0),step(20),
    ui(new Ui::MainWindow)
{   //srand((unsigned)time(NULL));
    ui->setupUi(this);
    this->setMaximumSize(800,520);
    this->setMinimumSize(800,520);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]=new Blank(this,i,j);//將row column的值回傳
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));
        }

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::button_clicked(int R, int C){
   //qDebug()<<b[R][C]->number;
    if(!isClicked){
        setClickedPicture(b[R][C]);
        record_R=R;
        record_C=C;
        isClicked=true;
    }
    else{
        if(record_R==R && record_C==C-1){//左右交換
            *b[record_R][record_C] + b[R][C];
            step-=1;
            if(!Judge(record_R,record_C,R,C)){
                *b[record_R][record_C] + b[R][C];
                step+=1;
            }
        }
        else if(record_R==R && record_C==C+1){
            *b[R][C] + b[record_R][record_C];
            step-=1;
            if(!Judge(record_R,record_C,R,C)){
                *b[R][C] + b[record_R][record_C];
                step+=1;
            }
        }
        else if(record_C==C && record_R==R-1){
            *b[record_R][record_C] + b[R][C];
            step-=1;
            if(!Judge(record_R,record_C,R,C)){
                   *b[record_R][record_C] + b[R][C];
                step+=1;
            }
        }
        else if(record_C==C && record_R==R+1){
            *b[R][C] + b[record_R][record_C];
            step-=1;
            if(!Judge(record_R,record_C,R,C)){
                *b[record_R][record_C] + b[R][C];
                step+=1;
            }
        }
        else{
            setClickedPicture(b[record_R][record_C]);
        }
        isClicked=false;
    }
}
void MainWindow::GameStart(){
    isClicked=false;
    for(int i=0;i<10;i++){//for1
        for(int j=0;j<10;j++){//for2
            b[i][j]->setRandomNumber();
            b[i][j]->setButtonPicture();
            if(j>=2 && b[i][j]->number==b[i][j-1]->number && b[i][j]->number==b[i][j-2]->number){//if
                j--;//產生時不要讓橫的三個一樣
            }//if
            if(i>=2 && b[i][j]->number==b[i-1][j]->number&&b[i][j]->number==b[i-2][j]->number){//if
                j--;//產生時不要讓直的三個一樣
            }//if
        }//for2
    }//for1
    ui->run->display(step);
}
void MainWindow::setClickedPicture(Blank *a){
    if(!isClicked){
        switch (a->number) {
        case 1:
            a->button->setIcon(QIcon(QPixmap(":/picture/Blue_o.png")));

            break;
        case 11:
            a->button->setIcon(QIcon(QPixmap(":/picture/Blue_v.png")));
            break;
        case 12:
            a->button->setIcon(QIcon(QPixmap(":/picture/Blue_h.png")));
            break;
        case 13:
            a->button->setIcon(QIcon(QPixmap(":/picture/Blue_w.png")));
            break;
        case 2:
            a->button->setIcon(QIcon(QPixmap(":/picture/Green_o.png")));
            break;
        case 21:
            a->button->setIcon(QIcon(QPixmap(":/picture/Green_v.png")));
            break;
        case 22:
            a->button->setIcon(QIcon(QPixmap(":/picture/Green_h.png")));
            break;
        case 23:
            a->button->setIcon(QIcon(QPixmap(":/icon/picture/Green_w.png")));
            break;
        case 3:
            a->button->setIcon(QIcon(QPixmap(":/picture/Red_o.png")));
            break;
        case 31:
            a->button->setIcon(QIcon(QPixmap(":/picture/Red_v.png")));
            break;
        case 32:
            a->button->setIcon(QIcon(QPixmap(":/picture/Red_h.png")));
            break;
        case 33:
            a->button->setIcon(QIcon(QPixmap(":/picture/Red_w.png")));
            break;
        case 4:
            a->button->setIcon(QIcon(QPixmap(":/picture/Yellow_o.png")));
            break;
        case 41:
            a->button->setIcon(QIcon(QPixmap(":/picture/Yellow_v.png")));
            break;
        case 42:
            a->button->setIcon(QIcon(QPixmap(":/picture/Yellow_h.png")));
            break;
        case 43:
            a->button->setIcon(QIcon(QPixmap(":/picture/Yellow_w.png")));
            break;
        case 5:
            a->button->setIcon(QIcon(QPixmap(":/picture/Bomb.png")));
            break;
        default:
            a->button->setIcon(QIcon(QPixmap("Nopic")));

        }
    }//if
    else{
        a->setButtonPicture();
    }
}

bool MainWindow::Judge(int row1, int col1, int row2, int col2)
{
    bool RF[12];
    RF[0]=JudgeStar(row1,col1);
    RF[1]=JudgeStar(row2,col2);
    RF[2]=JudgeL(row1,col1);
    RF[3]=JudgeL(row2,col2);
    RF[4]=JudgeV(row1,col1);
    RF[5]=JudgeV(row2,col2);
    RF[6]=JudgeH(row1,col1);
    RF[7]=JudgeH(row2,col2);
    RF[8]=JudgeH3(row1,col1);
    RF[9]=JudgeH3(row2,col2);
    RF[10]=JudgeV3(row1,col1);
    RF[11]=JudgeV3(row2,col2);
    RenewPicture();
    fillzero();
    bornzero();
    RenewPicture();
    for(int i=0;i<12;i++){
    if(RF[i]==true){
        return true;

    }
    }
    return false;
}

bool MainWindow::JudgeStar(int R, int C)
{
    int returnV;
    bool AnySpawn=false;
    destroy=new star;
    returnV=destroy->condition(b,b[R][C]);
    if(returnV){
        switch(returnV){
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            break;
        case 4:
            destroy->spawn(b,b[R][C],4);
            AnySpawn=true;
            break;
        }
    }
    delete destroy;
    return AnySpawn;
}
void MainWindow::RenewPicture(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]->setButtonPicture();
        }
    }
    ui->now->display(score);
    ui->run->display(step);
}

bool MainWindow::JudgeL(int R, int C)
{
    int returnV;
    bool AnySpawn=false;
    destroy=new NineBlock;
    returnV=destroy->condition(b,b[R][C]);
    if(returnV){
        switch(returnV){
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            score+=100;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            score+=100;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            score+=100;
            break;
        case 4:
            destroy->spawn(b,b[R][C],4);
            AnySpawn=true;
            score+=100;
            break;
       /* case 5:
            destroy->spawn(b,b[R][C],5);
            AnySpawn=true;
            break;
        case 6:
            destroy->spawn(b,b[R][C],6);
            AnySpawn=true;
            break;
        case 7:
            destroy->spawn(b,b[R][C],7);
            AnySpawn=true;
            break;
        case 8:
            destroy->spawn(b,b[R][C],8);
            AnySpawn=true;
            break;
        case 9:
            destroy->spawn(b,b[R][C],9);
            AnySpawn=true;
            break;
        case 10:
            destroy->spawn(b,b[R][C],10);
            AnySpawn=true;
            break;
        case 11:
            destroy->spawn(b,b[R][C],11);
            AnySpawn=true;
            break;
        case 12:
            destroy->spawn(b,b[R][C],12);
            AnySpawn=true;
            break;
        case 13:
            destroy->spawn(b,b[R][C],13);
            AnySpawn=true;
            break;
        case 14:
            destroy->spawn(b,b[R][C],14);
            AnySpawn=true;
            break;
        case 15:
            destroy->spawn(b,b[R][C],15);
            AnySpawn=true;
            break;
        case 16:
            destroy->spawn(b,b[R][C],16);
            AnySpawn=true;
            break;
            */
        }
    }
    delete destroy;
    return AnySpawn;

}

bool MainWindow::JudgeV(int R, int C)
{
    int returnV;
    bool AnySpawn=false;
    destroy=new Vertical;
    returnV=destroy->condition(b,b[R][C]);
    if(returnV){
        switch(returnV){
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            score+=50;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            score+=50;
            break;
        }
    }
    delete destroy;
    return AnySpawn;

}

bool MainWindow::JudgeH(int R, int C)
{
    int returnV;
    bool AnySpawn=false;
    destroy=new Horizontal;
    returnV=destroy->condition(b,b[R][C]);
    if(returnV){
        switch(returnV){
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            score+=50;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            score+=50;
            break;
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeH3(int R, int C)
{
    int returnV;
    bool AnySpawn=false;
    destroy=new hor3;
    returnV=destroy->condition(b,b[R][C]);
    if(returnV){
        switch(returnV){
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            score+=10;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            score+=10;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            score+=10;
            break;
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeV3(int R, int C)
{
    int returnV;
    bool AnySpawn=false;
    destroy=new ver3;
    returnV=destroy->condition(b,b[R][C]);
    if(returnV){
        switch(returnV){
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            score+=10;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            score+=10;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            score+=10;
            break;
        }
    }
    delete destroy;
    return AnySpawn;
}

void MainWindow::bornzero()
{
    bool aaa=true;
    do{
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            if(b[i][j]->number==0){
                b[i][j]->setRandomNumber();
                b[i][j]->setButtonPicture();

            }
        }
    }
    aaa=fallcheck();
    }while(aaa==true);
}

void MainWindow::fillzero()
{
do{
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            if(b[i][j]->number==0){
                for(int k=i;k>=0;k--){
                    if(b[k][j]->number!=0){
                        b[i][j]->number=b[k][j]->number;
                        b[k][j]->number=0;
                        break;
                    }
                }
            }
        }
    }

    //RenewPicture();
    }while(fallcheck()==true);
}

bool MainWindow::fallcheck()
{
    bool result=false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeStar(i,j))
                result=true;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeL(i,j))
                result=true;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeV(i,j))
                result=true;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeH(i,j))
                result=true;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeH3(i,j))
                result=true;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeV3(i,j))
                result=true;
        }
    }
    RenewPicture();
    return result;
}


