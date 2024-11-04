#include "GameObject.hpp"

GameObject::GameObject(const Vector2& position)
	: collider(*this, Vector2{0, 0}),
	  position(position),
	  scale(1.0f),
	  rotation(0) {
}

void GameObject::Update() {
}

void GameObject::Render() {
}
