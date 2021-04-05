#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calc)
{
    ui->setupUi(this);
}

Calc::~Calc()
{
    delete ui;
}

void Calc::addDigit(char digit)
{
    if (ui->lineEdit->text() == "0")
    {
        ui->lineEdit->setText((QString) digit);
        return;
    }

    ui->lineEdit->setText(ui->lineEdit->text() + digit);
}

void Calc::on_num_1_released()
{
    addDigit('1');
}

void Calc::on_num_2_released()
{
    addDigit('2');
}

void Calc::on_num_3_released()
{
    addDigit('3');
}

void Calc::on_num_4_released()
{
    addDigit('4');
}

void Calc::on_num_5_released()
{
    addDigit('5');
}

void Calc::on_num_6_released()
{
    addDigit('6');
}

void Calc::on_num_7_released()
{
    addDigit('7');
}

void Calc::on_num_8_released()
{
    addDigit('8');
}

void Calc::on_num_9_released()
{
    addDigit('9');
}

void Calc::on_num_0_released()
{
    addDigit('0');
}

void Calc::on_backspace_released()
{

}
