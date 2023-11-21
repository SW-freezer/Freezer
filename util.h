#pragma once
#include <Windows.h>

void processKeyInput();
int collision_pc_map(int dx, int dy);

// pc�� �� �浹
int collision_pc_map(int dx, int dy) {
	if (stage1_map[pc.arrY + dy][pc.arrX + dx] == 1) return 1;
	return 0;
}

// pc�� ���� �浹
int collision_pc_rock(int dx, int dy) {
	for (int i = 0; i < 4; i++) { // ���� 4���� ��ȸ�ϸ� ���� pc�� �浹�˻�
		if (stage1_rocks[i].arrX == pc.arrX + dx && stage1_rocks[i].arrY == pc.arrY + dy) {
			if (stage1_map[stage1_rocks[i].arrY + dy][stage1_rocks[i].arrX + dx] == 1) { // ���� �ڿ� ���� �ִ� ���
				return 1;
			}
			for (int j = 0; j < 4; j++) { // ���� �ڿ� �ٸ� ������ �ִ� ���
				if (stage1_rocks[j].arrX == stage1_rocks[i].arrX + dx && stage1_rocks[j].arrY == stage1_rocks[i].arrY + dy)
					return 1;
			}

			for (int j = 0; j < 3; j++) { // ���� �ڿ� �浿�� �ִ� ���
				if (stage1_gildong[j].arrX == stage1_rocks[i].arrX + dx && stage1_gildong[j].arrY == stage1_rocks[i].arrY + dy)
					return 1;
			}

			// �浹�� ������ ��ĭ �з��� ��
			stage1_rocks[i].posX += dx * CELL_WIDTH;
			stage1_rocks[i].posY += dy * CELL_WIDTH;
			stage1_rocks[i].arrX += dx;
			stage1_rocks[i].arrY += dy;
		}
	}
	return 0;
}

// pc�� ����� �浹 (�������� Ŭ����)
int collision_pc_refrigerator() {
	if (stage1_refrigerator.arrX == pc.arrX && stage1_refrigerator.arrY == pc.arrY)
		return 1;
	return 0;
}


void drawStage1(int isGildongRun, int idx) {

	drawTexture(map1_img, 0, 0);
	drawTexture(pc_img, pc.posX, pc.posY);
	drawTexture(refrigerator_img, 890, 446);
	drawTexture(roundCnt_img, 1062, 485);


	if (!isGildongRun) {
		for (int i = 0; i < 3; i++) {
			drawTexture(gildong_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
		}
	}

	else {
		for (int i = 0; i < 3; i++) {
			if (idx == i) continue;
			drawTexture(gildong_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
		}
	}

	for (int i = 0; i < 4; i++) {
		drawTexture(rock_img, stage1_rocks[i].posX, stage1_rocks[i].posY);
	}

	if (walkCnt >= 0 && walkCnt <= 23)
		drawTexture(walkCnt_imgs[walkCnt], 136, 485);

}


void gildong_run(int i) {

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_1.png");
	processKeyInput();
	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);


	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_2.png");
	processKeyInput();


	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_3.png");
	processKeyInput();

	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_4.png");
	processKeyInput();

	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

	SDL_RenderClear(renderer);
	gildong_run_img = loadTexture("./assets/gildong_run_5.png");
	processKeyInput();

	drawStage1(1, i);
	drawTexture(gildong_run_img, stage1_gildong[i].posX, stage1_gildong[i].posY);
	SDL_RenderPresent(renderer);
	Sleep(130);

}

int collision_pc_gogildong(int dx, int dy) { //pc�� �浿 �浹
	for (int i = 0; i < 3; i++) {
		if (stage1_gildong[i].arrX == pc.arrX + dx && stage1_gildong[i].arrY == pc.arrY + dy) {
			if (stage1_map[stage1_gildong[i].arrY + dy][stage1_gildong[i].arrX + dx] == 1) { // �浿 �ڿ� �� (�����)
				gildong_run(i); // �浿�� �������� ���ϸ��̼�
				stage1_gildong[i].posX += dx * CELL_WIDTH * 1000;
				stage1_gildong[i].posY += dy * CELL_WIDTH * 1000;
				stage1_gildong[i].arrX += dx;
				stage1_gildong[i].arrY += dy;
				return 1;
			}
			for (int j = 0; j < 3; j++) { // �浿 �ڿ� �ٸ� �浿�� �ִ� ���
				if (stage1_gildong[j].arrX == stage1_gildong[i].arrX + dx && stage1_gildong[j].arrY == stage1_gildong[i].arrY + dy) {
					gildong_run(i); // �浿�� �������� ���ϸ��̼�
					stage1_gildong[i].posX += dx * CELL_WIDTH * 1000;
					stage1_gildong[i].posY += dy * CELL_WIDTH * 1000;
					stage1_gildong[i].arrX += dx * 2;
					stage1_gildong[i].arrY += dy * 2;
					return 1;
				}
			}

			for (int j = 0; j < 4; j++) { // �浿 �ڿ� ������ �ִ� ���
				if (stage1_rocks[j].arrX == stage1_gildong[i].arrX + dx && stage1_rocks[j].arrY == stage1_gildong[i].arrY + dy){
					gildong_run(i); // �浿�� �������� ���ϸ��̼�
				stage1_gildong[i].posX += dx * CELL_WIDTH * 1000;
				stage1_gildong[i].posY += dy * CELL_WIDTH * 1000;
				stage1_gildong[i].arrX += dx * 2;
				stage1_gildong[i].arrY += dy * 2;
					return 1;
				}
			}

			// �浹�� �浿�� �� ĭ �з��� ��
			stage1_gildong[i].posX += dx * CELL_WIDTH;
			stage1_gildong[i].posY += dy * CELL_WIDTH;
			stage1_gildong[i].arrX += dx;
			stage1_gildong[i].arrY += dy;
		}
	}
	return 0;
}



SDL_Event event;
void processKeyInput() {
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
			case 1073741903: // right
				if (collision_pc_map(1, 0)) break;
				if (collision_pc_rock(1, 0)) break;
				walkCnt--;
				if (collision_pc_gogildong(1, 0) == 1) break;
				pc.posX += CELL_WIDTH;
				pc.arrX++;
				break;
			case 1073741904: // left
				if (collision_pc_map(-1, 0)) break;
				if (collision_pc_rock(-1, 0)) break;
				walkCnt--;
				if (collision_pc_gogildong(-1, 0)) break;
				pc.posX -= CELL_WIDTH;
				pc.arrX--;
				break;
			case 1073741905: // down
				if (collision_pc_map(0, 1)) break;
				if (collision_pc_rock(0, 1)) break;
				walkCnt--;
				if (collision_pc_gogildong(0, 1)) break;
				pc.posY += CELL_WIDTH;
				pc.arrY++;
				break;
			case 1073741906: // up
				if (collision_pc_map(0, -1)) break;
				if (collision_pc_rock(0, -1)) break;
				walkCnt--;
				if (collision_pc_gogildong(0, -1)) break;
				pc.posY -= CELL_WIDTH;
				pc.arrY--;
				break;
			case 27: // ESC
				quit = true;
				break;
			}
	}
}
