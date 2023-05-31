#include "MyGame.h"

MyGame::MyGame() : AbstractGame(), score(0), lives(3), numKeys(8), gameWon(false), box(5, 5, 30, 30) {
	TTF_Font * font = ResourceManager::loadFont("res/fonts/arial.ttf", 72);
	gfx->useFont(font);
	gfx->setVerticalSync(true);

    for (int i = 0; i < numKeys; i++) {
        std::shared_ptr<GameKey> k = std::make_shared<GameKey>();
        k->isAlive = true;
        k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
        gameKeys.push_back(k);
    }
	
	npc->x = getRandom(0, 750);
	npc->y = getRandom(0, 550);
	npc->width = 20;
	npc->height = 20;
	npc->tarX = getRandom(500, 750);
	npc->tarY = getRandom(450, 550);

	enemy->x = getRandom(0, 750);
	enemy->y = getRandom(0, 750);
	enemy->width = 30;
	enemy->height = 30;
}

MyGame::~MyGame() {

}

void MyGame::handleKeyEvents() {
	int speed = 3;

	if (eventSystem->isPressed(Key::W)) {
		velocity.y = -speed;
	}

	if (eventSystem->isPressed(Key::S)) {
		velocity.y = speed;
	}

	if (eventSystem->isPressed(Key::A)) {
		velocity.x = -speed;
	}

	if (eventSystem->isPressed(Key::D)) {
		velocity.x = speed;
	}
}

void MyGame::update() {
	box.x += velocity.x;
	box.y += velocity.y;

	for (auto key : gameKeys) {
		if (key->isAlive && box.contains(key->pos)) {
			score += 200;
			key->isAlive = false;
			numKeys--;
		}
	}

	velocity.x = 0;
    velocity.y = 0;

	if (numKeys == 0) {
		gameWon = true;
	}

	if (npc->reachedTarget)
	{
		npc->tarX = getRandom(500, 750);
		npc->tarY = getRandom(450, 550);
		std::cout << "\nTarget reached - Jess_Romer-Lee-CI517-2022";
	};

	if (enemy->reachedTarget)
		std::cout << "\nEnemy Encountered";


	npc->movement(npc->tarX, npc->tarY);
	enemy->movement(box.x, box.y);
}

void MyGame::render() {
	gfx->setDrawColor(SDL_COLOR_WHITE);
	gfx->drawRect(box);

	gfx->setDrawColor(SDL_COLOR_BLUE);
	for (auto key : gameKeys)
        if (key->isAlive)
		    gfx->drawCircle(key->pos, 5);

	gfx->setDrawColor(SDL_COLOR_GREEN);
	gfx->drawRect(npc->x, npc->y, npc->width, npc->height);

	gfx->setDrawColor(SDL_COLOR_RED);
	gfx->drawRect(enemy->x, enemy->y, enemy->width, enemy->height);

}

void MyGame::renderUI() {
	gfx->setDrawColor(SDL_COLOR_PINK);
	std::string scoreStr = std::to_string(score);
	gfx->drawText(scoreStr, 780 - scoreStr.length() * 50, 25);

	if (gameWon)
		gfx->drawText("YOU WIN!", 250, 500);
}