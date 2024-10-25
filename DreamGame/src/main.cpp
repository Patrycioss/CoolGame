#include <iostream>

// #define RESOURCES

#include <filesystem>

#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

static Texture2D texture;

static void UpdateDrawFrame() {
	BeginDrawing();
	DrawTexture(texture, 0,0,WHITE);
	ClearBackground(RED);
	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}

constexpr int TARGET_FPS = 60;


int main() {
	
	InitWindow(800, 450, "raylib [core] example - basic window");
	InitAudioDevice();

	std::string path = std::string(RESOURCES) + "/textures/awesomeface.png";
	texture = LoadTexture(path.c_str());

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame,TARGET_FPS,1);
#else

	SetTargetFPS(TARGET_FPS);
	
	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}
#endif

	CloseAudioDevice();
	CloseWindow();

	return 0;
}
