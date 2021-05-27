#include <iostream>
#include <stdlib.h>

using namespace std;
enum TicTacToeCell { t_empty, cross, zero };//Задание 2.2
const int SIZE = 3;
void task1()// Задание 2.1
{
	char a = 'g';
	short int b = 32000;
	int c = 32'332'323;
	long long d = 1'067'807'568'508'756;
	bool e = true;
	float f = 2.345;
	double z = 2.54354;
	cout << "Проверка" << endl << a << "  " << b << " " << c << " " << d << " " << e << " " << f << " " << z << endl;
}

void task3()
{
	TicTacToeCell arr[SIZE][SIZE] = { t_empty };//Задание 2.3
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			cout << arr[y][x] <<" ";
		}
		cout << endl;
	}
	
};

struct Player
{
	TicTacToeCell tip;
	char Name[255];
};


struct TicTacToe//задание 2.4
{
	TicTacToeCell arr[SIZE][SIZE];
	bool Gamefinished;
	Player Player1, Player2;
	const unsigned int Fieldsize = SIZE;
};

union myVariantdata//Задание 2.5
{
	char myChar;
	int myInt;
	float myFloat;
};

struct myVariant {//Задание 2.5
	myVariantdata data;
	unsigned int isChar : 1;
	unsigned int isInt : 1;
	unsigned int isFloat : 1;
};

void Print(const myVariant& var)
{
	if (var.isChar == 1)
		cout << var.data.myChar;
	
	else if (var.isInt == 1)
	
		cout << var.data.myInt << endl;
	
	else cout << var.data.myFloat;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	task1();
	task3();

	myVariant var;//Задание 2.5
	var.data.myInt = 10;
	var.isChar = 0;
	var.isInt = 1;
	var.isFloat = 0;
	Print(var);

	var.data.myChar = 'f';
	var.isChar = 1;
	var.isInt = 0;
	var.isFloat = 0;
	Print(var);
}