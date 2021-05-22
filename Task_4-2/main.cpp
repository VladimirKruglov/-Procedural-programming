#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

/**
* \brief Выбор заполнеия массива
**/
enum class Filling
{
	RANDOM = 1,
	USER = 2
};


/**
* \brief Заполнение массива случайными числами
* \param array Массив
* \param size Размер массива
* \param LOW_BOUND Минимально возможное число
* \param UP_BOUND Максимально возможное число
**/
void randomDigits(int* array, const size_t  size, const int LOW_BOUND, const int UP_BOUND);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void userInput(int* array, const size_t size);

/**
* \brief Вывод массива
* \param array Массив
* \param size Размер массива
**/
void Print(int* array, const size_t size);

/**
* \brief Поиск минимального элемента
* \param array Массив
* \param size Размер массива
* \return min Минимальный элемент массива
**/
int GetminValue(int* array, const size_t size);

/**
* \brief Вывод массива с заменой минимального элемента нулем
* \param array Массив
* \param size Размер массива
**/
void PrintReplacement(int* array, const size_t size, const int min);

/**
* \brief Метод, который формирут массив А из элементов массива D
* \param newarray Новый массив
* \param array Старый массив
* \param size Размер массива
**/
void newArray(const size_t size, int* newarray, int* array);

/**
* \brief Удаление элементов массива, первая и последняя цифра которых четная
* \param array Массив
* \param size Размер массива
**/
void RemoveEvenNumbers(int* array, const size_t size);

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int LOW_BOUND = -40, UP_BOUND = 40;

	cout << "Введите количество элементов массива: ";
	int* array;
	int size;
	cin >> size;

	array = new int[size];
	cout << "1 - Сгенерировать массив\n2 - Заполнить массив вручную\n1 или 2: ";
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
		cout << "Ошибка! Не выбран ни один из вариантов";
	}

	cout << "Удаление из массива всех чисел, первая и последняя цифра которых четные числа:\n";
	RemoveEvenNumbers(array, size);

	cout << "Минимальный по модулю элемент массива: ";
	int min = GetminValue(array, size);
	cout << min << "\n";

	cout << "Замена минимального по модулю элемента нулем:\n";
	PrintReplacement(array, size, min);

	cout << "Массив А сформированный из массива D той же размерности:\n";
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