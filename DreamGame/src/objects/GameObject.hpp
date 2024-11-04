#pragma once
#include <raylib.h>
#include "../Collider.hpp"

class GameObject {
	private:
		Collider collider;

	
	public:
		Vector2 position;
		Vector2 scale;
		float rotation;

		virtual ~GameObject() = default;
		explicit GameObject(const Vector2& position);
		virtual void Update();
		virtual void Render();

		const Collider& Collider() const;
};
