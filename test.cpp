// $Author:     Jan Řezníček <xrezni29@stud.fit.vutbr.cz>
// $Name:       Tdd tests for mathLibrary
//    g++ test.cpp mathLib.h -lgtest -lgtest_main -pthread
#include <vector>
#include "gtest/gtest.h"
#include "mathLib.h"
#include <cmath>
#include <iostream>
using namespace std;

//============================================================================//
//============================================================================//


double values[] = { -1500.15, 0 , 6800.765325 , -1836543,	164598,	-0.465414,	0.564654,	13682.5654,	14234.13456,	-141513.589,	-6853.2,	0.54647,	-51617.123,	-69,	1647713.134	};
double values2[] = {-3652.546,	14515.561,	2326.565,	5649,	-516413,	4,	-135.4566,	-15667.1314,	1384,	0,	16497,	0.122141,	0.999999,	123654.1456,	0.01		};

mathLib m;

float eps = 0.0001;
TEST(test ,addition)
{
    double result[] = {-5152.696,14515.561,	9127.330325,-1830894,-351815,3.534586,-134.891946,-1984.566,15618.13456,-141513.589,9643.8,	0.668611,-51616.123001,123585.1456,1647713.144	};

    for (int i = 0; i < 15; i++)
    {
        
        EXPECT_DOUBLE_EQ(m.addition(values[i],values2[i]), result[i]);
        
    }
    
   
}
TEST(test ,subtraction)
{
    double result[] = {2152.396,	-14515.561,	4474.200325	,-1842192	,681011	,-4.465414	,136.021254	,29349.6968	,12850.13456	,-141513.589	,-23350.2	,0.424329	,-51618.122998999999	,-123723.1456	,1647713.124		};

    for (int i = 0; i < 15; i++)
    {
        
        EXPECT_DOUBLE_EQ(m.subtraction(values[i],values2[i]), result[i]);
        
    }
    
   
}
//interval because double = double
::testing::AssertionResult Interval(double val, double interval)
{
    if((val >= interval-0.01) && (val <= interval+0.01))
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure();
}


TEST(test,pow)
{
    double result[] = {-1500.15,0,314538177833.184387,11376388239525403636531200.00000,120815531657301110271508480.00000,0.01016,0.01830,1228401282807909867115002200064000.00000,23987202604909806707047591885108412416.00000,3220931248021127533046904541636365596115258228867072.0000,46966350.2399999946};
    int exp[] = {1,2,3,4,5,6,7,8,9,10,2,1,3};
    int n = 20;
    for (int i = 0; i < 11; i++)
    {
        EXPECT_TRUE(Interval(m.pow(values[i],exp[i]), result[i]));
      
        cout.precision(15);
        cout << "Pořadí: " << i << " Umocňování: "<< endl <<values[i]<<"^"<<exp[i] << "  = " << fixed << result[i]<< endl;
    }
    
   
}
TEST(test,factorial)
{
    double result[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,1307674368000,2432902008176640000 };
    double valuesF[] = {0,1,2,3,4,5,6,7,8,9,10,15,20};
    for (int i = 0; i < 12; i++)
    {
        EXPECT_EQ(m.factorial(valuesF[i]),result[i]);
        cout << "Pořadí: " << i << " Faktoriál: "<< endl<< valuesF[i]<< "  = " << fixed << result[i]<< endl;
    }
    EXPECT_ANY_THROW(m.factorial(-10));
    EXPECT_ANY_THROW(m.factorial(1.547));
}
TEST(test,sqrt)
{
    double valuesS[] = {1,2.5,3.5,6.7,153.12,168.12,170.12};
    double result[] = {1,1.5811388301,1.5182944859,1.2095044771,28.6212071505,7.9828177546,1217.3499860497};
    double radicant[] = {1.0,2.0,3.0,10.0,1.5,2.467,0.723};
    for (int i = 0; i < 7; i++)
    {
        EXPECT_TRUE(Interval(m.sqrt(values[i],radicant[i]), result[i]));
        cout << "Pořadí: " << i << " Odmocnina: "<< endl<< valuesS[i]<< " , "<< radicant[i]<< "  = " << fixed << result[i]<< endl;

    }
    EXPECT_ANY_THROW(m.sqrt(1,-17));

}
TEST(test,division)
{
    double result[] = {49.849497999999997,47465.459999999999127,30.367719769673705,265.180478582670162,-0.545203530118280,0.138213334382348,0.000000257520535,-0.000175826612903,-0.001879254790405,-0.102483016119373,-91328.556816993455868};
    double divisor[] = {-1000,1,1563,17892.123,76598,514654.5615,564654,4464,-65451.4761,7464.6515,-0.784114};
    double valuesD[] = {-49849.498,47465.46,47464.746,4744641.74,-41761.5,71132.123,0.14541,-0.78489,123,-765,71612};
    for (int i = 0; i < 11; i++)
    {
        EXPECT_TRUE(Interval(m.division(valuesD[i],divisor[i]), result[i]));
    }
    EXPECT_ANY_THROW(m.division(1,0));

}
TEST(test,multiply)
{
    double result[] ={5479366.881900000385940,0.000000000000000,15822422.578358625993133,-10374631407.000000000000000,-85000546974.000000000000000,-1.861656000000000,-76.486111016400002,-214366550.010893553495407,19700042.231040000915527,-0.000000000000000,-113057240.399999991059303,0.066746392270000,-51617.071382876994903};
    for (int i = 0; i < 13; i++)
    {
        EXPECT_TRUE(Interval(m.multiply(values[i],values2[i]), result[i]));
    }
}
TEST(test,log)
{
    double valuesL[] = {1,1.5,1.8,288,1654315.1563,14657.123,474761.12313,0.0014657};
    double result[] = {0.000000000000000,0.405465108108164,0.587786664902119,5.662960480135946,14.318897678313400,9.592681707886747,13.070567057847144,-6.525422334931020};
      for (int i = 0; i < 8; i++)
    {
        EXPECT_TRUE(Interval(m.log(valuesL[i]), result[i]));
    
    }
    EXPECT_ANY_THROW(m.log(0));
    EXPECT_ANY_THROW(m.log(-1));
}



int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}




