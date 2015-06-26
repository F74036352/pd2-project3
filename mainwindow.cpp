#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]=new Blank(this,i,j);//將row column回傳
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
