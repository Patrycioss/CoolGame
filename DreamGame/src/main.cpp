#include <raylib.h>

#include "game/Game.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>

static void Update() {
	Game::Instance().Update();
}

#endif

constexpr int TARGET_FPS = 60;

int main() {

	Game game;
	
#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(Update, TARGET_FPS, true);
#else

	SetTargetFPS(TARGET_FPS);
	
	while (!WindowShouldClose()) {
		game.Update();
	}
#endif

	return 0;
}