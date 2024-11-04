#pragma once

#include "objects/GameObject.hpp"

class Collider {
	public:
		enum class Type {
			Rectangle,
			Circle,
		};

	private:
		const GameObject* gameObject;
		const Type type;

		Vector2 size{};
		float radius{};

	public:
		explicit Collider(const GameObject* gameObject, float radius);
		explicit Collider(const GameObject* gameObject, const Vector2& size);
};
