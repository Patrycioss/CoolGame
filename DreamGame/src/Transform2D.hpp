#pragma once
#include <raylib.h>

struct Transform2D {
	public:
		Vector2 position;
		Vector2 scale;
		float rotation;

		explicit Transform2D(const Vector2& position)
			: position(position), scale(1.0f, 1.0f), rotation(0.0f) {
		};

		explicit Transform2D(const Vector2& position, const Vector2& scale, const float& rotation = 0.0f)
			: position(position), scale(scale), rotation(rotation) {
		}
};