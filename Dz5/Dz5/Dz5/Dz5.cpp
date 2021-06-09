#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include"prototipes.h"
#include<string>


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(NULL)));
	task_1();
	task_2();
	task_3();
	task_4();
	std::cout << std::endl;
	task_5();
	task_5();
	task_5();
	task_5();
	task_5();
}