#include <iostream>
using namespace std;

/**
* \brief Метод, переводящий байты в мегабайты
* \param byte - число байт
* \return количество мегабайт в числе байт
**/
double Getm(double byte){
	const int a = pow(10, 6);
	return byte / a;
}

/**
* \brief Метод, переводящий байты в гигабайты
* \param byte - число байт
* \return количество гигабайт в числе байт
**/
double Getg(double byte){
	const int b = pow(10, 9);
	return byte / b;
}

/**
* \brief Метод, позволяющий ввести количество байт и проверяющий правильность ввода
* \return правильное значение ввода количества байт
**/
double input() {
	double byte;
	cout << "Please enter number of bytes: ";
	cin >> byte;
	while (!cin || cin.get() != '\n') {
		cout << "Wrong input! Please enter your number again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> byte;
	}
	return byte;
}
	
/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
**/
int main(){
	double byte = input();
	double mega = Getm(byte), giga = Getg(byte);
	cout << byte << " byte = " << mega << " megabyte\n" 
		 << byte << " byte = " << giga << " gigabyte";
	return 0;
}