#pragma once
#include "Transform2D.hpp"

class GameObject {
	private:
		Transform2D transform;

	public:
		virtual ~GameObject() = default;
		explicit GameObject(const Vector2& position);
		virtual void Update();
		virtual void Render();

		Vector2& position(const Vector2& newValue);
		Vector2& position();

		Vector2& scale(const Vector2& newValue);
		Vector2& scale();

		float& rotation(const float& newValue);
		float& rotation();
};
