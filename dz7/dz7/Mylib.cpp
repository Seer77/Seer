#include <stdint.h>
#include <locale.h>
#include <iostream>
#include<string>
#include <fstream>

namespace Mylib//������� �5 � ������� 1
{
    size_t EnterSIZEArray(std::size_t* size)//���������������� ���� ������� �������
    {
        std::cout << "Enter size of your array:";
        std::cin >> *size;
        return *size;
    }

    void ArrayInitialization(float* ptrArray, std::size_t SIZE)//������������� �������
    {
        for (std::size_t i = 0; i < SIZE; i++)
        {
            ptrArray[i] = static_cast<float>(rand()) / 100 - 100;
        }

    }

    void PrintArray(float* ptrArray, size_t size)//������ ������� c ���������� float
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << ptrArray[i] << std::endl;
        }
    }

    void NumberfPositiveandNegativeNumbers(float* ptrArray, size_t size)//�������� �� ������������� � ������������� ����� � ������ �� ����������
    {
        size_t Number_of_NegativeNumbers = 0;
        size_t Number_of_PositiveNumbers = 0;
        size_t TheNumber_of_NumbersEqual_toZero = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (ptrArray[i] > 0)
            {
                Number_of_PositiveNumbers += 1;
            }
            else if (ptrArray[i] < 0)
            {
                Number_of_NegativeNumbers += 1;
            }
            else
                TheNumber_of_NumbersEqual_toZero += 1;

        }
        std::cout << "Number of positive numbers  ", std::cout << Number_of_PositiveNumbers << std::endl;
        std::cout << "Number of negative numbers  ", std::cout << Number_of_NegativeNumbers << std::endl;
        std::cout << "Nhe number of numbers equal to zero  ", std::cout << TheNumber_of_NumbersEqual_toZero << std::endl;
    }
}

void task_1()//������� �1
{
    std::size_t SIZE{ 0 };
    Mylib::EnterSIZEArray(&SIZE);
    float* ptrArray{ 0 };
    if (SIZE > 0)
    {
        ptrArray = new(std::nothrow) float[SIZE];
        if (ptrArray != nullptr)
        {
            Mylib::ArrayInitialization(ptrArray, SIZE);
            Mylib::PrintArray(ptrArray, SIZE);
            Mylib::NumberfPositiveandNegativeNumbers(ptrArray, SIZE);
        }
        delete[]ptrArray;
        ptrArray = nullptr;
    }

}

#define RANGE_CHECK(EnterNumber) ((0 <= EnterNumber && EnterNumber < LimitNumber) ? TRUE : FOLSE)//������������ ���������� ������� �� ��������� ����� � ��������

void task_2()//������� �2
{
    const std::string TRUE = "true";
    const std::string FOLSE = "folse";
    int EnterNumber, LimitNumber = 10;//����� ����� ������ �� �� ����������������, �� �� ���� ������ (������ ������� ������������)
    std::cout << "Enter a number defining the range from 0 to 10: ";
    std::cin >> EnterNumber;
    std::cout << RANGE_CHECK(EnterNumber) << std::endl;
}
#define SIZE 10//�������� ������ ������� 

int InitializationArray(int* pArray, size_t size)//���������������� ������������� �������
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Initilize the array: ";
        std::cin >> pArray[i];
    }
    std::cout << std::endl;
    return *pArray;
}
#define SwapINT(a,b)  {int c=a; a=b; b=c;}

int BubbleSort(int* pArray, size_t size)//���������� ����������� ����� (� �������������� ������� ����������� � define
{
    int TemporaryVariable{ 0 };
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (pArray[j] > pArray[j + 1])
            {
                SwapINT(pArray[j], pArray[j + 1]);
            }
        }
    }
    return *pArray;
}

void PrintArray(int* pArray, size_t size)//������ ������� int
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << pArray[i], std::cout << " ";
    }
    std::cout << " " << std::endl;
}

void task_3()//������� �3
{

    int Array[SIZE]{ 0 };
    InitializationArray(Array, SIZE);
    PrintArray(Array, SIZE);
    BubbleSort(Array, SIZE);
    PrintArray(Array, SIZE);
    std::cout << std::endl;
}

#pragma pack(push, 1)//�������� ��������� � �� ���������� ������������
struct Employee
{
    long id{ 0 };
    unsigned short age{ 0 };
    double salary{ 0 };
    std::string name{ 0 };
};
#pragma pack(pop)

void task_4()//������� �4
{
    std::cout << "Structure size: " << sizeof(Employee) << std::endl << std::endl;//����� �� ����� ������� ���������
    const size_t SIZEEmployee = 3;
    Employee* pArray = new (std::nothrow) Employee[SIZEEmployee];
    if (pArray != nullptr)
    {
        pArray[0] = { 213513, 25, 150'000.0, "Ser Ign" };
        pArray[1] = { 213514, 32, 130'000.0, "Ser Fad" };
        pArray[2] = { 213515, 44, 110'000.0, "Ser Som" };

        for (size_t i = 0; i < SIZEEmployee; i++)//����� �� ����� ������� ��������� �����������
        {
            std::cout << "id employee: " << pArray[i].id << std::endl;
            std::cout << "Age employee: " << pArray[i].age << std::endl;
            std::cout << "Salary employee: " << pArray[i].salary << std::endl;
            std::cout << "Name employee: " << pArray[i].name << std::endl << std::endl;
        }

        std::ofstream fout("Structure employee.txt");//������ � ���� ������ �����������
        for (size_t i = 0; i < SIZEEmployee; i++)
        {
            fout << "id employee: " << pArray[i].id << std::endl;
            fout << "Age employee: " << pArray[i].age << std::endl;
            fout << "Salary employee: " << pArray[i].salary << std::endl;
            fout << "Name employee: " << pArray[i].name << std::endl << std::endl;
        }
        fout.close();

        delete[] pArray;
        pArray = nullptr;
    }
}