#include <iostream>
using namespace std;

/**
* \brief Метод, переводящий байты в мегабайты
* \param byte - число байт
* \return количество мегабайт в числе байт
**/
double Getm(double byte);

/**
* \brief Метод, переводящий байты в гигабайты
* \param byte - число байт
* \return количество гигабайт в числе байт
**/
double Getg(double byte);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
**/
int main(){
	double byte;
	cout << "Please enter number of bytes: ";
	cin >> byte;
	double mega = Getm(byte), giga = Getg(byte);
	cout << byte << " byte = " << mega << " megabyte\n" 
		 << byte << " byte = " << giga << " gigabyte";
	return 0;
}

double Getm(double byte) {
	const int a = pow(10, 6);
	return byte / a;
}

double Getg(double byte) {
	const int b = pow(10, 9);
	return byte / b;
}
