#include "MyEngineSystem.h"

MyEngine::MyEngine() {

}

MyEngine::MyEngine(int start_x, int start_y, int npc_width, int npc_height) {

	width = npc_width;
	height = npc_height;
	x = start_x;
	y = start_y;

};

void MyEngine::movement(int target_x, int target_y) {

	if (x < target_x)
		x++;
	else if (x > target_x)
		x--;

	if (y < target_y)
		y++;
	else if (y > target_y)
		y--;

	if (x == target_x && y == target_y)
		reachedTarget = true;
	else
		reachedTarget = false;

}