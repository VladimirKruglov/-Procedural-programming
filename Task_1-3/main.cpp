#include <iostream>
using namespace std;

/**
* \brief Функция, высчитывающая общее сопротивление
* \param R1 - сопротивление 1 резистора
* \param R2 - сопротивление 2 резистора  
* \param R3 - сопротивление 3 резистора
* \return значение общего сопротивления
**/
double GetInResistance(double R1, double R2, double R3);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
* */
int main() {
	cout << "Please enter resistance values R1: ";
	double R1;
	cin >> R1;
	cout << "Please enter resistance values R2: ";
	double R2;
	cin >> R2;
	cout << "Please enter resistance values R3: ";
	double R3;
	cin >> R3;
	double R = GetInResistance(R1, R2, R3);
    cout <<"R1 = " << R1 <<
		 "\nR2 = " << R2 <<
		 "\nR3 = " << R3 <<
		 "\nR = " << R;

	return 0;
}

double GetInResistance(double R1, double R2, double R3) {
	return pow((1 / R1 + 1 / R2 + 1 / R3), -1);
}