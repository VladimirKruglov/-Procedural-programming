#include <iostream>
using namespace std;

/**
* \brief Метод, считающий общее сопротивление
* \param R1 - сопротивление 1 резистора, R2- сопротивление 2 резистора,  R3- сопротивление 3 резистора
* \return значение общего сопротивления
**/
double GetR(double R1, double R2, double R3) {
	return pow((1 / R1 + 1 / R2 + 1 / R3),-1);
}

/**
*\brief Точка входа в программу
* \return Код ошибки (0-успех)
* */
int main() {
	double R1, R2, R3, R;
	cout << "Please enter resistance values R1: ";
	cin >> R1;
	
	// Как запихнуть все это в одну функцию, чтобы использовать 3 раза?
	while (!cin || cin.get() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error! Please enter resistance values: ";
		cin >> R1;
	}

	cout << "Please enter resistance values R2: ";
	cin >> R2;
	while (!cin || cin.get() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error! Please enter resistance values: ";
		cin >> R2;
	}
	cout << "Please enter resistance values R3: ";
	cin >> R3;
	while (!cin || cin.get() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error! Please enter resistance values: ";
		cin >> R3;
	}
	
	// Проверка на нули. Объясняется это тем, что если одно из сопротивлений равно 0, то программа считает, 
	// что общее сопротивление тоже равно 0 (получается деление на 0), но это не так. Наверное это можно оформить короче, но я еще
	// не знаю как
	if (R1 == 0) {
		if (R1 == 0 && R2 == 0 && R3 == 0) {
			R = 0;
			cout << "R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
		if (R1 == 0 && R2 == 0) {
			R = 1 / R3;
			cout << "R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
		if (R1 == 0 && R3 == 0) {
			R = 1 / R2;
			cout << "R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
		else R = 1 / R2 + 1 / R3;
		cout << "R1 = " << R1 <<
			"\nR2 = " << R2 <<
			"\nR3 = " << R3 <<
			"\nR = " << R;
    return 0;
	}


	if (R2 == 0) {
	    R = 1 / R1 + 1 / R3;
		cout << "R1 = " << R1 <<
			"\nR2 = " << R2 <<
			"\nR3 = " << R3 <<
			"\nR = " << R;
		return 0;
	}
	
	
	if (R3 == 0) {
		if (R1 == 0 && R2 == 0 && R3 == 0) {
			R = 0;
			cout << "R1 = " << R1 <<
				"\nR2 = " << R2 <<
				"\nR3 = " << R3 <<
				"\nR = " << R;
			return 0;
		}
		else R = 1 / R1 + 1 / R2;
		cout << "R1 = " << R1 <<
			"\nR2 = " << R2 <<
			"\nR3 = " << R3 <<
			"\nR = " << R;
		return 0;
	}



	R = GetR(R1, R2, R3);
    cout<< "R1 = " << R1 <<
		 "\nR2 = " << R2 <<
		 "\nR3 = " << R3 <<
		 "\nR = " << R;

	return 0;
}
