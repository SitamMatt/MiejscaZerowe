#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <vector>

#include "pomoc.hpp"
#include "Plot.hpp"

using namespace std;

int main()
{
	//ustawianie sciezki do gnuplota
	Plot::set_GNUPlotPath("A:\\Program Files/gnuplot\\bin");


	double a, b, x0, fa, fb;
	char repeat = 't';
	double(*fun)(double) = nullptr;

	while (repeat == 't')
	{
		system("cls");
		menu();

		int opcja = 0;
		while (opcja < 1 || opcja>4)
		{
			cout << "Co wybierasz : ";
			cin >> opcja;

			if (opcja < 1 || opcja>4)
			{
				cout << "podales zla liczbe, try again : ";
			}
		}

		switch (opcja) {
		case 1:
			fun = fun1;
			break;
		case 2:
			fun = fun2;
			break;
		case 3:
			fun = fun3;
			break;
		case 4:
			fun = fun4;
			break;
		}

		int loop = 0;
		cout << endl << "Podaj przedzialy funkcji." << endl;
		while (loop != 1)
		{

			cout << "a = "; cin >> a;
			cout << "b = "; cin >> b;

			fa = fun(a);
			fb = fun(b);

			loop = check(fa, fb);

		}

		cout << endl << "Metoda Falsi (1) czy Bisekcja (2)?" << endl;
		int metoda;
		cin >> metoda;
		while (metoda != 1 && metoda != 2)
		{
			cout << "wybierz 1 albo 2 : "; cin >> metoda;
		}

		cout << endl << "Obliczyc miejsce 0 przez iteracje czy dokladnosc ?  dokladnosc 'a' /  iteracja 'b' " << endl;

		char  sposob = 'o';

		while (sposob != 'a' && sposob != 'b')
		{
			cin >> sposob;  cout << endl;
		}
		double e; int i;
		if (sposob == 'b')
		{
			cout << "Ile iteracji wykonac : "; cin >> i; cout << endl;
		}
		else
		{
			cout << "Podaj dokladnosc : "; cin >> e; cout << endl;
		}
		x0 = a;                     // przypisuje wstepna wartosc temu poszukiwanemu punktowi
		int iter = 0;   int*x = &iter;  // Dodatkowy iterator dunno po co ale moze sie przydac np. przy dokladnosci jakbys chcial extra info

		if (metoda == 2)
		{
			switch (sposob)
			{
			case 'a':

				x0 = bisd(a, b, x0, fun, *x, e);
				cout << "Poszukiwany punkt to z " << x0 << " wyznaczony z dokladnoscia do " << e << " .";

				break;
			case 'b':

				x0 = bisi(a, b, x0, fun, *x, i);
				cout << "Poszukiwany punkt to z " << x0 << " wyznaczony po  " << i << "  iteracjach.";

				break;
			}
			cout << endl << "Metoda Bisekcji" << endl;
		}
		else
		{
			switch (sposob)
			{
			case 'a':

				x0 = falsid(a, b, x0, fun, *x, e);
				cout << "Poszukiwany punkt to z " << x0 << " wyznaczony z dokladnoscia do " << setprecision(9) << e << " po " << *x << " iteracjach.";
				
				break;
			case 'b':

				x0 = falsii(a, b, x0, fun, *x, i);
				cout << "Poszukiwany punkt to z " << x0 << " wyznaczony po  " << *x << "  iteracjach.";

				break;
			}
			cout << endl << "Metoda Falsi" << endl;
		}

		// Rysowanie wykresu
		Plot drawing;
		drawing.SetRange(a, b);
		drawing.Draw(fun);
		


		cout << endl << "Czy zechcialbys powtorzyc ?  t/n" << endl;
		cin >> repeat;
		while (repeat != 't'&&repeat != 'n')
		{
			cout << "Znowu zle, jeszcze raz" << endl;
			cin >> repeat;
		}
	}


	return 0;
}
