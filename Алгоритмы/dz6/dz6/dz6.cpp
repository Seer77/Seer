#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <math.h>
#include <stdio.h>

void PrintArr(int arr[3][3])//Печать двумерного массива
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << arr[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

void PrintArr1(int arr[9])//Печать одномерного массива
{
    for (size_t k = 0; k < 9; k++)
    {
        std::cout << arr[k] << "  ";
    }
    std::cout << std::endl << std::endl;
}


void bubbleSort(int arr[3][3])
{
    int arr1[9]{ 0 };
    int k = 0;
    for (int z = 0; z < 3; z++)
    {
        for (int x = 0; x < 3; x++, k++)
        {
            arr1[k] = arr[z][x];

        }
    }
    PrintArr1(arr1);

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9 - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                int t = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = t;
            }
        }
    }
    PrintArr1(arr1);
    k = 0;
    for (int z = 0; z < 3; z++)
    {
        for (int x = 0; x < 3; x++, k++)
        {
            arr[z][x] = arr1[k];

        }
    }
    PrintArr(arr);
}

double fun(double t)
{
    return sqrt(fabs(t)) + 5 * pow(t, 3);
}

int main()
{
    int arr[3][3] = { {1,9,2},{5,7,6},{4,3,8} };
    PrintArr(arr);
    std::cout << std::endl;
    bubbleSort(arr);
    std::cout << std::endl;


    {
        double array[11] = { 0 }, y;
        for (int i = 0; i < 11; i++)
        {
            std::cout << "Inter number: ";
            std::cin >> array[i];
        }
        for (int i = 10; i >= 0; i--)
        {
            y = fun(array[i]);
            if (y > 400)
                std::cout << "TOO LARGE: " << i << " - " << y << std::endl;
            else
                std::cout << "Result: " << i << " - " << y << std::endl;
        }
    }

}