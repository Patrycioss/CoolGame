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
		GameObject& gameObject;
		const Type type;

	public:
		explicit Collider(GameObject& gameObject, float radius);
		explicit Collider(GameObject& gameObject, const Vector2& size);

		[[nodiscard]] const Type& Type() const;

		float width;
		float height;
		float radius{};
		[[nodiscard]] GameObject& Owner() const;

	private:
		static bool RectRectOverlaps(const Collider& first, const Collider& second) {
			return second.Owner().position.x < first.Owner().position.x + first.width &&
				second.Owner().position.y + second.width >
				first.Owner().position.x &&
				second.Owner().position.y < first.Owner().position.y + first.height &&
				second.Owner().position.y + second.height >
				first.Owner().position.y;
		}

		static bool CircleCircleOverlaps(const Collider& first, const Collider& second) {
			return Vector2Distance(first.Owner().position, second.Owner().position) > first.radius + second.radius;
		}

		static bool CircleRectOverlaps(const Collider& circle, const Collider& rect) {
			const auto [circleX, circleY] = circle.Owner().position;
			const auto [rectX, rectY] = rect.Owner().position;

			float testX = circleX;
			float testY = circleY;

			if (circleX < rectX) testX = rectX; // left edge
			else if (circleX > rectX + rect.width) testX = rectX + rect.width; // right edge

			if (circleY < rectY) testY = rectY; // top edge
			else if (circleY > rectY + rect.height) testY = rectY + rect.height; // bottom edge

			float distX = circleX - testX;
			float distY = circleY - testY;
			float sqDistance = (distX * distX) + (distY * distY);

			return sqDistance <= (circle.radius * circle.radius);
		}

	public:
		static bool Overlaps(const Collider& first, const Collider& second) {
			if (first.Type() == Type::Rectangle && second.Type() == Type::Rectangle) {
				return RectRectOverlaps(first, second);
			}

			if (first.Type() == Type::Circle && second.Type() == Type::Circle) {
				return CircleCircleOverlaps(first, second);
			}

			if (first.Type() == Type::Circle && second.Type() == Type::Rectangle) return CircleRectOverlaps(first, second);
			if (first.Type() == Type::Rectangle && second.Type() == Type::Circle) return CircleRectOverlaps(second, first);

			throw std::runtime_error("Failed to implement collision between certain types?");
		}
};