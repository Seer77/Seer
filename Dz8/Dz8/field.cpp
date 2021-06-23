#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

enum Cell
{
	CROSS = 'X',
	ZERO = '0',
	EMPTY = '_'
};

struct Coord
{
	size_t y;
	size_t x;
};

enum Progress
{
	IN_PROGRESS,
	WON_HUMAN,
	WON_AI,
	DRAW
};



#pragma pack(push,1)
struct Field
{
	Cell** ppField = nullptr;
	const size_t SIZE = 5;
	Cell human = EMPTY;
	Cell ai = EMPTY;
	size_t turn = 0;
	Progress progress = IN_PROGRESS;
};
#pragma pack(pop)

int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::mt19937_64 generator(seed);
	std::uniform_int_distribution<int32_t>dis(min, max);
	return dis(generator);
}

void initField(Field& r)
{
	r.ppField = new Cell * [r.SIZE];
	for (size_t i = 0; i < r.SIZE; i++)
	{
		r.ppField[i] = new Cell[r.SIZE];
	}

	for (size_t y = 0; y < r.SIZE; y++)
	{
		for (size_t x = 0; x < r.SIZE; x++)
		{
			r.ppField[y][x] = EMPTY;
		}
	}

	if (getRandomNum(0, 1000) > 500)
	{
		r.human = CROSS;
		r.ai = ZERO;
		r.turn = 0;
	}
	else
	{
		r.human = ZERO;
		r.ai = CROSS;
		r.turn = 1;
	}

}

void deinitField(Field& r)
{
	for (size_t i = 0; i < r.SIZE; i++)
	{
		delete[] r.ppField[i];

	}
	delete[] r.ppField;
	r.ppField = nullptr;
}

void printField(const Field& r)
{
	std::cout << std::endl << "     ";
	for (size_t x = 0; x < r.SIZE; x++)
	{
		std::cout << x + 1 << "   ";
	}
	std::cout << std::endl;

	for (size_t y = 0; y < r.SIZE; y++)
	{
		std::cout << " " << y + 1 << " | ";
		for (size_t x = 0; x < r.SIZE; x++)
		{
			std::cout << static_cast<char>(r.ppField[y][x]) << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "   Human: " << static_cast<char>(r.human) << std::endl;
	std::cout << "Computer: " << static_cast<char>(r.ai) << std::endl << std::endl;
}

void inline clearScr()
{
	system("cls");
}

Coord getHumanCoord(Field& f)
{
	Coord c;
	do
	{
		std::cout << "Enter x: ";
		std::cin >> c.x;
		std::cout << "Enter y: ";
		std::cin >> c.y;
		if (c.x == 0 || c.y == 0 || c.x > f.SIZE || c.y > f.SIZE || f.ppField[c.y - 1][c.x - 1] != EMPTY)
		{
			std::cerr << "Error! This cell is busy!" << std::endl;
		}
	} while (c.x == 0 || c.y == 0 || c.x > f.SIZE || c.y > f.SIZE || f.ppField[c.y - 1][c.x - 1] != EMPTY);

	c.x--;
	c.y--;

	return c;
}

Progress getWon(const Field& f);

Coord getAICoord(Field& f)
{
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				f.ppField[y][x] = f.ai;
				if (getWon(f) == WON_AI)
				{
					f.ppField[y][x] = EMPTY;
					return{ y , x };
				}
				f.ppField[y][x] = EMPTY;
			}
		}
	}

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				f.ppField[y][x] = f.human;
				if (getWon(f) == WON_HUMAN)
				{
					f.ppField[y][x] = EMPTY;
					return{ y , x };
				}
				f.ppField[y][x] = EMPTY;
			}
		}
	}

	size_t centr = f.SIZE / 2;

	if (f.ppField[centr][centr] == EMPTY)
	{
		return { centr,centr };
	}
	Coord arr[4] = { 0 };
	size_t num = 0;
	if (f.ppField[0][0] == EMPTY)
	{
		arr[num++] = { 0,0 };
	}
	if (f.ppField[f.SIZE - 1][f.SIZE - 1] == EMPTY)
	{
		arr[num++] = { f.SIZE - 1, f.SIZE - 1 };
	}
	if (f.ppField[0][f.SIZE - 1] == EMPTY)
	{
		arr[num++] = { 0 , f.SIZE - 1 };
	}
	if (f.ppField[f.SIZE - 1][0] == EMPTY)
	{
		arr[num++] = { f.SIZE - 1, 0 };
	}
	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return arr[index];
	}

	num = 0;

	Coord arr1[100] = { 0 };
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				arr1[num++] = { y,x };
			}
		}
	}

	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return arr1[index];
	}
	return{ 1,1 };
}

