#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"
#include "display.h"
#include "stage1.h"
#include "util.h"


// ���� �Լ�
int main(int argc, char** argv) {

	initAll();  // SDL �ʱ�ȭ �Լ� ȣ��
	loadImg();

	while (!quit) {
		
	processKeyInput();
	stage1();
	}


	closeAll();  // �޸� ����
	return 0;
}
