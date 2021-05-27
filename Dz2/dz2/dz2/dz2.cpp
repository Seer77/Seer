#include <iostream>
#include <stdlib.h>

using namespace std;
enum TicTacToeCell { t_empty, cross, zero };//Задание 2.2

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
	TicTacToeCell arr[3][3] = { t_empty };//Задание 2.3
	cout << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << " " << endl;//Проверка инициализации массива
	cout << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << " " << endl;
	cout << arr[2][0] << " " << arr[2][1] << " " << arr[2][2] << " " << endl;
};

struct TicTacToe//задание 2.4
{
	TicTacToeCell arr[3][3];
	bool Gamefinished;
	TicTacToeCell Player1, Player2;
	long idPlayer1, idPlayer2;
	const unsigned int Fieldsize = 3;
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
	if (var.isChar == 1)//как закинуть в функцию пока не понимаю (как прописать входящие данные для цикла), поэтому использую здесь дважды
	{
		cout << var.isChar;
	}
	else if (var.isInt == 1)
	{
		cout << var.data.myInt << endl;
	}
	else cout << var.isFloat;

	var.data.myChar = 'f';
	var.isChar = 1;
	var.isInt = 0;
	var.isFloat = 0;
	if (var.isChar == 1)
	{
		cout << var.data.myChar <<endl;
	}
	else if (var.isInt == 1)
	{
		cout << var.isInt;
	}
	else cout << var.isFloat;
}
