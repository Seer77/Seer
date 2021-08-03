#include <iostream>
#include <iomanip>


void byn(int number)//4.1
{
	if (number >= 2)
	{
		byn(number / 2);
	}
	std::cout <<" " << number % 2;
}

int power(int a, int n)//4.2.1
{
	if (n == 0)
	{
		return 1;
	}
	int p = power(a, n / 2);
		if (n % 2 == 0)
		{
			return p * p;
		}
		else
		{
			return a * p * p;
		}
}

void parity(int *a, int *n)//4.2.2
{
	if (*n % 2 == 0)
	{
		std::cout << *a * *a / 2<<std::endl;
	}
	else
	{
		std::cout << power(*a, *n) * *a - 1<<std::endl;
	}
}

int routes(int x, int y)
{

	if (x == 0 && y == 0)
	{
		return 0;
	}
	else if (x == 0 || y == 0)
	{
		return 1;
	}
	else
	{
		
		return routes(x, y - 1) + routes(x - 1, y);
	}

}


int routesvar1(int x, int y)
{

	if (x == 0 && y == 0)
	{
		return 0;
	}
	else if (x == 0 || y == 0)
	{
		return 1;
	}
	else
	{
		if (x == 3 && y == 1)
		{
			return 0;
		}
		else if (x == 2 && y == 3)
		{
			return 0;
		}
			return routesvar1(x, y - 1) + routesvar1(x - 1, y);
	}

}

int main()
{
	int number;
	std::cout << "number:" <<std::endl;
	std::cin >> number;
	byn(number);
	std::cout << std::endl;
	//4.2.1
	int num;
	int steppe;
		std::cout << "Enter number:" <<std::endl;
		std::cin >> num;
		std::cout << "Enter psteppe:" << std::endl;
		std::cin >> steppe;
		std::cout<<" " << power(num, steppe) << std::endl;

		parity(&num, &steppe);//4.2.2

	const int sizeX = 8;
	const int sizeY = 8;
	std::cout << "Without obstacles" << std::endl;
	for (size_t y = 0; y < sizeY; y++)
	{
		for (size_t x = 0; x < sizeX; x++)
		{
			std::cout << std::setw(6) << routes(x, y);
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout <<"With obstacles" << std::endl;
	for (size_t y = 0; y < sizeY; y++)
	{
		for (size_t x = 0; x < sizeX; x++)
		{
			std::cout << std::setw(6) << routesvar1(x, y);
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}


}

