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

typedef struct Refrigerator {

	//ȭ�鿡�� ������� ��ġ
	int posX;
	int posY;

	// ������ �迭���� ������� ��ġ
	int arrX;
	int arrY;
}Refrigerator;

//������
int walkCnt=23;

// â�� ũ��
static const int width = 1440;
static const int height = 730;

Pc pc;
Rock stage1_rocks[4];
Gildong stage1_gildong[3];
Refrigerator stage1_refrigerator;

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

