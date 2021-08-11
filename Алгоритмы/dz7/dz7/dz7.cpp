#include <iostream>

void printIntArray(int* arr, int SZ)
{

    for (int i = 0; i < SZ; ++i)
    {
        std::cout <<" "<< arr[i];
    }
    std::cout << std::endl;
}

    void swapInt(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    void fillIntRandom(int* arr, int SZ, int border)
    {
        for (int i = 0; i < SZ; ++i)
            *(arr + i) = rand() % border;
    }

void qs(int* arr, int first, int last)
{
    int x;
    int i = first;
    int j = last;
    int y = arr[(first + last) / 2];
    if (arr[first] > arr[last])
    {
        if (y > arr[first])
        {
            x=arr[first];
        }
    }
    x = (arr[last] > y) ? arr[j] : y;
    do 
    {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j)
        {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

int main()
{
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ);
    qs(arr, 0, SZ - 1);
    printIntArray(arr, SZ);
}

