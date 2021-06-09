#include <stdint.h>
#include <locale.h>
#include <iostream>
#include<string>

//������� ������ ������, ��� ��� � �������� ��������� ������ �������� �������������, ��� �� �������, ��� �� ��� ��������� ��������

void  printArray(int* pArray, size_t SIZE)//������� ������������� ������
{
	for (size_t i = 0; i < SIZE; i++)
		std::cout << pArray[i] << "  ";
}

void  printArray(double* pArray, size_t SIZE)//������� ������������� ������
{
	for (size_t i = 0; i < SIZE; i++)
		std::cout << pArray[i] << "  ";
}

void inverse(int* pArray, size_t SIZE)//������� ����������� ����� (������ 0 ������ 1, � ��������)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		pArray[i] = (pArray[i] == 1) ? 0 : 1;
	}
}


void task_1()//������� �1 ������� ������ double
{
	const size_t SIZE{ 8 };
	double Array[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		Array[i] = (double)rand() / 100;//���������� ������� ���������� ������� ���� double
	};
	printArray(Array, SIZE);
	std::cout << std::endl << std::endl;
}

void task_2()//������� �2 ������ ������������� ������ �� "1" � "0" � ������ "1" ������, � "0" ���������
{
	const size_t SIZE{ 8 };
	int Array[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		Array[i] = rand() % 2;// ������������� ������� ��������� � ������
	}
	printArray(Array, SIZE);
	std::cout << std::endl;
	inverse(Array, SIZE);//�������� �������
	printArray(Array, SIZE);
	std::cout << std::endl << std::endl;

}

void filling(int* pArray, size_t SIZE)//������������� ������� ������� � 1 � ����� 3
{
	int posOne = 1;
	const int STEP = 3;
	for (size_t i = 0; i < SIZE; i++)
	{
		pArray[i] = posOne;
		posOne += STEP;
	}
}

void task_3()//������� �3 ������� ������������� ������ � ��������� ��� ������������������� �������� � ����� 3
{
	const size_t SIZE{ 8 };
	int Array[SIZE];
	filling(Array, SIZE);//������������� �������
	printArray(Array, SIZE);
	std::cout << std::endl << std::endl;
}

const size_t SIZEtask4 = 10;

void offsetArray(int* pArray, int bias)//������� ������ �������
{
	int offsetArray[SIZEtask4];

	bias = bias % SIZEtask4;//�������� �� ����������� ������ �������, ����������� ����� �����(���������� ��������������� "������"), ������� - ���������� ������� ��� ������ � ������ ������� �������

	if (bias == 0)//���� ����� �� 0 ����� ������ �� ������
	{
		return;
	}

	for (size_t i = 0; i < SIZEtask4; i++)
	{
		if (bias > 0)//���� ����� ������������ ������� ������
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
		else//����� ������� �����
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




void task_4()//������� �4 �������� ������� ������ ������� ������ ��� �����
{
	int Array[SIZEtask4];
	for (size_t i = 0; i < SIZEtask4; i++)
	{
		Array[i] = rand() % 100;//�������������� ������ ������ ������� �� 0 �� 100
	}
	std::cout << "filled array" << std::endl;
	printArray(Array, SIZEtask4);
	std::cout << std::endl;
	int bias;
	std::cout << "How many cell to offset the array:";
	std::cin >> bias;
	offsetArray(Array, bias);//������� ������ �������
	std::cout << "Offset array" << std::endl;
	printArray(Array, SIZEtask4);
	std::cout << std::endl;
}

bool Balance(int* pArray, int Sum, int size)//������� ����������� ������� �������� � �������
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

int RandNum(int* pArray, size_t size)//������� ������������� ������� ��� 5-�� ������� (����������� ������� �� 0 �� 3 - ��� �������� ���������� ��������)
{
	for (size_t i = 0; i < size; i++)
	{
		pArray[i] = rand() % 4;
	}
	return  *pArray;
}

void task_5()// ������� �5 �������� ������� ������� ���������� ������ ��� ������ ����� ����� � ������ ����� ������� 
{
	const int Sizetask5 = 10;
	int Array[Sizetask5];
	RandNum(Array, Sizetask5);//������������� �������
	std::cout << "filled array" << std::endl;
	printArray(Array, Sizetask5);
	std::cout << std::endl;
	int SumArray{ 0 };
	for (size_t i = 0; i < Sizetask5; i++)
	{
		SumArray += Array[i];
	}
	std::cout << "Sum elements array:" << SumArray << std::endl;//������� �����, ��� ��������
	std::cout << BalancedText << (Balance(Array, SumArray, Sizetask5) ? TRUE : FOLSE) << std::endl << std::endl;//�������� ������� ������ ������� � ������� ���������
}
