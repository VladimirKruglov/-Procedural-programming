#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Функция, рассчитывающая рекурентный член
* \param k Индекс члена ряда
* \return Значение рекурентного член
*/
double recurrent(const size_t k);

/**
* \brief Функция, рассчитывающая сумму первых n членов последовательности
* \param n Колличество членов последовательности
* \return Значение суммы
*/
double GetSum(const size_t n);

/**
* \brief Функция, рассчитывающая всех членов последовательности, не меньших заданного числа e
* \param eps Точность расчёта
* \return Значение суммы
*/
double GetSum2(const double EPS);

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Сумма первых n-членов\n" << "n = ";
    size_t n;
    cin >> n;

    cout << "Сумма = " << GetSum(n) << "\n\n";

    cout << "Сумма всех членов последовательности, не меньших заданного числа e\n" << "e = ";
    double eps;
    cin >> eps;

    cout << "Сумма = " << GetSum2(eps) << "\n";

    return 0;
}

double recurrent(const size_t k)
{
    return (-1.0) / (2 * k * (2 * k + 1));
}

double GetSum(const size_t n)
{
    double previous = 1, sum = previous, current;

    for (size_t k = 1; k < n; k++)
    {
        current = recurrent(k) * previous;
        sum += previous;
        previous = current;
    }

    return sum;
}

double GetSum2(const double EPS)
{
    double previous = 1, sum = previous, current;

    for (size_t k = 1; abs(previous) > EPS; k++)
    {
        current = recurrent(k) * previous;
        sum += current;
        previous = current;

    }

    return sum;
}