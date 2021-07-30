#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl;
    int a, b;
    std::cout << "Input number one:" << std::endl;
    std::cin >> a;
    std::cout << "Input number two:" << std::endl;
    std::cin >> b;
    int c = a * b;
    std::cout << "Product of a and b = "; std::cout << c;
}

