#pragma once
#include <memory>
#include <raylib.h>
#include <vector>

#include "../engine/Engine.hpp"
#include "objects/Player.hpp"

class Game {
	private:
		static Game* instance;

		SceneManager sceneManager;

		std::vector<std::unique_ptr<Object>> gameObjects;

		Window window;
		RenderTexture2D renderTexture;
		MovableCamera camera;

		
	public:
		bool enableDebugging = true;

		Game();
		~Game();
		Game(Game const&) = delete;
		void operator=(Game const&) = delete;

		void Update();

		static Game& Instance();
};
