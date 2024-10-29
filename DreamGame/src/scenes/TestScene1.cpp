#include "TestScene1.hpp"

#include "raylib.h"

TestScene1::TestScene1(const std::string& name)
	: Scene(name),
	  texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())) {
}

void TestScene1::Start() {
}

void TestScene1::Update() {
}

void TestScene1::Render() {
	DrawText("Scene 1!", 100, 20, 20, WHITE);
	DrawTexture(texture,20,20,WHITE);
}

void TestScene1::Stop() {
}
