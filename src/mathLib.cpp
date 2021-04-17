/**
 * @file mathLib.cpp
 * @author Smíšková Lucie (xsmisk00)
 *
 * @brief Implementation of math library mathLib.h
 */




#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "mathLib.h"

using namespace::std;
const float eps = 0.000000000000001;
const double e = 2.7182818284590452353602874713526624977572470936;


/**
   * @brief      addition
   *
   * add two numbers
   *
   * @param      number1 added number
   * @param      number2 added number
   *
   * @return     returns number1 + number2
*/
double mathLib::addition(double number1, double number2)
{
    return number1 + number2;
}


/**
   * @brief      substraction
   *
   * subtracts two numbers
   *
   * @param      number1 minuend
   * @param      number2 subtrahend
   *
   * @return     returns number1 - number2
*/
double mathLib::subtraction(double number1, double number2)
{
    return number1 - number2;
}


/**
   * @brief      multiplication
   *
   * multyply two numbers
   *
   * @param      number1 multiplyed number
   * @param      number2 multiplyed number
   *
   * @return     returns number1 * number2
*/
double mathLib::multiply(double number1, double number2)
{
    return number1 * number2;
}


/**
   * @brief      division
   *
   * divides two numbers
   * divisor can not be zero
   *
   * @param      divident
   * @param      divisor
   *
   * @return     if divisor equals zero returns error messege, else returns divident/divisir
*/
double mathLib::division(double divident, double divisor)
{
    if(divisor == 0)
        throw std::runtime_error("Can not divide by zero");
    return divident / divisor;
}


/**
   * @brief      sqrt
   *
   * counts square root
   * work for radicant grather or equal to zero and natural index
   *
   * @param      index
   * @param      radicant
   *
   * @return     if radicant is lower than zero or index is not natural number retuns error messege, else returns result of square root
*/
double mathLib::sqrt(long long index,double radicant)
{
    if (radicant <0)
        throw std::runtime_error("Radicant must be greater or equal to zero.");
    if (index < 0)
        throw std::runtime_error("Index must be a natural number.");
    double x0, x = 1;
    do {
        x0 = x;
        x = index - 1;
        x *= pow(index,x0);
        x += radicant;
        x /= (index * pow((index-1), x0));
    } while (((x0 - x) > eps)  || ((x - x0) > eps));

    return x;
}


/**
   * @brief      pow
   *
   * counts base to exponent power
   * work for natural exponent
   *
   * @param      exponent
   * @param      base
   *
   * @return     if exponent is not natural number returns error messege, else returns base^exponent
*/
double mathLib::pow(long long exponent, double base)
{
    if (exponent < 0)
        throw std::runtime_error("Exponent is not a natural number.");
    double returnValue = 1;
    for(int i = 0; i < exponent; i++) returnValue *= base;
    return returnValue;
}


/**
   * @brief      factorial
   *
   * counts factorial of number
   * number has to be natural
   *
   * @param      number
   *
   * @return     if number is not natural returns error messege, else returns factorial of number
*/
long long mathLib::factorial(long long number)
{
    if (number < 0)
        throw std::runtime_error("Factorial is definied only for non-negative numbers");
    if (number > 20)
        throw std::runtime_error("Factorial max number is 20");

    long long returnValue = 1;
    for(int i = 1; i <= number; i++)
        returnValue *= i;
    return returnValue;
}


/**
   * @brief      division
   *
   * counts natural logarithm of number
   * number has to be grater than zero
   * used diferrent method for number lower than two and others
   *
   * @param      number
   *
   * @return     if number is lower or equals to zero returns error messege, else returns result of natural logarithm
*/
double mathLib::log(double number)
{
    double returnValue = 0;
    if (number <= 0)
        throw std::runtime_error("Number has to be bigger than zero.");
    if (number < 2)
    {
        double x0 = 54;
        for (int i = 1; (((x0 - returnValue) > eps)  || ((returnValue - x0) > eps)); i++)
        {
            x0 = returnValue;
            if ((i % 2) == 0)
                returnValue -= (pow(i, (number-1)) / i);
            else
                returnValue += (pow(i, (number-1)) / i);
        }
        return returnValue;
    }

    double i;
    for(i = 0; number >= e; i++)
    {
        number /= e;
    }

    double k = 1;
    for (int j = 0; j < 1000; j++)
    {
        number *= number;
        k /= 2;
        if (number > e)
        {
            i += k;
            number /= e;
        }
    }
    return i;

    return returnValue;
}
