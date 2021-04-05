#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calc; }
QT_END_NAMESPACE

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();

    typedef enum {
        None,
        Addition,
        Substraction,
        Multiplcation,
        Division,
        Factorial,
        Logarithm,
        Pow,
        Root
    } OperationType;

private slots:
    void on_num_1_released();

    void on_num_2_released();

    void on_num_3_released();

    void on_num_4_released();

    void on_num_5_released();

    void on_num_6_released();

    void on_num_7_released();

    void on_num_8_released();

    void on_num_9_released();

    void on_num_0_released();

    void on_backspace_released();

    void on_clear_entry_released();

private:
    Ui::Calc *ui;

    double number1;
    double number2;
    OperationType operation;

    // Adds a digit to the line edit
    void addDigit(char digit);
};
#endif // CALC_H
