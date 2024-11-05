#include "Collider.hpp"

#include "Object.hpp"

Collider::Collider(Object& gameObject, const float radius): owner(gameObject), type(Type::Circle), radius(radius) {
}

Collider::Collider(Object& gameObject, const Vector2& size): owner(gameObject), type(Type::Rectangle), width(size.x), height(size.y) {
}

const enum Collider::Type& Collider::Type() const {
	return type;
}

Object& Collider::Owner() const {
	return owner;
}

void Collider::DebugRender(const Color& color) const {
	const auto [x, y] = owner.position;

	if (type == Type::Rectangle) {
		DrawRectangle((int)x, (int)y, (int)width, (int)height, color);
	} else if (type == Type::Circle) {
		DrawCircle((int)x, (int)y, radius, color);
	}
}

bool Collider::RectRectOverlaps(const Collider& first, const Collider& second) {
	return second.Owner().position.x < first.Owner().position.x + first.width &&
		second.Owner().position.y + second.width >
		first.Owner().position.x &&
		second.Owner().position.y < first.Owner().position.y + first.height &&
		second.Owner().position.y + second.height >
		first.Owner().position.y;
}

bool Collider::CircleCircleOverlaps(const Collider& first, const Collider& second) {
	return Vector2Distance(first.Owner().position, second.Owner().position) > first.radius + second.radius;
}

bool Collider::CircleRectOverlaps(const Collider& circle, const Collider& rect) {
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

bool Collider::Overlaps(const Collider& first, const Collider& second) {
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
