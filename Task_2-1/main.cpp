#include <iostream>
using namespace std;

/**
* \brief ���� �������� ����� � �������� �� ������������ �����
* \return �������� ����
**/
int input_hour();

/**
* \brief ���� �������� ����� � �������� �� ������������ �����
* \return �������� �����
**/
int input_minutes();

/**
* \brief �����, ������� ��������� ���� ����� ������������ ���������� ����� � �����
* \param hour - ����
* \param minutes - ������
**/
void timesDay(int hour, int minutes);

/**
* \brief �����, ������������ ����� �����
* \param hour - ����
**/
void checkZero(int hour);

/**
* \brief ����� ����� � ���������
* \return ��� ������ (0-�����)
**/
int main() {
	int hour, minutes;
	hour = input_hour();
	minutes = input_minutes();
	timesDay(hour, minutes);
	checkZero(hour);
	return 0;
}

int input_hour() { 
	int hour;
	cout << "Please enter hour: ";
	cin >> hour;
	while (hour < 0 || hour > 23 || !cin || (cin.get() != '\n'))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error! The entered value is incorrect or does not correspond to the frames of the day (00:00-23:59)\nRe-enter the value: ";
		cin >> hour;
	}
	return hour;
}

int input_minutes() {
	int minutes;
	cout << "Please enter minutes: ";
	cin >> minutes;
	while (minutes < 0 || minutes > 59 || !cin || (cin.get() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error! Incorrect value or your number does not belong to [0; 59]. Re-enter the value: ";
		cin >> minutes;
	}
	return minutes;
}

void timesDay(int hour, int minutes) {
	if (hour < 10 && minutes < 10)
		cout << "Time 0" << hour << ":0" << minutes << "\n";

	if (hour < 10 && minutes > 10)
		cout << "Time 0" << hour << ":" << minutes << "\n";

	if (hour > 10 && minutes < 10)
		cout << "Time " << hour << ":0" << minutes << "\n";

	if (hour > 10 && minutes > 10)
		cout << "Time " << hour << ":" << minutes << "\n";
}

void checkZero(int hour) {
	if (hour >= 5 && hour <= 11)
		cout << "Good morning!";
	
	if (hour > 11 && hour <= 16)
		cout << "Good day!";
	
	if (hour > 16 && hour <= 23)
		cout << "Good evening!";
	
	if (hour >= 0 && hour < 5)
		cout << "Good night!";
}