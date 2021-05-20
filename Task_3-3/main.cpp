#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Расчет функции e в степени 2x
 * \param x Показатель степени
 * \return Значение e в степени 2x
 */
double GetEPower2X(const double x);

/**
 * \brief Вычисление рекуррентного члена ряда
 * \param x Параметр функции, аппроксимируемой рядом
 * \param index Индекс члена ряда
 * \return Значение рекуррентного члена
 */
double recurrent(const double x, const int index);

/**
 * \brief Вычисление суммы ряда от x с заданной точностью
 * \param x Показатель степени.
 * \param eps Погрешность вычислений
 * \return sum Значение суммы ряда
 */
double GetSum(const double x, const double eps);

/**
 * \brief Вывод результата
 * \param argument Аргумент табулируемой функции
 * \param function Значение табулируемой функции
 * \param series Аппроксимация табулируемой функции
 */
void Print(const double argument, const double function, const double sum);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0-успех).
 */
int main()
{
    setlocale(LC_ALL, "ru");
    const auto LOW_BOUND = 0.1, UP_BOUND = 1.0, EPS = pow(20, (-4)), STEP = 0.1;

    auto x = LOW_BOUND;
    while (x <= UP_BOUND + EPS)
    {
        const auto function = GetEPower2X(x);
        const auto sum = GetSum(x, EPS);

        Print(x, function, sum);

        x += STEP;
    }

    return 0;
}

double GetEPower2X(const double x)
{
    return exp(2 * x);
}

double recurrent(const double x, const int index)
{
    return 2 * index * x;
}

double GetSum(const double x, const double eps)
{
    double previous = x, sum = previous, current;

    for (size_t n = 0; abs(previous) > eps; n++)
    {
        current = recurrent(x, n) * previous;
        previous = current;
        sum += previous;
    }

    return sum;
}



void Print(const double argument, const double function, const double sum)
{
    cout<< "X" << setw(10) << argument << " | "
        << "Значение функции" << setw(15) << function << " | "
        << "Значение суммы ряда" << setw(15) << sum << "\n";
}