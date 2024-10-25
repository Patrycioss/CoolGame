#include <raylib.h>

#include "Game.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>

// Static function for emscripten that expects a c-function.
static Game* gamePtr;

static void Update() {
	gamePtr->Update();
}

#endif

constexpr int TARGET_FPS = 60;

int main() {
	InitWindow(1000, 800, "DreamGame");
	InitAudioDevice();

	Game game;

#if defined(PLATFORM_WEB)
	gamePtr = &game;
	emscripten_set_main_loop(Update, TARGET_FPS, 1);
#else

	SetTargetFPS(TARGET_FPS);

	while (!WindowShouldClose()) {
		game.Update();
	}
#endif

	CloseAudioDevice();
	CloseWindow();

	return 0;
}
