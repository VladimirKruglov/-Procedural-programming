#include <iostream>
#include <Windows.h>
using namespace std;

class Time {
public:
	int hour;
	int minutes;
};

/**
* \brief Метод, выводящий время
* \param time - время
**/
void Print(Time time);

/**
* \brief Метод, определяющий время суток
* \param time - время 
**/
void TimesDay(Time time);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Time time;
	cout << "Введите значение часа: ";
	cin >> time.hour;
	cout << "Введите значение минут: ";
	cin >> time.minutes;
	Print(time);
	TimesDay(time);
	return 0;
}

void Print(Time time) {
	if (time.hour < 10 && time.minutes < 10)
		cout << "Time 0" << time.hour << ":0" << time.minutes << "\n";
	if (time.hour < 10 && time.minutes > 10)
		cout << "Time 0" << time.hour << ":" << time.minutes << "\n";
	if (time.hour > 10 && time.minutes < 10)
		cout << "Time " << time.hour << ":0" << time.minutes << "\n";
	if (time.hour > 10 && time.minutes > 10)
		cout << "Time " << time.hour << ":" << time.minutes << "\n";
}

void TimesDay(Time time) {
	if (time.hour >= 5 && time.hour <= 11)
		cout << "Good morning!";

	if (time.hour > 11 && time.hour <= 16)
		cout << "Good day!";

	if (time.hour > 16 && time.hour <= 23)
		cout << "Good evening!";

	if (time.hour >= 0 && time.hour < 5)
		cout << "Good night!";
}