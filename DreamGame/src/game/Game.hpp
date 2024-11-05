#pragma once
#include <raylib.h>

#include "../engine/object_management/Scene.hpp"
#include "../engine/Engine.hpp"

class Game {
	private:
		static Game* instance;

		SceneManager sceneManager;
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
