#include "Game.hpp"
#include <string>

#include "objects/Player.hpp"

Game* Game::instance;

Game::Game()
	: window({1280, 720}, false),
	  renderTexture(LoadRenderTexture(static_cast<int>(window.Resolution().x), static_cast<int>(window.Resolution().y))),
	  camera(
		  {window.Resolution().x / 2.0f, window.Resolution().y / 2.0f},
		  {window.Size().x / 2.0f, window.Size().y / 2.0f},
		  0,
		  1) {
	instance = this;

	InitAudioDevice();

	player1 = objectManager.Add<Player>(Vector2{100, 100}, 0, WHITE);
	player2 = objectManager.Add<Player>(Vector2{200, 100}, 3, GREEN);
	player3 = objectManager.Add<Player>(Vector2{100, 200}, 1, BLUE);
	player4 = objectManager.Add<Player>(Vector2{200, 200}, 2, RED);

	objectManager.Sort();
}

Game::~Game() {
	UnloadRenderTexture(renderTexture);
	CloseAudioDevice();
	CloseWindow();
}

void Game::Update() {
	window.Update();
	objectManager.Update();

	ClearBackground(WHITE);
	BeginTextureMode(renderTexture);
	BeginDrawing();

	ClearBackground(RED);
	camera.Begin();

	// Rendering
	objectManager.Render();

	camera.End();
	EndTextureMode();

	const Vector2 size = window.Size();
	const Vector2 resolution = window.Resolution();
	const float scale = std::min(size.x / resolution.x, size.y / resolution.y);

	Vector2 texturePosition = Vector2{size.x / 2.0f, size.y / 2.0f};
	const Vector2 textureSize = Vector2{size.x * scale, size.y * scale};
	texturePosition = Vector2{texturePosition.x - textureSize.x / 2.0f, texturePosition.y - textureSize.y / 2.0f};

	DrawTexturePro(renderTexture.texture,
	               {0, 0, static_cast<float>(renderTexture.texture.width), static_cast<float>(-renderTexture.texture.height)},
	               {texturePosition.x, texturePosition.y, textureSize.x, textureSize.y},
	               {0, 0},
	               0,
	               WHITE);

	EndDrawing();

	Logger::Print();
}

Game& Game::Instance() {
	return *instance;
}
