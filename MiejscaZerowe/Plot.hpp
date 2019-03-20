#include "gnuplot_i.hpp"
#include <string>
#include <numeric>
using namespace std;
class Plot : public Gnuplot{
public:
	double a;
	double b;
	double a_b_distance;
	void Draw(double(*fun)(double)) {

		vector<double> x;
		vector<double> y;
		double offset = 3 * a_b_distance / 1000;

		for (double i = a-a_b_distance; i < b+a_b_distance; i += offset) {
			x.push_back(i);
			double value = fun(i);
			y.push_back(value);
		}

		double average = accumulate(y.begin(), y.end(), 0.00) / y.size();

		set_yrange(-1 * abs(average/4), average/4);
		set_grid();
		set_style("linespoints");
		set_pointsize(0.5);
		cmd("set xzeroaxis linetype 11 linewidth 5");
		cmd("set yzeroaxis linetype 11 linewidth 5");
		plot_xy(x, y, "podpis - opcjonalnie");
	};
	//Plot() {
	//	main_plot.set_title("wykres");
	//	main_plot.set_xlabel("oœ x");//
	//	main_plot.set_ylabel("oœ y");//
	//	main_plot.set_style("lines");//
	//	main_plot.set_grid();
	//}
	void SetRange(double ap, double bp) {
		double right = ap > bp ? ap : bp;
		double left = ap < bp ? ap : bp;
		a_b_distance = abs(ap) + abs(bp);
		set_xrange(left-a_b_distance, right+a_b_distance);
		set_yrange(0, 20);//
		a = left;
		b = right;
	};
};