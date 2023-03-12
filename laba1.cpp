#include <iostream>
#include <iomanip>
using namespace std;
const double eps = 0.001;

int main() {
	setlocale(LC_ALL, "Ru");
	// fac - знаменатель , s - сумма ряда, n - кол-во членов внутреннего ряда, k - кол-во членов внешнего ряда 
	int fac, n, k;
	//zn - член ряда чисел
	double zn, s;
	fac = 1; s = 0;
	for (k = 1;k < 10; k++)
	{
		s = 0;
		for (n = 1;n < k; n++)
			s = s + sin(n * k);
		fac *=k;
		zn = s / fac;
		s = s + zn;
	}
	cout <<"Числовой ряд = " << s;
}

/*
double absolute(double x)
{
	return x < 0 ? -x : x;
}
double F(double x)
{
	//w - предыдущий член, v  - последующий, u - отдельные члены разложения, sum - сумма ряда
	double n = 1, u = -x * x, v = 1, w = x + n, sum = x;
	while (absolute(v - w) > eps) {
		n += 2.;
		w = v;
		v *= u / (n * (n - 1.));
		sum += v;
	} return sum;
}*/
/*
int main()
{
	double x; cout << setprecision(15) << fixed;
	while (true) {
		cout << "x: "; cin >> x;
		cout << setw(18) << F(x) << endl;
	}
}
*/


