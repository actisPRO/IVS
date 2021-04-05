#include <string>

#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calc)
{
    number1 = 0;
    number2 = 0;
    operation = None;

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

void Calc::showError(QString error)
{
    number1 = 0;
    number2 = 0;
    operation = None;

    ui->lineEdit->setText(error);
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

void Calc::on_num_dot_released()
{
    //if (ui->lineEdit->text().contains('.')) return;

    addDigit('.');
}

void Calc::on_backspace_released()
{
    if (ui->lineEdit->text() == "0") return; // do nothing as zero is an empty input
    if ((!ui->lineEdit->text().startsWith('-') && ui->lineEdit->text().length() == 1) // only one digit => set input to zero
            || (ui->lineEdit->text().startsWith('-') && ui->lineEdit->text().length() == 2)) // two symbols, but the first one is minus
        ui->lineEdit->setText("0");
    else
    {
        auto input = ui->lineEdit->text();
        input.resize(input.length() - 1);
        ui->lineEdit->setText(input);
    }
}

void Calc::on_clear_entry_released()
{
    ui->lineEdit->setText("0");
}

void Calc::on_global_clear_released()
{
    number1 = 0;
    number2 = 0;
    operation = None;

    ui->lineEdit->setText("0");
}

void Calc::on_op_sign_released()
{
    bool ok = false;
    double input = ui->lineEdit->text().toDouble(&ok);

    if (!ok)
    {
        showError("Conversion error!");
        return;
    }

    input = 0 - input;
    ui->lineEdit->setText(QString::number(input));
}
