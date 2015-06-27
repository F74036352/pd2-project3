#include "blank.h"

Blank::Blank(QWidget* parent,int R,int C):
    QObject(parent),row(R),column(C)
{
button=new QPushButton(parent);
button->setGeometry(column*50,row*50,50,50);
connect(button,SIGNAL(clicked()),this,SLOT(click()));//button發出信號，SLOT接收，給click

}

Blank::~Blank()
{

}

void Blank::click()
{
    emit Click(row,column);

}
void Blank::setRandomNumber(){
    number=rand()%4+1;
    return;
}
void Blank::setButtonPicture(){
    switch (number) {
    case 1:
        button->setIcon(QIcon(QPixmap(":/picture/Blue_o.png")));
        break;
    case 11:
        button->setIcon(QIcon(QPixmap(":/picture/Blue_v.png")));
        break;
    case 12:
        button->setIcon(QIcon(QPixmap(":/picture/Blue_h.png")));
        break;
    case 13:
        button->setIcon(QIcon(QPixmap(":/picture/Blue_w.png")));
        break;
    case 2:
        button->setIcon(QIcon(QPixmap(":/picture/Green_o.png")));
        break;
    case 21:
        button->setIcon(QIcon(QPixmap(":/picture/Green_v.png")));
        break;
    case 22:
        button->setIcon(QIcon(QPixmap(":/picture/Green_h.png")));
        break;
    case 23:
        button->setIcon(QIcon(QPixmap(":/icon/picture/Green_w.png")));
        break;
    case 3:
        button->setIcon(QIcon(QPixmap(":/picture/Red_o.png")));
        break;
    case 31:
        button->setIcon(QIcon(QPixmap(":/picture/Red_v.png")));
        break;
    case 32:
        button->setIcon(QIcon(QPixmap(":/picture/Red_h.png")));
        break;
    case 33:
        button->setIcon(QIcon(QPixmap(":/picture/Red_w.png")));
        break;
    case 4:
        button->setIcon(QIcon(QPixmap(":/picture/Yellow_o.png")));
        break;
    case 41:
        button->setIcon(QIcon(QPixmap(":/picture/Yellow_v.png")));
        break;
    case 42:
        button->setIcon(QIcon(QPixmap(":/picture/Yellow_h.png")));
        break;
    case 43:
        button->setIcon(QIcon(QPixmap(":/picture/Yellow_w.png")));
        break;
    case 5:
        button->setIcon(QIcon(QPixmap(":/picture/Bomb.png")));
        break;
    default:
        button->setIcon(QIcon(QPixmap("Nopic")));

    }
}
void Blank::operator + (Blank *a){
    int tmp_num=a->number;
    a->number=number;
    number=tmp_num;
    setButtonPicture();
    a->setButtonPicture();
}