Progress getWon(const Field& f)
{


	for (size_t y = 0; y < f.SIZE; y++)
	{
		size_t comulative_variable_horizont_ai = 0;
		size_t comulative_variable_horizont_human = 0;
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == f.ai)
			{
				comulative_variable_horizont_ai++;
			}
			else if (f.ppField[y][x] == f.human)
			{
				comulative_variable_horizont_human++;
			}

			if (comulative_variable_horizont_ai == f.SIZE)
			{
				return WON_AI;
			}
			else if (comulative_variable_horizont_human == f.SIZE)
			{
				return WON_HUMAN;
			}
		}
	}

	for (size_t x = 0; x < f.SIZE; x++)
	{
		size_t comulative_variable_vertical_ai = 0;
		size_t comulative_variable_vertical_human = 0;
		for (size_t y = 0; y < f.SIZE; y++)
		{
			if (f.ppField[y][x] == f.ai)
			{
				comulative_variable_vertical_ai++;
			}
			else if (f.ppField[y][x] == f.human)
			{
				comulative_variable_vertical_human++;
			}

			if (comulative_variable_vertical_ai == f.SIZE)
			{
				return WON_AI;
			}
			else if (comulative_variable_vertical_human == f.SIZE)
			{
				return WON_HUMAN;
			}

		}
	}

	size_t diagonal_sum_ai = 0;
	size_t diafonal_sum_human = 0;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		if (f.ppField[y][y] == f.ai)
		{
			diagonal_sum_ai++;
		}
		else if (f.ppField[y][y] == f.human)
		{
			diafonal_sum_human++;
		}
	}
	if (diagonal_sum_ai == f.SIZE)
	{
		return WON_AI;
	}
	else if (diafonal_sum_human == f.SIZE)
	{
		return WON_HUMAN;
	}

	diagonal_sum_ai = 0;
	diafonal_sum_human = 0;
	size_t diagonal_min_max = f.SIZE - 1;
	size_t diagonal_max_min = 0;

	for (size_t i = 0; i < f.SIZE; i++)
	{
		if (f.ppField[diagonal_min_max][diagonal_max_min] == f.ai)
		{
			diagonal_sum_ai++;
		}
		else if (f.ppField[diagonal_min_max][diagonal_max_min] == f.human)
		{
			diafonal_sum_human++;
		}
		diagonal_min_max--;
		diagonal_max_min++;
	}

	if (diagonal_sum_ai == f.SIZE)
	{
		return WON_AI;
	}
	else if (diafonal_sum_human == f.SIZE)
	{
		return WON_HUMAN;
	}

	bool draw = true;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				draw = false;
				break;
			}
		}

		if (!draw)
		{
			break;
		}
	}
	if (draw)
	{
		return DRAW;
	}
	return IN_PROGRESS;
}

void congrats(Progress progress)
{
	if (progress == WON_HUMAN)
	{
		std::cout << "Human won! =)" << std::endl;
	}
	else if (progress == WON_AI)
	{
		std::cout << "Computer won! =)" << std::endl;
	}
	else if (progress == DRAW)
	{
		std::cout << "Draw =/" << std::endl;
	}

}

void Game()
{
	Field f;
	initField(f);

	clearScr();
	printField(f);

	do {

		if (f.turn % 2 == 0)
		{
			Coord c = getHumanCoord(f);
			f.ppField[c.y][c.x] = f.human;
		}
		else
		{
			Coord c = getAICoord(f);
			f.ppField[c.y][c.x] = f.ai;
		}
		f.turn++;
		clearScr();
		printField(f);
		f.progress = getWon(f);

	} while (f.progress == IN_PROGRESS);

	congrats(f.progress);
	deinitField(f);
}
