#include "Game.hpp"
#include <string>

#include "scenes/TestScene1.hpp"
#include "scenes/TestScene2.hpp"
#include "utils/Vector2Extensions.hpp"

#include "objects/Player.hpp"

std::once_flag Game::initInstanceFlag;
Game* Game::instance;

Game::Game()
	: window({1000, 800}, false) {
	window.Start();
	renderTexture = LoadRenderTexture(window.Resolution().x, window.Resolution().y);
	InitAudioDevice();

	sceneManager.AddScene<TestScene1>("TestScene1");
	sceneManager.AddScene<TestScene2>("TestScene2");

	sceneManager.SetScene("TestScene1");
}

Game::~Game() {
	CloseAudioDevice();
	CloseWindow();
	delete instance;
}

void Game::Update() {
	// counter++;
	//
	// if (counter > 100) {
	// 	counter = 0;
	//
	// 	if (sceneManager.ActiveScene()->Name() == "TestScene1") {
	// 		sceneManager.SetScene("TestScene2");
	// 	} else {
	// 		sceneManager.SetScene("TestScene1");
	// 	}
	// }

	sceneManager.Update();

	ClearBackground(WHITE);
	BeginTextureMode(renderTexture);
	BeginDrawing();

	ClearBackground(RED);
	BeginMode2D(camera);

	// DrawTexture(texture, 0, 0,WHITE);

	sceneManager.Render();

	Logger::Print();

	EndMode2D();
	EndTextureMode();

	const Vector2 windowSize(GetScreenWidth(), GetScreenHeight());
	const float scale = std::min(windowSize.x / window.Resolution().x, windowSize.y / window.Resolution().y);

	Vector2 texturePosition = windowSize / 2.0f;
	Vector2 textureSize = windowSize * scale;
	texturePosition -= textureSize / 2.0f;

	DrawTexturePro(renderTexture.texture,
	               {0, 0, (float)renderTexture.texture.width, (float)-renderTexture.texture.height},
	               {texturePosition.x, texturePosition.y, textureSize.x, textureSize.y},
	               {0, 0},
	               0,
	               WHITE);

	EndDrawing();
}

Game& Game::Instance() {
	std::call_once(initInstanceFlag, InitGame);
	return *instance;
}

void Game::InitGame() {
	instance = new Game();
}
