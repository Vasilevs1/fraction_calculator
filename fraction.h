#ifndef FRACTION_H
#define FRACTION_H
#include <QTextEdit>
#include <qstring.h>
class Fraction
{
 QTextEdit* d;
public:
    Fraction(int num,int denom);
    int numerator;
    int denomenator;
    void fshort();
    void m(int mn);
    Fraction();
    void setdisplay(QTextEdit*a);
    void display();
};


#endif // FRACTION_H
