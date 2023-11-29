#define  _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"
#include "display.h"
#include "util.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage5.h"



int main(int argc, char** argv) {

	initAll(); // SDL �ʱ�ȭ
	loadImg();

	//stage1();
	//stage2();
	//stage3();

	stage5();
	
	closeAll(); // SDL �޸� ����
	return 0;
}
