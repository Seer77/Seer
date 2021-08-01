#include <iostream>

int main()
{
    int number;
    std::cout << "Enter an integer, positive number:";
    std::cin >> number;
    int d{ 0 };
    int i{ 1 };
    while (i <= number)
    {
        if (number % i++ == 0)
        {
            d++;
        }
        else
        {
            continue;
        }
        if (d == 3)
        {
            break;
        }
    }
    d == 3 ? std::cout << "Number is not prime" << std::endl : std::cout << "The number is prime" << std::endl;

    size_t SUMM { 0 };
    for (size_t i = 1; i <= 10; i++)
    {
        SUMM = SUMM + i;
    }
    std::cout << SUMM;
}