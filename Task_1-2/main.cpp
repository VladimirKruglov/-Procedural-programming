#include <iostream>
using namespace std;

/**
* \brief Метод, переводящий байты в мегабайты
* \param byte - число байт
* \return количество мегабайт в числе байт
**/
double GetInMegabytes(double byte);

/**
* \brief Метод, переводящий байты в гигабайты
* \param byte - число байт
* \return количество гигабайт в числе байт
**/
double GetInGigabytes(double byte);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
**/
int main(){
	double byte;
	cout << "Please enter number of bytes: ";
	cin >> byte;
	double mega = GetInMegabytes(byte), giga = GetInGigabytes(byte);
	cout << byte << " byte = " << mega << " megabyte\n" 
		 << byte << " byte = " << giga << " gigabyte";
	return 0;
}

double GetInMegabytes(double byte) {
	const int BASED_ON_POWERS = 10, MEGA = 6;
	const int a = pow(BASED_ON_POWERS, MEGA);
	return byte / a;
}

double GetInGigabytes(double byte) {
	const int BASED_ON_POWERS = 10, GIGA = 9;
	const int b = pow(BASED_ON_POWERS, GIGA);
	return byte / b;
}
