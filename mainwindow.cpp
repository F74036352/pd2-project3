#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(500,520);
    this->setMinimumSize(500,520);
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

}
void MainWindow::GameStart(){
    for(int i=0;i<10;i++){//for1
        for(int j=0;j<10;j++){//for2
            b[i][j]->setRandomNumber();
            b[i][j]->setButtonPicture();
            if(j>=2 && b[i][j]->number==b[i][j-1]->number && b[i][j]->number==b[i][j-2]->number){//if
                j--;
            }//if
            if(i>=2 && b[i][j]->number==b[i-1][j]->number&&b[i][j]->number==b[i-2][j]->number){//if
                j--;
            }//if
        }//for2
    }//for1
}
