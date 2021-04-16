#include <iostream>
using namespace std;

/**
* \brief Функция, высчитывающая значение y, если x > 1
* \param a - константа, имеющая тип double
* \param x - переменная, имеющая тип double
* \return значение y
**/
double GetY1(const double a, double x);

/**
* \brief Функция, высчитывающая значение y, если x <= 1
* \param a - константа, имеющая тип double
* \param x - переменная, имеющая тип double
* \return значение y
**/
double GetY2(const double a, double x);

/**
* \brief Функция, высчитывающая значение y, если x <= 1
* \param a - константа, имеющая тип double
* \param double x - переменная, имеющая тип double
* \return значение y
**/
double input();

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	const double a = 0.9;
	double x = input();
	double y;
	if (x > 1) {
		y = GetY1(a, x);
		cout << "Since x > 1, then y = " << y;
	}
	else  {
		y = GetY2(a, x);
		cout << "Since x <= 1, then y =  " << y;
	}
	return 0;
}

double GetY1(const double a, double x) {
	return a * log(x) + sqrt(abs(x));
}

double GetY2(const double a, double x) {
	return 2 * a * cos(x) + 3 * x * x;
}

double input() {
	double x;
	cout << "Please enter x: ";
	cin >> x;
	while (!cin || (cin.get() != '\n'))
	{
		cout << "Error! Please enter x: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> x;
	}
	return x;
}
