#include "fraction.h"

Fraction::Fraction(int num,int denom)
{
    numerator = num;
    denomenator = denom;
}
Fraction::Fraction()
{
    numerator=0;
    denomenator=0;
}

void Fraction::setdisplay(QTextEdit *a)
{
  d=a;
}

void Fraction::display()
{
    d->append(QString::number(numerator)+" "+ QString::number(denomenator));
}


void Fraction::fshort()
{
    int i=1;
    do
    {
        i++;
       if((denomenator % i==0) && (numerator % i==0))
       {
          numerator = numerator/i;
          denomenator = denomenator/i;
          i=1;
       }

    }while(i<300000);
}

void Fraction::m(int mn)
{
    numerator = numerator*mn;
    denomenator = denomenator*mn;
}

