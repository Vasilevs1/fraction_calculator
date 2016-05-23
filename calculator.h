#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "fraction.h"
namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT
    Fraction *f1;
    Fraction *f2;
    Fraction *fres;
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;
public slots:
    void del();
    void umn();
    void plus();
    void minus();
};

#endif // CALCULATOR_H
