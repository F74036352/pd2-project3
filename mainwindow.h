#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include"blank.h"
#include "destroy.h"
#include "star.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"
#include <cstdlib>
#include <ctime>
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
    bool JudgeL(int R,int C);
    bool JudgeV(int R,int C);
    bool JudgeH(int R,int C);
    bool JudgeH3(int R,int C);
    bool JudgeV3(int R,int C);
    void bornzero();
    void fillzero();
    bool fallcheck();
public slots:
    void button_clicked(int R,int C);
signals:
    void quit(int star,int score);


private:
    Ui::MainWindow *ui;
    Blank* b[10][10];
    int record_R;
    int record_C;
    bool isClicked;
    Destroy* destroy;
    int score;
    int step;
    int stars;
};

#endif // MAINWINDOW_H
