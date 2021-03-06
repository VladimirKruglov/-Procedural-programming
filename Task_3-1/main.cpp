#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
* \brief Расчёт функции
* \param x - аргумент функции
* \return значение функции
**/
double calcFunction(const double x);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main()
{
	const double LOW_BOUND = 1, UP_BOUND = 2, STEP = 0.1, WIDTH = 3;
	
	cout << setw(WIDTH) << "X" << " | " << setw(WIDTH) << "Y\n";

	for (double x = LOW_BOUND; x < UP_BOUND; x += STEP)
	{
		cout << setw(WIDTH) << x << " | " << setw(WIDTH) << calcFunction(x) << "\n";
	}

	return 0;
}

double calcFunction(const double x)
{
	return 0.1*x*x - x*log(x);
}

