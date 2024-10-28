#include "TestScene2.hpp"

#include "raylib.h"

void TestScene2::Start() {
	EnableLogging(true);
}

void TestScene2::Update() {
	DrawText("Scene 2!", 100, 20, 20, WHITE);
};

void TestScene2::Stop() {
};
