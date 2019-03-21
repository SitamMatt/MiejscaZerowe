#include <iostream>
#include <cmath>
#include <windows.h>
#include "pomoc.hpp"
#include <iomanip>
using namespace std;


void menu()
{
   cout <<"Wybierz numer funkcji : "<<endl;
   cout <<"[1] f(x) = (x^3)/2 + 2(x)^2 - x - 3 ;"<<endl;
   cout <<"[2] f(x) = sin(x/3) + 0.5 ;" <<endl;
   cout <<"[3] f(x) = (2^x) - 3 ;"<<endl;
   cout <<"[4] f(x) = [((2^x) - 3)^3] + 2x - 3 ;"<<endl;
}

double funOne(double x) {
	double y;
	double horner[4] = { 0.5,2,-1,-3 };                     // jakos poszlo tym honrerem
	int dlugosc = 4;
	y = horner[0];
	for (int i = 1; i < dlugosc; i++)
	{
		y = (y*x) + horner[i];
	}
	return y;
}

double fun2(double x) {
	double y = sin(x / 3.0) + 0.5;
	return y;
}

double fun3(double x) {
	double y = pow(2, x) - 3;
	return y;
}

double fun4(double x) {
	double y = pow((pow(2, x) - 3), 3) + (2 * x) - 3;
	return y;
}


double check(double value1, double value2)
{
    if (value1* value2<0)
    {
        return 1;
    }
    else
    {
        cout <<endl<<"Bledne przedzialy, try again. "<<endl;
        return 0;
    }



}


