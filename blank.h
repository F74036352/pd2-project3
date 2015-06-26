#ifndef BLANK_H
#define BLANK_H
#include<QObject>
#include<QPushButton>

class Blank:public QObject
{
    Q_OBJECT
public:
    Blank();
    explicit Blank(QWidget*parent,int R,int C );
    ~Blank();
    QPushButton *button;
    const int row;
    const int column;
    int number;
    void setButtonPicture();
    void setRandomNumber();
public slots://信號
    void click();
signals:
    void Click(int R,int C);
};

#endif // BLANK_H
