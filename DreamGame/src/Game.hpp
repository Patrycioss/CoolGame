﻿#pragma once
#include <memory>
#include <mutex>
#include <raylib.h>
#include <vector>

#include "GameObject.hpp"
#include "SceneManager.hpp"

class Game {
	private:
		static std::once_flag initInstanceFlag;
		static Game* instance;

		Texture texture;
		// SceneManager sceneManager;

		std::vector<std::unique_ptr<GameObject>> gameObjects;

		Game();
		~Game();
		static void InitGame();

	public:
		Game(Game const&) = delete;
		void operator=(Game const&) = delete;

		void Update();

		static Game& Instance();
};
