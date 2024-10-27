#include "Game.hpp"
#include "Player.hpp"

#include <string>

std::once_flag Game::initInstanceFlag;
Game* Game::instance;

Game::Game()
	: texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())) {
}

Game::~Game() {
	delete instance;
}

void Game::Update() {
	BeginDrawing();
	DrawTexture(texture, 0, 0,WHITE);
	ClearBackground(RED);
	EndDrawing();
}

Game& Game::Instance() {
	std::call_once(initInstanceFlag, InitGame);
	return *instance;
}

void Game::InitGame() {
	instance = new Game();
}
