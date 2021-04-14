/**
 * @file stddev.cpp
 * @author Matsvei Hauryliuk (xhaury00)
 *
 * @brief Calculation of standard deviation
 */

#include <iostream>
#include <math.h>
#include "mathLib.h"

long double calculate_mean(long double* mean, long double numbers[2000], int* i);

long double calculate_deviation(long double* s, int* N, long double* deviation);

int main()
{
    mathLib lib;
    long double mean, old_mean, s, deviation = 0.0;
    int i = 1;
    int N = 0;
    long double numbers[2000];
    while(scanf("%Lf", &numbers[i]) == 1)
    {
        ++N;
        old_mean = mean;
        mean = calculate_mean(&mean, numbers, &i);
        s = lib.addition(s, (numbers[i] - mean) * (numbers[i] - old_mean));
        ++i;
    }
    deviation = calculate_deviation(&s, &N, &deviation);
    printf("%Lf\n", deviation);

    return 0;
}

/**
 * @brief mean
 *
 * Calculates mean value for a given array of numbers
 *
 * @param   mean
 * @param   numbers
 * @param   i
 *
 * @return  Returns mean value
 * */
long double calculate_mean(long double* mean, long double numbers[2000], int* i)
{
    mathLib lib;
    *mean = lib.addition(*mean, (numbers[*i] - *mean) / *i);
    return *mean;
}

/**
 * @brief deviation
 *
 * Calculates deviation for a given array of numbers
 *
 * @param   s
 * @param   N
 * @param   deviation
 *
 * @return  Returns deviation
 * */
long double calculate_deviation(long double* s, int * N, long double * deviation)
{
    mathLib lib;
    *deviation = lib.division(*s, *N - 1);
    *deviation = lib.sqrt(2, *deviation);
    return *deviation;
}