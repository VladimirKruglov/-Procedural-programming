#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

/**
* \brief ����� ��������� �������
**/
enum class Filling
{
	RANDOM = 1,
	USER = 2
};


/**
* \brief ���������� ������� ���������� �������
* \param array ������
* \param size ������ �������
* \param LOW_BOUND ���������� ��������� �����
* \param UP_BOUND ����������� ��������� �����
**/
void randomDigits(int* array, const size_t  size, const int LOW_BOUND, const int UP_BOUND);

/**
* \brief ���� ������� � ����������
* \param array ������
* \param size ������ �������
**/
void userInput(int* array, const size_t size);

/**
* \brief ����� �������
* \param array ������
* \param size ������ �������
**/
void Print(int* array, const size_t size);

/**
* \brief ����� ������������ ��������
* \param array ������
* \param size ������ �������
* \return min ����������� ������� �������
**/
int GetminValue(int* array, const size_t size);

/**
* \brief ����� ������� � ������� ������������ �������� �����
* \param array ������
* \param size ������ �������
**/
void PrintReplacement(int* array, const size_t size, const int min);

/**
* \brief �����, ������� �������� ������ � �� ��������� ������� D
* \param newarray ����� ������
* \param array ������ ������
* \param size ������ �������
**/
void newArray(const size_t size, int* newarray, int* array);

/**
* \brief �������� ��������� �������, ������ � ��������� ����� ������� ������
* \param array ������
* \param size ������ �������
**/
void RemoveEvenNumbers(int* array, const size_t size);

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int LOW_BOUND = -40, UP_BOUND = 40;

	cout << "������� ���������� ��������� �������: ";
	int* array;
	int size;
	cin >> size;

	array = new int[size];
	cout << "1 - ������������� ������\n2 - ��������� ������ �������\n1 ��� 2: ";
	int choice;
	cin >> choice;

	const auto filling = static_cast<Filling>(choice);
	switch (filling)
	{
	case Filling::RANDOM:
		randomDigits(array, size, LOW_BOUND, UP_BOUND);
		Print(array, size);
		break;
	case Filling::USER:
		userInput(array, size);
		Print(array, size);
		break;
	default:
		cout << "������! �� ������ �� ���� �� ���������";
	}

	cout << "�������� �� ������� ���� �����, ������ � ��������� ����� ������� ������ �����:\n";
	RemoveEvenNumbers(array, size);

	cout << "����������� �� ������ ������� �������: ";
	int min = GetminValue(array, size);
	cout << min << "\n";

	cout << "������ ������������ �� ������ �������� �����:\n";
	PrintReplacement(array, size, min);

	cout << "������ � �������������� �� ������� D ��� �� �����������:\n";
	int* newarray;
	newarray = new int[size];
	newArray(size, newarray, array);
	Print(newarray, size);

	return 0;
}

void randomDigits(int* array, const size_t  size, const int LOW_BOUND, const int UP_BOUND) 
{
	for (size_t i = 0; i < size; i++) 
	{
		array[i] = rand() % (2 * UP_BOUND + 1) + LOW_BOUND;
	}
}

void userInput(int* array, const size_t size) 
{
	for (size_t i = 0; i < size; i++) 
	{
		cout << "arr[" << i << "] = ";
		cin >> array[i];
	}
}

void Print(int* array, const size_t size) 
{
	cout << "array[" << size << "]" << "= {";
	for (size_t i = 0; i < size; i++) 
	{
		cout << array[i] << ";" << setw(3);
	}
	cout << "}\n\n";
}

int GetminValue(int* array, const size_t size)
{
	int min = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (abs(array[i]) <= abs(min))
			min = array[i];
	}
	return min;
}

int GetminValue(int* array, const int size)
{
	return 0;
}

void PrintReplacement(int* array, const size_t size, const int min)
{
	cout << "array[" << size << "]" << "= {";
	for (size_t i = 0; i < size; i++)
	{
		if (abs(array[i]) == abs(min))
			array[i] = 0;

		cout << array[i] << ";" << setw(3);
	}
	cout <<"}\n\n";
}

void newArray(const size_t size, int* newarray, int* array) 
{
	for (size_t i = 0; i < size; i++)
	{
		if (i >= 3 && i <= 12 )
			newarray[i] = -array[i] * array[i];
		else
			newarray[i] = array[i] - 1;
	}
}

void RemoveEvenNumbers(int* array, const size_t size) {
	int x, newsize = 0;
	for (size_t i = 0; i < size; i++)
		if (array[i] % 2 == 0)
		{
			x = array[i] / 10;
			if (x % 2 != 0)
			{
				array[newsize++] = array[i];
			}
			for (size_t i = 0; i < newsize; i++)
				cout << array[i] << ";";
			cout << "}\n\n";
		}
}