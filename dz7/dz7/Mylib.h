#pragma once
#include <stdint.h>
#include <locale.h>
#include <iostream>
#include<string>
#include <fstream>
#define RANGE_CHECK(EnterNumber) ((0 <= EnterNumber && EnterNumber < LimitNumber) ? TRUE : FOLSE)
#define SwapINT(a,b)  {int c=a; a=b; b=c;}

namespace Mylib//Задание №5 в задании 1
{
    size_t EnterSIZEArray(std::size_t* size);
    void ArrayInitialization(float* ptrArray, std::size_t SIZE);
    void PrintArray(float* ptrArray, size_t size);
    void NumberfPositiveandNegativeNumbers(float* ptrArray, size_t size);
}
#define SIZE 10
int InitializationArray(int* pArray, size_t size);
int BubbleSort(int* pArray, size_t size);
void PrintArray(int* pArray, size_t size);
#pragma pack(push, 1)
struct Employee
{
    long id{ 0 };
    unsigned short age{ 0 };
    double salary{ 0 };
    std::string name{ 0 };
};
#pragma pack(pop)

void task_1();
void task_2();
void task_3();
void task_4();


