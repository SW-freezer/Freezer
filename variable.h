#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>


SDL_Window* window;         // SDL â�� ��Ÿ���� ������ ����
SDL_Renderer* renderer;     // SDL �������� ��Ÿ���� ������ ����



// â�� ũ��
static const int width = 1200;
static const int height = 800;


SDL_Texture* dora;
int doraPosX, doraPosY;

