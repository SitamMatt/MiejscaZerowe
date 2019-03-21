#ifndef POMOC_H
#define POMOC_H
using namespace std;
void menu();
double funOne(double x);
double fun2(double x);
double fun3(double x);
double fun4(double x);
double check (double value1, double value2);
double funf(double option,double mid,int opcja);
double falsii(double point1, double point2, double mid, double(*funkcja)(double), int &iter,int i);
double falsid(double point1, double point2, double mid, double(*funkcja)(double), int&iter,double  e);
double bisd(double point1, double point2, double mid, double(*funkcja)(double), int&iter, double  e);
double bisi(double point1, double point2, double mid, double(*funkcja)(double), int&iter,int  i);
#endif // POMOC_H

/* Koncowki i / d okreslaja czy jest to iteracja czy dokladnosc
    funf jest to funkcja do metody Falsi
    fun1 oblicza wartosc podanej przy pomocy zmiennej opcja funkcji w zadanym miejscu
    check sprawdza czy punkty na fukncji leca po przeciwnej stronie osi OX

*/
