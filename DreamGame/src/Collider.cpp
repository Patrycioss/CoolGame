#include "Collider.hpp"

Collider::Collider(GameObject& gameObject, const float radius): gameObject(gameObject), type(Type::Circle), radius(radius) {
}

Collider::Collider(GameObject& gameObject, const Vector2& size): gameObject(gameObject), type(Type::Rectangle), width(size.x), height(size.y) {
}

const enum Collider::Type& Collider::Type() const {
	return type;
}

GameObject& Collider::Owner() const{
	return gameObject;
}
