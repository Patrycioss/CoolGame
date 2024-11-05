#pragma once

#include <raylib.h>
#include <stdexcept>

#include "raymath.h"

class Object;

class Collider {
	public:
		enum class Type {
			Rectangle,
			Circle,
		};

	private:
		Object& owner;
		const Type type;

	public:
		explicit Collider(Object& gameObject, float radius);
		explicit Collider(Object& gameObject, const Vector2& size);

		[[nodiscard]] const Type& Type() const;

		float width{};
		float height{};
		float radius{};
		[[nodiscard]] Object& Owner() const;

		void DebugRender(const Color& color) const;

	private:
		static bool RectRectOverlaps(const Collider& first, const Collider& second);

		static bool CircleCircleOverlaps(const Collider& first, const Collider& second);

		static bool CircleRectOverlaps(const Collider& circle, const Collider& rect);

	public:
		static bool Overlaps(const Collider& first, const Collider& second);
};
