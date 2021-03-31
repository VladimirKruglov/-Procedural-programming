#include <iostream>
#include <cmath>
#define USE_MATH_DEFINER
using namespace std;

double GetA(const double x, const double y, const double z) {
	return pow(abs(x * y * z + abs(z * sin(y))),1.0/3);
}
double GetB(const double x, const double y, const double z) {
	return y * cos(x * z * sin(y)) + 3;
}


int main() {
	const double x = 2.0;
	const double y = -1.0;
	const double z = 0.7;
	const auto a = -GetA(x, y, z);
	const auto b = GetB(x, y, z);
	cout << "x = " << x << endl
		<< "y = " << y << endl
		<< "z = " << z << endl
		<< "a = " << a << endl
		<< "b = " << b << endl;
	return 0;
}