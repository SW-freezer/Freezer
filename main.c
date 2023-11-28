#define  _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"
#include "display.h"
#include "stage1.h"
#include "util.h"
#include "stage2.h"
#include "stage3.h"



int main(int argc, char** argv) {

	initAll(); // SDL �ʱ�ȭ
	loadImg();

	stage3();
	gameClear();

	closeAll(); // SDL �޸� ����
	return 0;
}
