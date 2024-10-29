#pragma once
#include <memory>
#include <mutex>
#include <raylib.h>
#include <vector>

#include "Window.hpp"
#include "objects/GameObject.hpp"
#include "scenes/SceneManager.hpp"

class Game {
	private:
		static std::once_flag initInstanceFlag;
		static Game* instance;

		int counter = 0;

		Texture texture;
		SceneManager sceneManager;

		std::vector<std::unique_ptr<GameObject>> gameObjects;

		Window window;
		RenderTexture2D renderTexture;
		Camera2D camera;

		Game();
		~Game();
		static void InitGame();

	public:
		Game(Game const&) = delete;
		void operator=(Game const&) = delete;

		void Update();
		void Render();

		static Game& Instance();
};
