#include <iostream>
using namespace std;

/**
* \brief Функция, высчитывающая общее сопротивление
* \param R1 - сопротивление 1 резистора
* \param R2 - сопротивление 2 резистора  
* \param R3 - сопротивление 3 резистора
* \return значение общего сопротивления
**/
double GetR(double R1, double R2, double R3);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
* */
int main() {
	double R1;
	cout << "Please enter resistance values R1: ";
	cin >> R1;
	double R2;
	cout << "Please enter resistance values R2: ";
	cin >> R2;
	double R3;
	cout << "Please enter resistance values R3: ";
	cin >> R3;
	double R;
	
	// Проверка на нули. Объясняется это тем, что если одно из сопротивлений равно 0, то программа считает, 
	// что общее сопротивление тоже равно 0 (получается деление на 0), но это не так. Наверное это можно оформить короче, но я еще
	// не знаю как
	if (R1 == 0) {
		if (R2 == 0 && R3 == 0) {
			R = 0;
			cout << "R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
		if (R2 == 0) {
			R = 1 / R3;
			cout << "R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
		if (R3 == 0) {
			R = 1 / R2;
			cout << "R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
		R = 1 / R2 + 1 / R3;
		cout << "R1 = " << R1 <<
			"\nR2 = " << R2 <<
			"\nR3 = " << R3 <<
			"\nR = " << R;
    return 0;
	}


	if (R2 == 0) {
		if (R3 == 0) {
			R = R1;
			cout<<"R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
	    R = 1 / R1 + 1 / R3;
		cout << "R1 = " << R1 <<
			"\nR2 = " << R2 <<
			"\nR3 = " << R3 <<
			"\nR = " << R;
		return 0;
	}
	
	
	if (R3 == 0) {
		R = 1 / R1 + 1 / R2;
		cout << "R1 = " << R1 <<
			"\nR2 = " << R2 <<
			"\nR3 = " << R3 <<
			"\nR = " << R;
		return 0;
	}



	R = GetR(R1, R2, R3);
    cout<<"R1 = " << R1 <<
		 "\nR2 = " << R2 <<
		 "\nR3 = " << R3 <<
		 "\nR = " << R;

	return 0;
}

double GetR(double R1, double R2, double R3) {
	return pow((1 / R1 + 1 / R2 + 1 / R3), -1);
}