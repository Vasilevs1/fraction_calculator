#ifndef FRACTION_H
#define FRACTION_H
#include <QTextEdit>
class Fraction
{
public:
    Fraction(int num,int denom);
    int numerator;
    int denomenator;
    void fshort();
    void m(int mn);
    Fraction();
};


#endif // FRACTION_H
