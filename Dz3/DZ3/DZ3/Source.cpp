#include <stdint.h>
#include <locale.h>
#include <iostream>


int32_t a;//{ 100 };
int32_t b;//{ 200 };
int32_t c;//{ 300 };
int32_t d;//{ 400 };

void UserInput()
{
	std::cout << "������� ����� ����� ��� ���������� �:";
	std::cin >> a;
	std::cout << "������� ����� ����� ��� ���������� b:";
	std::cin >> b;
	std::cout << "������� ����� ����� ��� ���������� c:";
	std::cin >> c;
	std::cout << "������� ����� ����� ��� ���������� d(�� ������ 0):";
	std::cin >> d;
	while (d == 0)
	{
		std::cout << "�� ����� 0 (�� 0 ������ ������), ������� ����� �� ������ 0 ";
		std::cin >> d;
	}
	
}
