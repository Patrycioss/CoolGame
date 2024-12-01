#include "TestScene2.hpp"

#include "../objects/Player.hpp"

#include "../objects/TestChild.hpp"

TestScene2::TestScene2(const std::string& name)
	: Scene(name) {
	Player* player = Add<Player>("Player",Vector2{200, 200}, 10, WHITE);
	TestChild* child = Add<TestChild>("TestChild",Vector2{0,0}, 20, RED);

	player->AddChild(child);
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
