#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "variable.h"



// SDL �����Լ��� ��������


// �ʱ�ȭ �Լ�
static int initAll()
{
	if (SDL_Init(SDL_INIT_EVENTS) != 0)  // SDL �ʱ�ȭ
	{
		fprintf(stderr, "%s\n", (SDL_GetError()));
		return (0);
	}

	// SDL â ����
	window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	if (window == 0)
	{
		fprintf(stderr, "%s\n", (SDL_GetError()));
		return (0);
	}

	// ������ ���� (����ȭ �� ���÷��� �ֻ����� ����ȭ)
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == 0)
	{
		fprintf(stderr, "%s\n", (SDL_GetError()));
		return (0);
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))  // SDL_image �ʱ�ȭ
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return (0);
	}

	return (1);
}





// SDL ���� �Լ�
static void closeAll()
{
	// ����� �̹��� �޸� ��� �����ϼ���
	SDL_DestroyTexture(dora);  // �ؽ�ó ����


	SDL_DestroyRenderer(renderer);  // ������ ����
	SDL_DestroyWindow(window);      // â ����
	IMG_Quit();                     // SDL_image ����
	SDL_Quit();                     // SDL ����
}

// �ؽ�ó �ε� �Լ�
SDL_Texture* loadTexture(const char* file) {
	SDL_Surface* surface;
	SDL_Texture* texture;

	surface = IMG_Load(file);
	if (surface == NULL) {
		printf("fail to read %s\n", file);
		return NULL;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
		printf("unable to create texture.\n");
	}

	SDL_FreeSurface(surface);

	return texture;
}


// �ؽ�ó �׸��� �Լ�
void drawTexture(SDL_Texture* texture, int x, int y) {
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, texture, &src, &dst);
}
