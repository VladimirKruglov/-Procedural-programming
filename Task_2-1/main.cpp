#include <iostream>
#include <string>
using namespace std;

/**
* \brief �������, ������������� ����� ���������������
* \param lentgh - ����� ������� ���������������
* \param width - ������ ������� ���������������
* \param height - ������ ������� ���������������
* \return �������� ������
**/
double GetVolume(double lentgh, double width, double height);

/**
* \brief �������, ������������� ������� ����������� ���������������
* \param lentgh - ����� ������� ���������������
* \param width - ������ ������� ���������������
* \param height - ������ ������� ���������������/**
* \return �������� ������� �����������
**/
double GetSquare(double lentgh, double width, double height);

/**
* \brief ������������ ��� �����, � ������� �������� ����� ��������� ����� ��� �������
*/
enum class Choice
{
	/**
	* \brief ����� ������������ - �����
	*/
	VOLUME = 1,

	/**
	* \brief ����� ������������ - ������� �����������
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
* \brief ����� ����� � ���������.
* \return ��� ������, ���� 0 - �������� ����������.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	const auto message = "��� ������������\n��������, ��� ����� ���������:\n"
		+ to_string(static_cast<int>(Choice::VOLUME)) + " - ����� ���������������\n"
		+ to_string(static_cast<int>(Choice::SQARE)) + " - ������� ����������� ���������������\n";
	
	const auto number = ReadUserChoice(message);

	switch (number)
	{
	case Choice::VOLUME:
	{
		cout << "������� �������� �����: ";
		double lentgh;
		cin >> lentgh;
		cout << "������� �������� ������: ";
		double width;
		cin >> width;
		cout << "������� �������� ������: ";
		double height;
		cin >> height;
		cout << "����� = " << GetVolume(lentgh, width, height);
		break;
	}
	case Choice::SQARE:
	{
		cout << "������� �������� �����: ";
		double lentgh;
		cin >> lentgh;
		cout << "������� �������� ������: ";
		double width;
		cin >> width;
		cout << "������� �������� ������: ";
		double height;
		cin >> height;
		cout << "������� ����������� = " << GetSquare(lentgh, width, height);
		break;
	}
	default:
		cout << "������!";
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