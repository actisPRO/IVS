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

    void on_global_clear_released();

    void on_num_dot_released();

    void on_op_sign_released();

    void on_op_add_released();

    void on_op_sub_released();

    void on_op_mult_released();

    void on_op_div_released();

    void on_op_eq_released();

private:
    Ui::Calc *ui;

    // Is the first number set, or does it contain the default value?
    bool number1_set;

    // Result of the previous equation. Zero by default
    double number1;

    // The number the user is able to change
    double number2;

    // True means, that next input will erase current text of the line edit.
    bool waitingForInput;

    // Current operation
    OperationType operation;

    // Adds a digit to the line edit
    void addDigit(char digit);

    // Cleans the buffer (number1, number2 and operation) and shows an error message in the line edit
    void showError(QString error);

    // Performs an operation (based on number1, number2 and operation variables)
    // @returns Result of the operation
    double performOperation(bool *ok);
};
#endif // CALC_H
