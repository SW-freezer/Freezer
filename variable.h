#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define CELL_WIDTH 70 // ������ �� ĭ�� �ʺ�

typedef struct Pc {

	// ȭ�鿡�� pc��ġ
	int posX;
	int posY;

	// ������ �迭���� pc��ġ
	int arrX;
	int arrY;
}Pc;

typedef struct Rock {

	// ȭ�鿡�� ���� ��ġ
	int posX;
	int posY;

	// ������ �迭���� ���� ��ġ
	int arrX;
	int arrY;
}Rock;

typedef struct Gildong {

	// ȭ�鿡�� �浿�� ��ġ
	int posX;
	int posY;

	// ������ �迭���� �浿�� ��ġ
	int arrX;
	int arrY;
}Gildong;



// â�� ũ��
static const int width = 1440;
static const int height = 730;

// ���� ��������
bool quit = false;

Pc pc = { 820, 170, 6, 1 };

Rock stage1_rocks[4] = {
	{ 540, 446, 2, 5 } ,
	{ 540, 516, 2, 6 } ,
	{ 680, 516, 4, 6 } ,
	{ 750, 446, 5, 5 }
};

Gildong stage1_gildong[3] = {
	{ 680, 236, 4, 2 } ,
	{ 610, 306, 3, 3 } ,
	{ 750, 306, 5, 3 }
};


int stage1_map[8][9] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 1, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
};

