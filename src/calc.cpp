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
    previousOperation = None;
    operation = None;
    waitingForInput = false;

    this->installEventFilter(this);
    ui->setupUi(this);
}

Calc::~Calc()
{
    delete ui;
}

/*bool Calc::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Backspace)
        {
            ui->backspace->animateClick();
            return true;
        }
    }

    return QWidget::eventFilter(target, event);
}*/

void Calc::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_0)
    {
        ui->num_0->animateClick();
    }
    else if (event->key() == Qt::Key_1)
    {
        ui->num_1->animateClick();
    }
    else if (event->key() == Qt::Key_2)
    {
        ui->num_2->animateClick();
    }
    else if (event->key() == Qt::Key_3)
    {
        ui->num_3->animateClick();
    }
    else if (event->key() == Qt::Key_4)
    {
        ui->num_4->animateClick();
    }
    else if (event->key() == Qt::Key_5)
    {
        ui->num_5->animateClick();
    }
    else if (event->key() == Qt::Key_6)
    {
        ui->num_6->animateClick();
    }
    else if (event->key() == Qt::Key_7)
    {
        ui->num_7->animateClick();
    }
    else if (event->key() == Qt::Key_8)
    {
        ui->num_8->animateClick();
    }
    else if (event->key() == Qt::Key_9)
    {
        ui->num_9->animateClick();
    }
    else if (event->key() == Qt::Key_Period || event->key() == Qt::Key_Comma)
    {
        ui->num_dot->animateClick();
    }
    else if (event->key() == Qt::Key_Plus)
    {
        ui->op_add->animateClick();
    }
    else if (event->key() == Qt::Key_Minus)
    {
        ui->op_sub->animateClick();
    }
    else if (event->key() == Qt::Key_Asterisk || event->key() == Qt::Key_multiply)
    {
        ui->op_mult->animateClick();
    }
    else if (event->key() == Qt::Key_Slash || event->key() == Qt::Key_division)
    {
        ui->op_div->animateClick();
    }
    else if (event->key() == Qt::Key_Equal || event->key() == Qt::Key_Enter)
    {
        ui->op_eq->animateClick();
    }
    else if (event->key() == Qt::Key_Backspace)
    {
        ui->backspace->animateClick();
    }
    else if (event->key() == Qt::Key_Delete)
    {
        ui->clear_entry->animateClick();
    }
}

void Calc::addDigit(char digit)
{
    if (ui->result->text() == "0" || waitingForInput)
    {
        waitingForInput = false;
        ui->result->setText((QString) digit);
        return;
    }

    if (ui->result->text().length() >= MAX_DIGITS) return;

    ui->result->setText(ui->result->text() + digit);
}

void Calc::showError(QString error)
{
    number1 = 0;
    number2 = 0;
    operation = None;

    ui->result->setText(error);
    waitingForInput = true;
}

double Calc::performCalculation(bool *ok)
{
    *ok = true;
    switch (operation)
    {
        case None:
            return number1;
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

void Calc::performOperation(OperationType nextOperation)
{
    // Means, that there was no input (eg. user pressed 5, then +, then -):
    // user wants to change the operation
    if (nextOperation != None && waitingForInput)
    {
        operation = nextOperation;
        return;
    }

    waitingForInput = true;
    bool ok = true;
    if (!number1_set)
    {
        number1 = ui->result->text().toDouble(&ok);
        if (!ok)
        {
            showError("Conversion error!");
            return;
        }
        number1_set = true;
        operation = nextOperation;
    }
    else
    {
        // If user presses = button more, then once, we want to repeat the latest 'normal'
        // operation, using old number2 and displayed text, which is stored in number1 (as a result of the
        // previous equation)
        if (nextOperation == None && operation == None)
        {
            operation = previousOperation;
        }
        else
        {
            number2 = ui->result->text().toDouble(&ok);
            if (!ok)
            {
                showError("Conversion error!");
                return;
            }
        }

        number1 = performCalculation(&ok);
        if (!ok) return;

        auto result = QString::asprintf("%.16g", number1);
        ui->result->setText(result);

        // If user presses the = button again, program will repeat the previous operation
        // using the same number2, but with a new number1
        previousOperation = operation;
        operation = nextOperation;
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
    if (ui->result->text().contains('.')) return;

    addDigit('.');
}

void Calc::on_backspace_released()
{
    if (ui->result->text() == "0") return; // do nothing as zero is an empty input
    if ((!ui->result->text().startsWith('-') && ui->result->text().length() == 1) // only one digit => set input to zero
            || (ui->result->text().startsWith('-') && ui->result->text().length() == 2)) // two symbols, but the first one is minus
        ui->result->setText("0");
    else
    {
        auto input = ui->result->text();
        input.resize(input.length() - 1);
        ui->result->setText(input);
    }
}

void Calc::on_clear_entry_released()
{
    ui->result->setText("0");
    waitingForInput = true;
}

void Calc::on_global_clear_released()
{
    number1_set = false;
    number1 = 0;
    number2 = 0;
    operation = None;

    ui->result->setText("0");
}

void Calc::on_op_sign_released()
{
    bool ok = false;
    double input = ui->result->text().toDouble(&ok);

    if (!ok)
    {
        showError("Conversion error!");
        return;
    }

    input = 0 - input;
    ui->result->setText(QString::number(input));
}

void Calc::on_op_add_released()
{
    performOperation(Addition);
}

void Calc::on_op_sub_released()
{
    performOperation(Substraction);
}

void Calc::on_op_mult_released()
{
    performOperation(Multiplcation);
}

void Calc::on_op_div_released()
{
    performOperation(Division);
}

void Calc::on_op_eq_released()
{
    performOperation(None);
}


