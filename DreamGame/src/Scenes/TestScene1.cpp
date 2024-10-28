﻿#include "TestScene1.hpp"

#include "raylib.h"

void TestScene1::Start() {
	EnableLogging(true);
}

void TestScene1::Update() {
	DrawText("Scene 1!", 100, 20, 20, WHITE);
}

void TestScene1::Stop() {
}
