#include "TestScene2.hpp"

#include "../objects/Player.hpp"

TestScene2::TestScene2(const std::string& name)
	: Scene(name) {
	Add<Player>(Vector2{200, 200}, 10, WHITE);
}

void TestScene2::Start() {
}

void TestScene2::Update() {
};

void TestScene2::Render() {
	DrawText("Scene 2!", 100, 20, 20, WHITE);
}

void TestScene2::Stop() {
};
