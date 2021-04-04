#include <iostream>
#define USE_MATH_DEFINER
#include <cmath>
using namespace std;

double GetA(const double x, const double y, const double z) {
	return cbrt((x * y * z) + abs(z * sin(y))) ;
}
double GetB(const double x, const double y, const double z) {
	return y * cos(x * z * sin(y)) + 3;
}


int main() {
	const double x = 2.0;
	const double y = 0.7;
	const double z = -1.0;
	const auto a = GetA(x, y, z);
	const auto b = GetB(x, y, z);
	cout<< "x = " << x 
		<< "\ny = " << y 
		<< "\nz = " << z 
		<< "\na = " << a 
		<< "\nb = " << b;
	return 0;
}
