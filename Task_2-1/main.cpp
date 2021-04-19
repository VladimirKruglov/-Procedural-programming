#include <iostream>
#include <Windows.h>
using namespace std;

/**
* \brief Функция, высчитывающая объем параллелепипеда
* \param lentgh - длина стороны параллелепипеда
* \param width - ширина стороны параллелепипеда
* \param height - высота стороны параллелепипеда
* \return значение объема
**/
double calcVolume(double lentgh, double width, double height);

/**
* \brief Функция, высчитывающая площадь поверхности параллелепипеда
* \param lentgh - длина стороны параллелепипеда
* \param width - ширина стороны параллелепипеда
* \param height - высота стороны параллелепипеда
* \return значение площади поверхности
**/
double calcSquare(double lentgh, double width, double height);


/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "Дан параллепипед"
		 << "\nВведите значение длины: ";
	double lentgh;
	cin >> lentgh;
	cout << "Введите значение ширины: ";
	double width;
	cin >> width;
	cout << "Введите значение высоты: ";
	double height;
	cin >> height;
	cout << "Введите 1 - для расчета объема параллепипеда\n"
		<< "        2 - для расчета площади поверхности\n";
	double volume = calcVolume(lentgh,width,height);
	double square = calcSquare(lentgh,width,height);
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout<< "Длина = " << lentgh
			<< "\nШирина = " << width
			<< "\nВысота = " << height
			<< "\nОбъем = " << volume;
		break;
	case 2:
		cout<< "Длина = " << lentgh
			<< "\nШирина = " << width
			<< "\nВысота = " << height
			<< "\nПлощадь поверхности = " << square;
		break;
	default:
		cout << "По-русски же написал выбрать 1 или 2";
		break;
	}
	return 0;
}

double calcVolume(double lentgh, double width, double height) {
	return lentgh * width * height;
}

double calcSquare(double lentgh, double width, double height) {
	return 2 * (lentgh * width + lentgh * height + width * height);
}