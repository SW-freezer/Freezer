#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"


// ���� �Լ�
int main(int argc, char** argv) {
	
	initAll();  // �ʱ�ȭ �Լ� ȣ��
	dora = loadTexture("doraemong.png");  // �ؽ�ó �ε�
	tmp = loadTexture("tmp.png");  // �ؽ�ó �ε�

	bool quit = false;
	SDL_Event event;

	while (!quit) {
		while (SDL_PollEvent(&event)) {

			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case 1073741903: // right
					doraPosX+= 10;
					break;
				case 1073741904: // left
					doraPosX-= 10;
					break;
				case 1073741905: // down
					doraPosY+= 10;
					break;
				case 1073741906: // up
					doraPosY-= 10;
					break;
				}
			}
		}
		SDL_RenderClear(renderer);   // ������ Ŭ����
		drawTexture(dora, doraPosX, doraPosY);  // �ؽ�ó �׸���
		SDL_RenderPresent(renderer);  // ������ ������Ʈ
	}


	closeAll();  // �޸� ����
	return 0;
}
