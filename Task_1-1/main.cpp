#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

/**
* \brief Метод, считающий const auto a
* \param const double x - константа, имеющая тип данных с плавающей запятой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей запятой двойной точности 
* \param const double z - константа, имеющая тип данных с плавающей запятой двойной точности 
* \return значение const auto a
**/
double GetA(const double x, const double y, const double z) {
	return cbrt((x * y * z) + abs(z * sin(y))) ;
}

/**
* \brief Метод, считающий const auto b
* \param const double x - константа, имеющая тип данных с плавающей запятой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей запятой двойной точности 
* \param const double z - константа, имеющая тип данных с плавающей запятой двойной точности 
* \return значение const auto b
**/
double GetB(const double x, const double y, const double z) {
	return y * cos(x * z * sin(y)) + 3;
}

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
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
