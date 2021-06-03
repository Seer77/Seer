#include <iostream> //Проверочные выводы и вариации помечаю и вывожу(что бы соответствовало в задании при запуске), если мешают могу удалять
#include <stdlib.h>

using namespace std;
const string TRUE = "true";
const string FOLSE = "folse";


void task1()
{
    int Number1, Number2;
    cout << "Введите, целое число (от 0 до 20) 1:";
    cin >> Number1;
    cout << "Введите, целое число (от 0 до 20) 2:";
    cin >> Number2;
    cout << "Проверка: "<< Number1 + Number2 << endl;
    if (10 < (Number1 + Number2) && (Number1 + Number2) <= 20)
    {
        cout <<"Задание 1 вывод: " << TRUE << endl << endl;
    }
    else
    {
        cout << "Задание 1: " << FOLSE << endl << endl;
    }
};

void task2()
{
    int Number1;
    int Number2;
    cout << "Enter number 1:";
    cin >> Number1;
    cout << "Enter number 2:";
    cin >> Number2;
    cout << "Задание 2, Проверка var1:" << Number1 << "+" << Number2 << "=" << Number1 + Number2 << endl;
    if (((Number1 == 10) && (Number2 == 10)) || ((Number1+Number2) == 10))
    {
        cout << "Задание 2 вывод: " << TRUE << endl;
    }
    else
    {
        cout << "Задание 2 вывод: " << FOLSE << endl;
    }
};


void task3var1()
{
    for (size_t i = 1; i < 50; i += 2)
    {
        cout << i << " ";
    }
    cout << endl;
};

void task3var2()
{
    for (size_t i = 1; i < 50; i++)
    {
        if (i % 2 != 0)
            cout << i << " ";
    }
    cout << endl;
};

void task4()
{
    int number;
    cout << "Введите целое, положительное число:";
    cin >> number;
    int d{ 0 };
    int i{ 1 };
    while ( i <= number)
    {
        if (number % i++ == 0)
        {
            d++;
        }
        else
        {
            continue;
        }
        if (d == 3)
        {
            break;
        }
    }
    d == 3 ? cout << "Число является не простым" <<endl : cout <<"Число является простым" <<endl;
   
};

void task5()
{
    int year;
    cout << "Введите год (от 1 до 3000):";
    cin >> year;
    if ((year % 4 == 0) || ((year % 400 == 0) && (year % 100 != 0)))
    {
        cout << "Год явлеется високосным";
    }
    else
    {
        cout << "Год не является високосным";
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    task1();
    task2();
    task3var1();
    task3var2();
    task4();
    task5();
}