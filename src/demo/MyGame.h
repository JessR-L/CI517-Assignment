#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

#include "../engine/AbstractGame.h"


struct GameKey {
	Point2 pos;
	bool isAlive;
};

class MyGame : public AbstractGame {
	private:
		Rect box;

		Vector2i velocity;

		std::vector<std::shared_ptr<GameKey>> gameKeys;

		MyEngine* npc = new MyEngine(500, 500, 30, 30);
		MyEngine* enemy = new MyEngine(300, 300, 50, 50);


		/* GAMEPLAY */
		int score, numKeys, lives;
		bool gameWon;
		

		void handleKeyEvents();
		void update();
		void render();
		void renderUI();
		
	public:
        MyGame();
		~MyGame();
};

#endif