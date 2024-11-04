#pragma once

#include <raylib.h>
#include <stdexcept>

#include "raymath.h"
#include "objects/GameObject.hpp"

class Collider {
	public:
		enum class Type {
			Rectangle,
			Circle,
		};

	private:
		GameObject& owner;
		const Type type;

	public:
		explicit Collider(GameObject& gameObject, float radius);
		explicit Collider(GameObject& gameObject, const Vector2& size);

		[[nodiscard]] const Type& Type() const;

		float width{};
		float height{};
		float radius{};
		[[nodiscard]] GameObject& Owner() const;

		void DebugRender(const Color& color) const;

	private:
		static bool RectRectOverlaps(const Collider& first, const Collider& second);

		static bool CircleCircleOverlaps(const Collider& first, const Collider& second);

		static bool CircleRectOverlaps(const Collider& circle, const Collider& rect);

	public:
		static bool Overlaps(const Collider& first, const Collider& second);
};
