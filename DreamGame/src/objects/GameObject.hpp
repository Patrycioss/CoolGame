#pragma once
#include <raylib.h>

class GameObject {
	public:
		Vector2 position;
		Vector2 scale;
		float rotation;

		virtual ~GameObject() = default;
		explicit GameObject(const Vector2& position);
		virtual void Update();
		virtual void Render();
};
