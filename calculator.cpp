#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    f1 = new Fraction;
    f2 = new Fraction;
    fres= new Fraction;
    f1->setdisplay(ui->displayer);
    f2->setdisplay(ui->displayer);
    fres->setdisplay(ui->displayer);
    ui->resultDenom->setReadOnly(1);
    ui->resultNum->setReadOnly(1);
    ui->firstNum->setMinimum(1);
    ui->firstNum->setMaximum(300000);
    ui->firstDenom->setMinimum(1);
    ui->firstDenom->setMaximum(300000);
    ui->secondNum->setMinimum(1);
    ui->secondNum->setMaximum(300000);
    ui->secondDenom->setMinimum(1);
    ui->secondDenom->setMaximum(300000);
    connect(ui->delButton,SIGNAL(clicked(bool)),this,SLOT(del()));
    connect(ui->umnButton,SIGNAL(clicked(bool)),this,SLOT(umn()));
    connect(ui->plusButton,SIGNAL(clicked(bool)),this,SLOT(plus()));
    connect(ui->minusButton,SIGNAL(clicked(bool)),this,SLOT(minus()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::del()
{
    ui->resultNum->clear();
    ui->resultDenom->clear();
    f1->numerator = ui->firstNum->value();
    f1->denomenator = ui->firstDenom->value();
    f2->numerator = ui->secondNum->value();
    f2->denomenator = ui->secondDenom->value();
    f1->fshort();
    f2->fshort();
    fres->numerator = f1->numerator * f2->denomenator;
    fres->denomenator = f1->denomenator * f2->numerator;
    fres->fshort();
    ui->label->setText("/");
    if(fres->denomenator == 1)
    {
        ui->resultNum->setText(QString::number(fres->numerator));
    }
    else{
    ui->resultNum->setText(QString::number(fres->numerator));
    ui->resultDenom->setText(QString::number(fres->denomenator));
    }
    fres->numerator = 0;
    fres->denomenator = 0;
}

void Calculator::umn()
{
    ui->resultNum->clear();
    ui->resultDenom->clear();
    f1->numerator = ui->firstNum->value();
    f1->denomenator = ui->firstDenom->value();
    f2->numerator = ui->secondNum->value();
    f2->denomenator = ui->secondDenom->value();
    f2->fshort();
    f1->fshort();
    fres->numerator = f1->numerator * f2->numerator;
    fres->denomenator = f1->denomenator * f2->denomenator;
    fres->fshort();
    ui->label->setText("*");
    if(fres->denomenator == 1)
    {
        ui->resultNum->setText(QString::number(fres->numerator));
    }
    else{
    ui->resultNum->setText(QString::number(fres->numerator));
    ui->resultDenom->setText(QString::number(fres->denomenator));
    }
    fres->numerator = 0;
    fres->denomenator = 0;

}

void Calculator::plus()
{
    ui->resultNum->clear();
    ui->resultDenom->clear();
    f1->numerator = ui->firstNum->value();
    f1->denomenator = ui->firstDenom->value();
    f2->numerator = ui->secondNum->value();
    f2->denomenator = ui->secondDenom->value();
    f1->fshort();
    f2->fshort();
    f1->display();
    f2->display();
if((f1->denomenator % f2->denomenator == 0)&&(f1->denomenator != f2->denomenator))
{
 int reserve = f1->denomenator / f2->denomenator;
f2->m(reserve);
f2->display();
}
else
{
    if((f2->denomenator % f1->denomenator == 0)&&(f2->denomenator !=f1->denomenator))
    {
     int reserve = f2->denomenator /f1->denomenator;
     f1->m(reserve);
    }
    else
    {
        int reserve;
        if(f1->denomenator > f2->denomenator)
        {
            for(int i=2;i<300000;i++)
            {
               if((f1->denomenator*i) % f2->denomenator == 0 )
               {
                   f1->m(i);
                   reserve = f1->denomenator /f2->denomenator;
                   f2->m(reserve);
                   break;
               }
            }
        }
        if(f2->denomenator >f1->denomenator)
        {
            for(int i =2;i<300000;i++)
            {
               if((f2->denomenator*i) % f1->denomenator ==0)
               {
                   f2->m(i);
                   reserve = f2->denomenator /f1->denomenator;
                   f1->m(reserve);
                   break;
               }

            }
        }
    }
}



fres->numerator = f1->numerator + f2->numerator;
fres->denomenator = f1->denomenator;
fres->fshort();
    ui->label->setText("+");
    if(fres->denomenator == 1)
    {
        ui->resultNum->setText(QString::number(fres->numerator));
    }
    else{
    ui->resultNum->setText(QString::number(fres->numerator));
    ui->resultDenom->setText(QString::number(fres->denomenator));
    }
    fres->numerator = 0;
    fres->denomenator = 0;
}

void Calculator::minus()
{
    ui->resultNum->clear();
    ui->resultDenom->clear();
    f1->numerator = ui->firstNum->value();
    f1->denomenator = ui->firstDenom->value();
    f2->numerator = ui->secondNum->value();
    f2->denomenator = ui->secondDenom->value();
    f1->fshort();
    f2->fshort();
    if((f1->denomenator % f2->denomenator == 0)&&(f1->denomenator != f2->denomenator))
    {
     int reserve = f1->denomenator / f2->denomenator;
    f2->m(reserve);
    f2->display();
    }
    else
    {
        if((f2->denomenator % f1->denomenator == 0)&&(f2->denomenator !=f1->denomenator))
        {
         int reserve = f2->denomenator /f1->denomenator;
         f1->m(reserve);
        }
        else
        {
            int reserve;
            if(f1->denomenator > f2->denomenator)
            {
                for(int i=2;i<300000;i++)
                {
                   if((f1->denomenator*i) % f2->denomenator == 0 )
                   {
                       f1->m(i);
                       reserve = f1->denomenator /f2->denomenator;
                       f2->m(reserve);
                       break;
                   }
                }
            }
            if(f2->denomenator >f1->denomenator)
            {
                for(int i =2;i<300000;i++)
                {
                   if((f2->denomenator*i) % f1->denomenator ==0)
                   {
                       f2->m(i);
                       reserve = f2->denomenator /f1->denomenator;
                       f1->m(reserve);
                       break;
                   }

                }
            }
        }
    }
    fres->numerator = f1->numerator - f2->numerator;
    fres->denomenator = f1->denomenator;
    ui->label->setText("-");
    if(fres->denomenator == 1)
    {
        ui->resultNum->setText(QString::number(fres->numerator));
    }
    else{
    ui->resultNum->setText(QString::number(fres->numerator));
    ui->resultDenom->setText(QString::number(fres->denomenator));
    }
    fres->numerator = 0;
    fres->denomenator = 0;
}


