#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define CELL_WIDTH 70 // ������ �� ĭ�� �ʺ�
#define MAX_NUM_NPC 30 // NPC �ִ� ����

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
Refrigerator refrigerator;
Rock rocks[MAX_NUM_NPC];
Gildong gildongs[MAX_NUM_NPC];
Crap craps[MAX_NUM_NPC];


int maps[10][15][15] = {
	{{0}},

	// �������� 1
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 1, 1, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	},


	// �������� 2
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	},


	// �������� 3
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	}

};

