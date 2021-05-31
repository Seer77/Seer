#include <stdint.h>
#include <locale.h>
#include <iostream>


int32_t a;//{ 100 };
int32_t b;//{ 200 };
int32_t c;//{ 300 };
int32_t d;//{ 400 };

void UserInput()
{
	std::cout << "Введите целое число для переменной а:";
	std::cin >> a;
	std::cout << "Введите целое число для переменной b:";
	std::cin >> b;
	std::cout << "Введите целое число для переменной c:";
	std::cin >> c;
	std::cout << "Введите целое число для переменной d(не равное 0):";
	std::cin >> d;
	while (d == 0)
	{
		std::cout << "Вы ввели 0 (на 0 делить нельзя), введите число не равное 0 ";
		std::cin >> d;
	}
	
}
