#include <iostream>
#include <cmath>
#include <windows.h>
#include "pomoc.hpp"
#include <iomanip>
#include <chrono>
using namespace std;


double funf(double a, double b, std::function<double(double)> funkcja)
{
    double ret = (b*funkcja(a)- a*funkcja(b))/(funkcja(a)-funkcja(b));
    return ret;
}

double falsii(double a, double b, double x0, std::function<double(double)> funkcja, int&i,int MaksIter)
{
	auto start = std::chrono::system_clock::now();
	// wstepna inicjacja zmiennych
	double fb = funkcja(b), fa = funkcja(a), f0;
	x0 = b;
	//start petli
	do {
		x0 = funf(a, b, funkcja);
		f0 = funkcja(x0);

		if (f0 * fa < 0) {
			b = x0;
			fb = f0;
		}
		else {
			a = x0;
			fa = f0;
		}
		i++;
	} while (i < MaksIter && f0 != 0);

	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << "Czas wykonania: " << elapsed.count() << " mikrosekund" << endl;
	return x0;
}


double falsid(double a, double b, double x0, std::function<double(double)> funkcja, int&i,double  epsilon)
{
	auto start = std::chrono::system_clock::now();
	// wstepna inicjacja zmiennych
	double fb = funkcja(b), fa = funkcja(a), f0;
	x0 = b;
	//start petli
	do {
		x0 = funf(a, b, funkcja);
		f0 = funkcja(x0);

		if (f0 * fa < 0) {
			b = x0;
			fb = f0;
		}
		else {
			a = x0;
			fa = f0;
		}
		i++;
	} while (abs(f0) > epsilon && f0 != 0);
	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << "Czas wykonania: " << elapsed.count() << " mikrosekund" << endl;
	return x0;
}
