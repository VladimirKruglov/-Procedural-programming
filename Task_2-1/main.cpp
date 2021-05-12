#include <iostream>
#include <string>
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
* \param height - высота стороны параллелепипеда/**
* \return значение площади поверхности
**/
double GetSquare(double lentgh, double width, double height);

/**
* \brief Перечислимый тип чисел, с помощью которого можно посчитать объем или площадь
*/
enum class Choice
{
	/**
	* \brief Выбор пользователя - объем
	*/
	VOLUME = 1,

	/**
	* \brief Выбор пользователя - площадь поверхности
	*/
	SQARE = 2 
};

/**
* \brief
* \param message
* \return
*/
Choice ReadUserChoice(const string & message = "");

/**
* \brief Точка входа в программу.
* \return Код ошибки, если 0 - успешное выполнение.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	const auto message = "Дан параллепипед\nВыберите, что нужно посчитать:\n"
		+ to_string(static_cast<int>(Choice::VOLUME)) + " - Объем параллелепипеда\n"
		+ to_string(static_cast<int>(Choice::SQARE)) + " - Площадь поверхности параллелепипеда\n";
	
	const auto number = ReadUserChoice(message);

	switch (number)
	{
	case Choice::VOLUME:
	{
		cout << "Введите значение длины: ";
		double lentgh;
		cin >> lentgh;
		cout << "Введите значение ширины: ";
		double width;
		cin >> width;
		cout << "Введите значение высоты: ";
		double height;
		cin >> height;
		cout << "Объем = " << GetVolume(lentgh, width, height);
		break;
	}
	case Choice::SQARE:
	{
		cout << "Введите значение длины: ";
		double lentgh;
		cin >> lentgh;
		cout << "Введите значение ширины: ";
		double width;
		cin >> width;
		cout << "Введите значение высоты: ";
		double height;
		cin >> height;
		cout << "Площадь поверхности = " << GetSquare(lentgh, width, height);
		break;
	}
	default:
		cout << "Ошибка!";
	}
	return 0;
}

Choice ReadUserChoice(const string& message)
{
	cout << message;
	int userInput;
	cin >> userInput;
	return static_cast<Choice>(userInput);
}

double GetVolume(double lentgh, double width, double height) {
	return lentgh * width * height;
}

double GetSquare(double lentgh, double width, double height) {
	return 2 * (lentgh * width + lentgh * height + width * height);
}