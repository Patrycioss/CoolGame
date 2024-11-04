#include "GameObject.hpp"

unsigned int GameObject::lastID = 0;

void GameObject::InternalUpdate() {
	Update();
}

void GameObject::InternalRender() {
	Render();
}

GameObject::GameObject(const Vector2& position, const int priority)
	: collider(*this, Vector2{0, 0}),
	  ID(lastID),
	  priority(priority),
	  position(position),
	  scale(1.0f), rotation(0) {
	lastID++;
}

void GameObject::Update() {
}

void GameObject::Render() {
}

const Collider& GameObject::Collider() const {
	return collider;
}

unsigned int GameObject::GetID() const {
	return ID;
}

int GameObject::GetPriority() const {
	return priority;
}
