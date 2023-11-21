#pragma once


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

SDL_Event event;
void processKeyInput() {
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
			case 1073741903: // right
				if (collision_pc_map(1, 0)) break;
				if (collision_pc_rock(1, 0)) break;
				walkCnt--;
				pc.posX += CELL_WIDTH;
				pc.arrX++;
				break;
			case 1073741904: // left
				if (collision_pc_map(-1, 0)) break;
				if (collision_pc_rock(-1, 0)) break;
				walkCnt--;
				pc.posX -= CELL_WIDTH;
				pc.arrX--;
				break;
			case 1073741905: // down
				if (collision_pc_map(0, 1)) break;
				if (collision_pc_rock(0, 1)) break;
				walkCnt--;
				pc.posY += CELL_WIDTH;
				pc.arrY++;
				break;
			case 1073741906: // up
				if (collision_pc_map(0, -1)) break;
				if (collision_pc_rock(0, -1)) break;
				walkCnt--;
				pc.posY -= CELL_WIDTH;
				pc.arrY--;
				break;
			case 27: // ESC
				quit = true;
				break;
			}

	}
}


