#include <string>

#include "calc.h"
#include "ui_calc.h"
#include "mathLib.h"

#define MAX_DIGITS 16

mathLib math = mathLib();

Calc::Calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calc)
{
    number1_set = false;
    number1 = 0;
    number2 = 0;
    operation = None;
    waitingForInput = false;

    ui->setupUi(this);
}

Calc::~Calc()
{
    delete ui;
}

void Calc::addDigit(char digit)
{
    if (ui->lineEdit->text() == "0" || waitingForInput)
    {
        waitingForInput = false;
        ui->lineEdit->setText((QString) digit);
        return;
    }


    if (ui->lineEdit->text().length() >= MAX_DIGITS) return;

    ui->lineEdit->setText(ui->lineEdit->text() + digit);
}

void Calc::showError(QString error)
{
    number1 = 0;
    number2 = 0;
    operation = None;

    ui->lineEdit->setText(error);
    waitingForInput = true;
}

double Calc::performOperation(bool *ok)
{
    *ok = true;
    switch (operation)
    {
        case Addition:
        return math.addition(number1, number2);
        case Substraction:
        return math.subtraction(number1, number2);
        case Multiplcation:
        return math.multiply(number1, number2);
        case Division:
        try {
            return math.division(number1, number2);
        } catch (std::runtime_error) {
            *ok = false;
            showError("Cannot divide by zero");
            return 0;
        }
    }
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
    if (ui->lineEdit->text().contains('.')) return;

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
    number1_set = false;
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

void Calc::on_op_add_released()
{
    bool ok = false;
    number2 = ui->lineEdit->text().toDouble(&ok);
    if (!ok)
    {
        showError("Conversion error!");
        return;
    }

    if (!number1_set)
    {
       number1 = number2;
    }
    else
    {
       number1 = performOperation(&ok);
    }
    number1_set = true;
    operation = Addition;

    auto result = QString::asprintf("%.16g", number1);
    ui->lineEdit->setText(result);

    waitingForInput = true;
}

void Calc::on_op_sub_released()
{
    bool ok = false;
    number2 = ui->lineEdit->text().toDouble(&ok);
    if (!ok)
    {
        showError("Conversion error!");
        return;
    }

    if (!number1_set)
    {
       number1 = number2;
    }
    else
    {
       number1 = performOperation(&ok);
    }
    number1_set = true;
    operation = Substraction;

    auto result = QString::asprintf("%.16g", number1);
    ui->lineEdit->setText(result);

    waitingForInput = true;
}

void Calc::on_op_mult_released()
{
    bool ok = false;
    number2 = ui->lineEdit->text().toDouble(&ok);
    if (!ok)
    {
        showError("Conversion error!");
        return;
    }

    if (!number1_set)
    {
       number1 = number2;
    }
    else
    {
       number1 = performOperation(&ok);
    }
    number1_set = true;
    operation = Multiplcation;

    auto result = QString::asprintf("%.16g", number1);
    ui->lineEdit->setText(result);

    waitingForInput = true;
}

void Calc::on_op_div_released()
{
    bool ok = false;
    number2 = ui->lineEdit->text().toDouble(&ok);
    if (!ok)
    {
        showError("Conversion error!");
        return;
    }

    if (!number1_set)
    {
       number1 = number2;
    }
    else
    {
       number1 = performOperation(&ok);
    }
    number1_set = true;
    operation = Division;

    auto result = QString::asprintf("%.16g", number1);
    ui->lineEdit->setText(result);

    waitingForInput = true;
}

void Calc::on_op_eq_released()
{

}
