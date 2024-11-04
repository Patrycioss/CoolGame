#include "Collider.hpp"

Collider::Collider(const GameObject* gameObject, const float radius): gameObject(gameObject), type(Type::Circle), radius(radius) {
}

Collider::Collider(const GameObject* gameObject, const Vector2& size): gameObject(gameObject), type(Type::Rectangle), size(size) {
}
