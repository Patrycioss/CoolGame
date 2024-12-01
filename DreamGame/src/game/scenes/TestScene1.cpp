#include "TestScene1.hpp"

TestScene1::TestScene1(const std::string& name)
	: Scene(name),
	  texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())) {
	player1 = Add<Player>("Player1", Vector2{100, 100}, 0, WHITE);
	player2 = Add<Player>("Player2", Vector2{200, 100}, 3, GREEN);
	player3 = Add<Player>("Player3", Vector2{100, 200}, 1, BLUE);
	player4 = Add<Player>("Player4", Vector2{200, 200}, 2, RED);
}

void TestScene1::Start() {
}

void TestScene1::Update() {
}

void TestScene1::Render() {
	DrawText("Scene 1!", 100, 20, 20, WHITE);
}

void TestScene1::Stop() {
}
