#include <iostream>
#include <locale.h>
#include "Source.h"

using namespace std;

void task_1_and_4()// переменные объявляются и инициализируются в файле Source.cpp, в файле Source.h экспортируется для использования в cpp файлах
{
	float Expression = a * (b + (static_cast<float>(c) / d));
	cout << Expression << endl;
}

void task_2()
{
	int32_t a, b;
	cout << "Введите целое число:";
	cin >> a;
	b = (a <= 21) ? 21 - a : (a - 21) << 1;
	cout << b << endl;
}

void task_3()
{
	uint32_t Array[3][3][3] = { 0 };
	uint32_t* pArray = nullptr;
	pArray = &Array[0][0][0];
	pArray += 13;
	*pArray = 50;
	cout << Array[1][1][1] << endl;
	cout << *pArray << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	UserInput();
	task_1_and_4();
	task_2();
	task_3();
}