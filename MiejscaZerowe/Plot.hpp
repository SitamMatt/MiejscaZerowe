#include "gnuplot_i.hpp"
#include <string>
#include <numeric>
using namespace std;
class Plot : public Gnuplot{
public:
	double a;
	double b;
	double a_b_distance;
	void Draw(std::function<double(double)> fun) {

		vector<double> x;
		vector<double> y;
		double offset = 3 * a_b_distance / 1000;

		for (double i = a-a_b_distance; i < b+a_b_distance; i += offset) {
			x.push_back(i);
			double value = fun(i);
			y.push_back(value);
		}

		double average = accumulate(y.begin(), y.end(), 0.00) / y.size() / 1000;

		set_grid();
		set_style("lines");
		set_pointsize(0.5);
		cmd("set xzeroaxis linetype 11 linewidth 3");
		cmd("set yzeroaxis linetype 11 linewidth 3");
		set_xlabel("OX");
		set_ylabel("OY");
		set_title("Wykres");

		plot_xy(x, y, "f(x)");
	};
	void SetRange(double ap, double bp) {
		double right = ap > bp ? ap : bp;
		double left = ap < bp ? ap : bp;
		a_b_distance = abs(ap) + abs(bp);
		set_xrange(left-a_b_distance, right+a_b_distance);
		set_yrange(left - a_b_distance, right + a_b_distance);
		a = left;
		b = right;
	};

	void Root(double x0, double y0)
	{
		vector<double> a;
		vector<double> b;
		a.push_back(x0);
		b.push_back(y0);
		set_style("points");
		set_pointsize(3.0);
		plot_xy(a, b, "Pierwiastek");
	}

};

