#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "sdl.h"


// ���� �Լ�
int main(int argc, char** argv) {

	initAll();  // SDL �ʱ�ȭ �Լ� ȣ��

	player = loadTexture("player.png");  // �ؽ�ó �ε�
	bg1 = loadTexture("bg1.png");

	bool quit = false;
	SDL_Event event;

	while (!quit) {
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case 1073741903: // right
					doraPosX += 10;
					break;
				case 1073741904: // left
					doraPosX -= 10;
					break;
				case 1073741905: // down
					doraPosY += 10;
					break;
				case 1073741906: // up
					doraPosY -= 10;
					break;
				case 27: // ESC
					quit = true;
					break;
				}
			}
		}
		drawTexture(bg1, 0, 0);  // �ؽ�ó �׸���
		drawTexture(player, doraPosX, doraPosY);  // �ؽ�ó �׸���
		SDL_RenderPresent(renderer);  // ������ ������Ʈ
	}


	closeAll();  // �޸� ����
	return 0;
}
