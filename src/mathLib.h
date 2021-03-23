// $Author:     Jan Řezníček <xrezni29@stud.fit.vutbr.cz>
// $Name:       mathLibrary



class mathLib
{
public:



    
    //addition 2 numbers, returns result of addition 
    double addition(double number1, double number2);

    //number1 - number2 return result 
    double subtraction(double number1, double number2);


    //multiply 2 numbers, return  result of multiplication
    double multiply(double number1, double number2);

  
    //divident/divisor return result error message for divisor = 0 
    double division(double divident, double divisor);

    //return sqrt(radicant) work for radicant >= 0 else return error message 
    double sqrt(double index,double radicant);


    //expoent can be only int, return exp(base)
    double pow(double exponent, double base);


    //return factorial of number, work for number(int) >= 0 error message for not unsigned int 
    double factorial(double number);

    double log(double number);


};

