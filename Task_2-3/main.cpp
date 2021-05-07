#include <iostream>
using namespace std;

/**
* \brief Метод, определяющий время суток
* \param hour - часы
**/
void TimesDay(int hour);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	cout << "Enter the hour: ";
	int hour;
	cin >> hour;
	cout << "Enter the minutes: ";
	int minutes;
	cin >> minutes;
	TimesDay(hour);
	return 0;
}

void TimesDay(int hour) {
	const int LowLimitMorning = 5;
	const int UpLimitMorning = 11;
	const int UpLimitDay = 16;
	const int UpLimitEvening = 23;
	const int LowLimitNight = 0;
	if (hour >= LowLimitMorning && hour <= UpLimitMorning)
		cout << "Good morning!";

	if (hour > UpLimitMorning && hour <= UpLimitDay)
		cout << "Good day!";

	if (hour > UpLimitDay && hour <= UpLimitEvening)
		cout << "Good evening!";

	if (hour >= LowLimitNight && hour < LowLimitMorning)
		cout << "Good night!";
}