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
double Getg(double x){
	const int b = pow(10, 9);
	return x / b;
}

/**
* \brief Метод, позволяющий ввести и проверяющий правильность ввода
* \return правильное значение ввода
**/
double input() {
	double x;
	cout << "Please enter number of bytes: ";
	cin >> x;
	while (!cin || cin.get() != '\n') {
		cout << "Wrong input! Please enter your number again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> x;
	}
	return x;
}
	
/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
**/
int main(){
	double num = input();
	double mega = Getm(num), giga = Getg(num);
	cout << num << " byte = " << mega << " megabyte\n" 
		 << num << " byte = " << giga << " gigabyte";
	return 0;
}