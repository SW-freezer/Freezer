#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

// â�� ũ��
static const int width = 1440;
static const int height = 730;

// pc��ġ
int pcPosX = 820;
int pcPosY = 170;

// ���� ��������
bool quit = false;


int map1_info[6][7] = {
	{1, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0},
};


