#include <iostream>
using namespace std;

/**
* \brief Метод, переводящий байты в мегабайты
* \param byte - число байт
* \return количество мегабайт в числе байт
**/
const double GetInMegabytes(double byte);

/**
* \brief Метод, переводящий байты в гигабайты
* \param byte - число байт
* \return количество гигабайт в числе байт
**/
const double GetInGigabytes(double byte);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
**/
int main(){
	double byte;
	cout << "Please enter number of bytes: ";
	cin >> byte;
	const auto megabytes = GetInMegabytes(byte);
	const auto gigabytes = GetInGigabytes(byte);
	cout << byte << " byte = " << megabytes << " megabyte\n" 
		 << byte << " byte = " << gigabytes << " gigabyte";
	return 0;
}

const double GetInMegabytes(double byte) {
	const int BASED_ON_POWERS = 10, MEGA = 6;
	const auto factor = pow(BASED_ON_POWERS, MEGA);
	return byte / factor;
}

const double GetInGigabytes(double byte) {
	const int BASED_ON_POWERS = 10, GIGA = 9;
	const auto factor = pow(BASED_ON_POWERS, GIGA);
	return byte / factor;
}
