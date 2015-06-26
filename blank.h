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
};

#endif // BLANK_H
