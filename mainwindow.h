#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"blank.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void button_clicked(int R,int C);

private:
    Ui::MainWindow *ui;
    Blank* b[10][10];
};

#endif // MAINWINDOW_H
