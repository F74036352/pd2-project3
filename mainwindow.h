#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"blank.h"
#include "destroy.h"
#include "star.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void GameStart();
    void setClickedPicture(Blank*a);
    bool Judge(int row1,int col1,int row2,int col2);
    bool JudgeStar(int R,int C);
    void RenewPicture();
public slots:
    void button_clicked(int R,int C);

private:
    Ui::MainWindow *ui;
    Blank* b[10][10];
    int record_R;
    int record_C;
    bool isClicked;
    Destroy* destroy;
};

#endif // MAINWINDOW_H
