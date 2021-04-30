#include <iostream>
#include <Windows.h>
using namespace std;

/**
* \brief Функция, расчитывающая значение y, если x > 1
* \param a - константа, имеющая тип double
* \param x - переменная, имеющая тип double
* \return значение y
**/
double GetY1(const double a, double x);

/**
* \brief Функция, расчитывающая значение y, если x <= 1
* \param a - константа, имеющая тип double
* \param x - переменная, имеющая тип double
* \return значение y
**/
double GetY2(const double a, double x);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const double a = 0.9;
	double x;
	cout << "Введите значение x: ";
	cin >> x;
	double y;
	if (x > 1) {
		y = GetY1(a, x);
		cout << "Так как x > 1, то y = " << y;
	}
	else  {
		y = GetY2(a, x);
		cout << "Так как x <= 1, то y =  " << y;
	}
	return 0;
}

double GetY1(const double a, double x) {
	return a * log(x) + sqrt(abs(x));
}

double GetY2(const double a, double x) {
	return 2 * a * cos(x) + 3 * x * x;
}

