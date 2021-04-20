/**
 * @file    calc.h
 * @author  Denis Karev (xkarev00@stud.fit.vutbr.cz)
 *
 * @brief   Header file for the calculator GUI.
 */

#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Calc; }
QT_END_NAMESPACE

class Calc : public QMainWindow
{
    Q_OBJECT
public:
    Calc(QWidget *parent = nullptr);
    ~Calc();

    /**
     * @brief Keyboard event handler for keyboard input.
     * @param event
     */
    void keyPressEvent(QKeyEvent *event);

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

    void on_op_root_released();

    void on_op_ln_released();

    void on_op_pow_released();

    void on_op_fac_released();

private:
    Ui::Calc *ui;

    /**
     * @brief Is the first number set, or does it contain the default (zero) value.
     */
    bool number1_set;

    /**
     * @brief Result of the previous operation.
     *
     * Dividend for division operation.
     * Radicant in root operation.
     * Base in pow opeartion.
     * Number in factorial and natural logarithm operations, if number2 is not set.
     */
    double number1;

    /**
     * @brief User input.
     * Divisor for division operation.
     * Index in root operation.
     * Exponent in pow operation.
     * Number in factorial and natural logarithm operations, if set.
     */
    double number2;

    /**
     * @brief If true, next input will erase content in the window
     */
    bool waitingForInput;

    /**
     * @brief Operation, selected by user
     */
    OperationType operation;

    /**
     * @brief Operation, selected by user before the one in 'operation' variable
     */
    OperationType previousOperation;

    /**
     * @brief Updates the font size of the result label to match the number of characters.
     */
    void updateTextSize();

    /**
     * @brief Updates the equation label.
     * @param First number
     * @param Second number
     * @param Operation type
     * @param If true, will be formatted as follows: n1 OP n2 = or OP(np1, np2). If false, np1 OP or OP(np1, ?)
     */
    void updateEquationLabel(double number1, double number2, OperationType operation, bool showNumber2 = true);

    /**
     * @brief Adds a digit to the result label
     * @param Digit
     */
    void addDigit(char digit);

    /**
     * @brief Cleans the buffer (number1, number2 and operation) and shows an error message in the result label
     * @param Error message
     */
    void showError(QString error);

    /**
     * @brief Performs a calculation (based on number1, number2 and operation variables).
     * @param Will be true, if the operation was succesfull.
     * @return Result of the calculation.
     */
    double performCalculation_2op(bool *ok = nullptr);

    /**
     * @brief Performs an operation: sets values of number1, number2, updates operation and previousOperation and calls performCalculation (if needed)
     * @param Operation, chosen by user.
     */
    void performOperation(OperationType type);
};
#endif // CALC_H
