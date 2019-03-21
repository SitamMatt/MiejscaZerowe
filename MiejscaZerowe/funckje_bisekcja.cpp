#include <iostream>
#include <cmath>
#include <windows.h>
#include "pomoc.hpp"
#include <iomanip>
#include <chrono>
using namespace std;

double bisi(double point1, double point2, double mid, std::function<double(double)> funkcja, int&iter,int i)
{
	auto start = std::chrono::system_clock::now();

	while (iter < i)
	{
		mid = (point1 + point2) / 2.0;
		if (funkcja(mid)*funkcja(point2) < 0)
		{
			point1 = mid;
		}
		else if (funkcja(mid)*funkcja(point1) < 0)
		{
			point2 = mid;
		}
		else cout << endl << "Podales pierwiatek" << endl;
		iter++;
	}

	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << "Czas wykonania: " << elapsed.count() << " mikrosekund" << endl;
	return mid;
}


double bisd(double point1, double point2, double mid, std::function<double(double)> funkcja, int&iter,double  e)
{
	auto start = std::chrono::system_clock::now();

	while (abs(funkcja(mid)) > e)
	{
		mid = (point1 + point2) / 2.0;
		if (funkcja(mid)*funkcja(point2) < 0)
		{
			point1 = mid;
		}
		else if (funkcja(mid)*funkcja(point1) < 0)
		{
			point2 = mid;
		}
		else cout << endl << "Podana liczba jest pierwiastkiem." << endl;

		iter++;
	}

	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << "Czas wykonania: " << elapsed.count() << " mikrosekund" << endl;
	return mid;
}
