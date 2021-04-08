#include <iostream>
using namespace std;

/**
* \brief �����, ����������� ����� � ���������
* \param byte - ����� ����
* \return ���������� �������� � ����� ����
**/
double Getm(double byte){
	const int a = pow(10, 6);
	return byte / a;
}

/**
* \brief �����, ����������� ����� � ���������
* \param byte - ����� ����
* \return ���������� �������� � ����� ����
**/
double Getg(double x){
	const int b = pow(10, 9);
	return x / b;
}

/**
* \brief �����, ����������� ������ � ����������� ������������ �����
* \return ���������� �������� �����
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
 * \brief ����� ����� � ���������.
 * \return ��� ������ (0 - �����).
**/
int main(){
	double num = input();
	double mega = Getm(num), giga = Getg(num);
	cout << num << " byte = " << mega << " megabyte\n" 
		 << num << " byte = " << giga << " gigabyte";
	return 0;
}