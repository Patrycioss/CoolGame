#include "Game.hpp"
#include <string>

#include "scenes/TestScene1.hpp"
#include "scenes/TestScene2.hpp"

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

	std::srand(std::time(nullptr));

	player1 = objectManager.Add<Player>(Vector2{100, 100}, std::rand(), WHITE);
	player2 = objectManager.Add<Player>(Vector2{200, 100}, std::rand(), GREEN);
	player3 = objectManager.Add<Player>(Vector2{100, 200}, std::rand(), BLUE);
	player4 = objectManager.Add<Player>(Vector2{200, 200}, std::rand(), RED);

	printf("%i, %i, %i, %i", player1->GetPriority(), player2->GetPriority(), player3->GetPriority(), player4->GetPriority());

	objectManager.Sort();

	// sceneManager.AddScene<TestScene1>("TestScene1");
	// sceneManager.AddScene<TestScene2>("TestScene2");

	// sceneManager.SetScene("TestScene1");
}

Game::~Game() {
	UnloadRenderTexture(renderTexture);
	CloseAudioDevice();
	CloseWindow();
}

void Game::Update() {
	counter++;

	if (counter > 100) {
		counter = 0;

		// player1->SetPriority(std::rand());
		// player2->SetPriority(std::rand());
		// player3->SetPriority(std::rand());
		// player4->SetPriority(std::rand());

		// if (player1->GetPriority() == 0) {
		// 	player1->SetPriority(1000);
		// 	player2->SetPriority(0);
		// }
		// else {
		// 	player1->SetPriority(0);
		// 	player2->SetPriority(1000);
		// }

		objectManager.Sort();

		// if (sceneManager.ActiveScene()->Name() == "TestScene1") {
		// 	sceneManager.SetScene("TestScene2");
		// } else {
		// 	sceneManager.SetScene("TestScene1");
		// }
	}

	window.Update();
	objectManager.Update();
	// sceneManager.Update();

	ClearBackground(WHITE);
	BeginTextureMode(renderTexture);
	BeginDrawing();

	ClearBackground(RED);
	camera.Begin();

	// Rendering
	// sceneManager.Render();
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
