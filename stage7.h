#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage7_initPos() {

	// NPC, ������ ��ġ �ʱ�ȭ
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		gildongs[i].posX = -100;
		gildongs[i].posY = -100;
		gildongs[i].arrX = -1;
		gildongs[i].arrY = -1;

		rocks[i].posX = -100;
		rocks[i].posY = -100;
		rocks[i].arrX = -1;
		rocks[i].arrY = -1;

		crabs[i].posX = -100;
		crabs[i].posY = -100;
		crabs[i].arrX = -1;
		crabs[i].arrY = -1;
	}

	shoe.posX = -100;
	shoe.posY = -100;
	shoe.arrX = -1;
	shoe.arrY = -1;

	shield.posX = -100;
	shield.posY = -100;
	shield.arrX = -1;
	shield.arrY = -1;
	// --------------------- ��ǥ��� ------------------------

	// pc
	pc.posX = 880;
	pc.posY = 340;
	pc.arrX = 6;
	pc.arrY = 5;

	// �浿
	gildongs[0].posX = pc.posX - CELL_WIDTH * 5;
	gildongs[0].posY = pc.posY - CELL_WIDTH * 1;
	gildongs[0].arrX = pc.arrX - 5;
	gildongs[0].arrY = pc.arrY - 1;

	gildongs[1].posX = pc.posX - CELL_WIDTH * 2;
	gildongs[1].posY = pc.posY - CELL_WIDTH * 1;
	gildongs[1].arrX = pc.arrX - 2;
	gildongs[1].arrY = pc.arrY - 1;

	gildongs[2].posX = pc.posX - CELL_WIDTH * 3;
	gildongs[2].posY = pc.posY + CELL_WIDTH * 0;
	gildongs[2].arrX = pc.arrX - 3;
	gildongs[2].arrY = pc.arrY + 0;

	// ����
	rocks[0].posX = pc.posX - CELL_WIDTH * 2;
	rocks[0].posY = pc.posY - CELL_WIDTH * 2;
	rocks[0].arrX = pc.arrX - 2;
	rocks[0].arrY = pc.arrY - 2;


	rocks[1].posX = pc.posX - CELL_WIDTH * 1;
	rocks[1].posY = pc.posY - CELL_WIDTH * 2;
	rocks[1].arrX = pc.arrX - 1;
	rocks[1].arrY = pc.arrY - 2;

	rocks[2].posX = pc.posX + CELL_WIDTH * 0;
	rocks[2].posY = pc.posY - CELL_WIDTH * 2;
	rocks[2].arrX = pc.arrX + 0;
	rocks[2].arrY = pc.arrY - 2;


	rocks[3].posX = pc.posX - CELL_WIDTH * 4;
	rocks[3].posY = pc.posY - CELL_WIDTH * 1;
	rocks[3].arrX = pc.arrX - 4;
	rocks[3].arrY = pc.arrY - 1;


	rocks[4].posX = pc.posX - CELL_WIDTH * 1;
	rocks[4].posY = pc.posY - CELL_WIDTH * 1;
	rocks[4].arrX = pc.arrX - 1;
	rocks[4].arrY = pc.arrY - 1;


	// �����
	refrigerator.posX = pc.posX - CELL_WIDTH * 2;
	refrigerator.posY = pc.posY - CELL_WIDTH * 4;
	refrigerator.arrX = pc.arrX - 2;
	refrigerator.arrY = pc.arrY - 4;


	// ��
	crabs[0].posX = pc.posX - CELL_WIDTH * 5;
	crabs[0].posY = pc.posY + CELL_WIDTH * 1;
	crabs[0].arrX = pc.arrX - 5;
	crabs[0].arrY = pc.arrY + 1;

	crabs[1].posX = pc.posX - CELL_WIDTH * 2;
	crabs[1].posY = pc.posY + CELL_WIDTH * 1;
	crabs[1].arrX = pc.arrX - 2;
	crabs[1].arrY = pc.arrY + 1;

	crabs[2].posX = pc.posX - CELL_WIDTH * 5;
	crabs[2].posY = pc.posY + CELL_WIDTH * 2;
	crabs[2].arrX = pc.arrX - 5;
	crabs[2].arrY = pc.arrY + 2;

	crabs[3].posX = pc.posX - CELL_WIDTH * 4;
	crabs[3].posY = pc.posY + CELL_WIDTH * 2;
	crabs[3].arrX = pc.arrX - 4;
	crabs[3].arrY = pc.arrY + 2;

	crabs[4].posX = pc.posX - CELL_WIDTH * 3;
	crabs[4].posY = pc.posY + CELL_WIDTH * 2;
	crabs[4].arrX = pc.arrX - 3;
	crabs[4].arrY = pc.arrY + 2;

	crabs[5].posX = pc.posX - CELL_WIDTH * 2;
	crabs[5].posY = pc.posY + CELL_WIDTH * 2;
	crabs[5].arrX = pc.arrX - 2;
	crabs[5].arrY = pc.arrY + 2;


	// �ڹ���
	door.posX = pc.posX - CELL_WIDTH * 1;
	door.posY = pc.posY - CELL_WIDTH * 3;
	door.arrX = pc.arrX - 1;
	door.arrY = pc.arrY - 3;


	// Ű
	key.posX = pc.posX - CELL_WIDTH * 4;
	key.posY = pc.posY - CELL_WIDTH * 2;
	key.arrX = pc.arrX - 4;
	key.arrY = pc.arrY - 2;




	walkCnt = 33;
	walkForcrab = 0;
	key_flag = 0;
	shield_flag = 0;
}

void stage7() {

	curStage = 7;
	stage7_initPos();
	crabUpDown();

	while (1) {
		SDL_RenderClear(renderer);


		if (processKeyInput() == -1) { // RŰ ������ �����
			stage7_initPos();
			crabUpDown();
		}

		drawStage(0, -1);

		SDL_RenderPresent(renderer);


		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}

		if (walkCnt <= 0) {
			pc_melting();
			gameOver();
			crabUpDown();
			stage7_initPos();

		}
	}
}