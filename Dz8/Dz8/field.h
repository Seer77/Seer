#pragma once

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

int32_t getRandomNum(int32_t min, int32_t max);

void initField(Field& r);

void deinitField(Field& r);

void printField(const Field& r);


void inline clearScr();


Coord getHumanCoord(Field& f);


Progress getWon(const Field& f);

Coord getAICoord(Field& f);

Progress getWon(const Field& f);


void congrats(Progress progress);

void Game();
