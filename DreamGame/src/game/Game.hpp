#pragma once
#include <memory>
#include <raylib.h>
#include <vector>

#include "../engine/Engine.hpp"
#include "objects/Player.hpp"

class Game {
	private:
		static Game* instance;

		int counter = 0;

		SceneManager sceneManager;
		ObjectManager objectManager;

		std::vector<std::unique_ptr<Object>> gameObjects;

		Window window;
		RenderTexture2D renderTexture;
		MovableCamera camera;

		Player* player1 = nullptr;
		Player* player2 = nullptr;
		Player* player3 = nullptr;
		Player* player4 = nullptr;

	public:
		bool enableDebugging = true;

	
		Game();
		~Game();
		Game(Game const&) = delete;
		void operator=(Game const&) = delete;

		void Update();

		static Game& Instance();
};
