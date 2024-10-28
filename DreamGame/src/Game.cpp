#include "Game.hpp"
#include <string>

#include "scenes/TestScene1.hpp"
#include "scenes/TestScene2.hpp"

#include "objects/Player.hpp"

std::once_flag Game::initInstanceFlag;
Game* Game::instance;

Game::Game()
	: texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())) {
	sceneManager.AddScene<TestScene1>("TestScene1");
	sceneManager.AddScene<TestScene2>("TestScene2");

	sceneManager.SetScene("TestScene1");
}

Game::~Game() {
	delete instance;
}

void Game::Update() {
	counter++;

	if (counter > 100) {
		counter = 0;

		if (sceneManager.ActiveScene()->Name() == "TestScene1") {
			sceneManager.SetScene("TestScene2");
		} else {
			sceneManager.SetScene("TestScene1");
		}
	}

	sceneManager.Update();

	BeginDrawing();
	DrawTexture(texture, 0, 0,WHITE);
	ClearBackground(RED);

	sceneManager.Render();

	Logger::Print();

	EndDrawing();
}

Game& Game::Instance() {
	std::call_once(initInstanceFlag, InitGame);
	return *instance;
}

void Game::InitGame() {
	instance = new Game();
}
