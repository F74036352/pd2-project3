#include "blank.h"

Blank::Blank(QWidget* parent,int R,int C):
    QObject(parent),row(R),column(C)
{
button=new QPushButton(parent);

}

Blank::~Blank()
{

}

