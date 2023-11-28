#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define CELL_WIDTH 70 // ������ �� ĭ�� �ʺ�

// ���� �� ������������ ������ ����
int curStage;

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

typedef struct Crap {
	int posX;
	int posY;

	int arrX;
	int arrY;
}Crap;
//���� ������
int walkCnt;

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

/* ��������2 ������ */

Rock stage2_rocks[3];
Gildong stage2_gildong[3];
Refrigerator stage2_refrigerator;
Crap stage2_crap[6];

int stage2_map[8][9] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1}
};




/* ��������3 ������ */

Gildong stage3_gildong[2];
Refrigerator stage3_refrigerator;
Crap stage3_crap[8];

int stage3_map[9][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};