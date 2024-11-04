#pragma once
#include <raylib.h>

#include "Collider.hpp"

struct Collision {
	Vector2 point;
	Vector2 normal;
	float time;
};
