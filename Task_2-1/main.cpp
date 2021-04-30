#include <iostream>
#include <Windows.h>
using namespace std;

/**
* \brief Функция, расчитывающая объем параллелепипеда
* \param lentgh - длина стороны параллелепипеда
* \param width - ширина стороны параллелепипеда
* \param height - высота стороны параллелепипеда
* \return значение объема
**/
double GetVolume(double lentgh, double width, double height);

/**
* \brief Функция, расчитывающая площадь поверхности параллелепипеда
* \param lentgh - длина стороны параллелепипеда
* \param width - ширина стороны параллелепипеда
* \param height - высота стороны параллелепипеда
* \return значение площади поверхности
**/
double GetSquare(double lentgh, double width, double height);

enum Choice {
	VOLUME,
	SQARE
};
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
	cout << "Введите 0 - для расчета объема параллепипеда\n"
		<< "          1 - для расчета площади поверхности\n";
	double volume = GetVolume(lentgh, width, height);
	double square = GetSquare(lentgh, width, height);
	int YourChoice;
	cin >> YourChoice;
	switch (YourChoice)
	{
	case VOLUME:
		cout << "Объем = " << volume;
		break;
	case SQARE:
		cout << "Площадь поверхности = " << square;
		break;
	default:
		cout << "По-русски же написал выбрать 1 или 2";
		break;
	}
	return 0;
}

double GetVolume(double lentgh, double width, double height) {
	return lentgh * width * height;
}

double GetSquare(double lentgh, double width, double height) {
	return 2 * (lentgh * width + lentgh * height + width * height);
}
