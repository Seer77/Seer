#include <stdint.h>
#include <locale.h>
#include <iostream>
#include<string>

//Функции рандом разные, так как в заданиях требуются разные варианты инициализации, где по заданию, где то для упрощения проверки

void  printArray(int* pArray, size_t SIZE)//Функция распечатывает массив
{
	for (size_t i = 0; i < SIZE; i++)
		std::cout << pArray[i] << "  ";
}

void  printArray(double* pArray, size_t SIZE)//Функция распечатывает массив
{
	for (size_t i = 0; i < SIZE; i++)
		std::cout << pArray[i] << "  ";
}

void inverse(int* pArray, size_t SIZE)//Функция инверсирует масси (вместо 0 ставит 1, и наоборот)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		pArray[i] = (pArray[i] == 1) ? 0 : 1;
	}
}


void task_1()//Задание №1 Вывести массив double
{
	const size_t SIZE{ 8 };
	double Array[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		Array[i] = (double)rand() / 100;//Заполнение массива случайными числами типа double
	};
	printArray(Array, SIZE);
	std::cout << std::endl << std::endl;
}

void task_2()//Задание №2 Задать целочисленный массив из "1" и "0" и замена "1" нулями, а "0" единицами
{
	const size_t SIZE{ 8 };
	int Array[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		Array[i] = rand() % 2;// Инициализация массива единицами и нулями
	}
	printArray(Array, SIZE);
	std::cout << std::endl;
	inverse(Array, SIZE);//инверсия массива
	printArray(Array, SIZE);
	std::cout << std::endl << std::endl;

}

void filling(int* pArray, size_t SIZE)//Инициализация массива начиная с 1 с шагом 3
{
	int posOne = 1;
	const int STEP = 3;
	for (size_t i = 0; i < SIZE; i++)
	{
		pArray[i] = posOne;
		posOne += STEP;
	}
}

void task_3()//Задание №3 Создать целочисленный массив и заполнить его последовательностью значений с шагом 3
{
	const size_t SIZE{ 8 };
	int Array[SIZE];
	filling(Array, SIZE);//Инициализация массива
	printArray(Array, SIZE);
	std::cout << std::endl << std::endl;
}

const size_t SIZEtask4 = 10;

void offsetArray(int* pArray, int bias)//Функция сдвига массива
{
	int offsetArray[SIZEtask4];

	bias = bias % SIZEtask4;//Проверка на цикличность сдвига массива, отбрасываем целые числа(количество соответствующих "кругов"), остаток - количество позиций для сдвига в рамках размера массива

	if (bias == 0)//Если сдвиг на 0 ячеек ничего не делаем
	{
		return;
	}

	for (size_t i = 0; i < SIZEtask4; i++)
	{
		if (bias > 0)//Если сдвиг положительно двигаем вправо
		{
			if (i < bias)
			{
				offsetArray[i] = pArray[SIZEtask4 - (bias - i)];
			}
			else
			{
				offsetArray[i] = pArray[i - bias];
			}
		}
		else//Иначе двигаем влево
		{
			if (i - bias < SIZEtask4)
			{
				offsetArray[i] = pArray[i - bias];
			}
			else
			{
				offsetArray[i] = pArray[-bias - (SIZEtask4 - i)];
			}
		}
	}
	for (size_t i = 0; i < SIZEtask4; i++)
	{
		pArray[i] = offsetArray[i];
	}
}




void task_4()//Задание №4 Написать функцию сдвига массива вправо или влево
{
	int Array[SIZEtask4];
	for (size_t i = 0; i < SIZEtask4; i++)
	{
		Array[i] = rand() % 100;//Инициализируем массив целыми числами от 0 до 100
	}
	std::cout << "filled array" << std::endl;
	printArray(Array, SIZEtask4);
	std::cout << std::endl;
	int bias;
	std::cout << "How many cell to offset the array:";
	std::cin >> bias;
	offsetArray(Array, bias);//Функция сдвига массива
	std::cout << "Offset array" << std::endl;
	printArray(Array, SIZEtask4);
	std::cout << std::endl;
}

bool Balance(int* pArray, int Sum, int size)//Функция определения баланса значений в массиве
{
	int LeftSum{ 0 };
	for (size_t i = 0; i < size; i++)
	{
		LeftSum += pArray[i];
		if (LeftSum == Sum - LeftSum)
		{
			return true;
		}

	}
	return false;
}

const std::string TRUE = "true";
const std::string FOLSE = "folse";
const std::string BalancedText = "Balanced:";

int RandNum(int* pArray, size_t size)//Функция инициализации массива для 5-го задания (заполняется числами от 0 до 3 - для меньшего количества вариаций)
{
	for (size_t i = 0; i < size; i++)
	{
		pArray[i] = rand() % 4;
	}
	return  *pArray;
}

void task_5()// Задание №5 Написать функцию которая возвращает истину при равной сумме левой и правой части массива 
{
	const int Sizetask5 = 10;
	int Array[Sizetask5];
	RandNum(Array, Sizetask5);//Инициализация массива
	std::cout << "filled array" << std::endl;
	printArray(Array, Sizetask5);
	std::cout << std::endl;
	int SumArray{ 0 };
	for (size_t i = 0; i < Sizetask5; i++)
	{
		SumArray += Array[i];
	}
	std::cout << "Sum elements array:" << SumArray << std::endl;//Выводим сумму, для проверки
	std::cout << BalancedText << (Balance(Array, SumArray, Sizetask5) ? TRUE : FOLSE) << std::endl << std::endl;//Вызываем функцию поиска баланса и выводим результат
}
