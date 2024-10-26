#include "Game.hpp"

#include <raylib.h>
#include <string>

Game::Game() {
	const std::string path = std::string(RESOURCES) + "/textures/awesomeface.png";
	texture = LoadTexture(path.c_str());
}

void Game::Update() {

	BeginDrawing();
	DrawTexture(texture, 0,0,WHITE);
	ClearBackground(RED);
	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}