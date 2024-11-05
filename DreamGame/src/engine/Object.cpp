#include "Object.hpp"

unsigned int Object::lastID = 0;

void Object::InternalUpdate() {
	Update();
}

void Object::InternalRender() {
	Render();
}

Object::Object(const Vector2& position, const int priority)
	: collider(*this, Vector2{0, 0}),
	  ID(lastID),
	  priority(priority),
	  position(position),
	  scale(1.0f), rotation(0) {
	lastID++;
}

void Object::Update() {
}

void Object::Render() {
}

const Collider& Object::Collider() const {
	return collider;
}

unsigned int Object::GetID() const {
	return ID;
}

int Object::GetPriority() const {
	return priority;
}

void Object::SetPriority(const int priority) {
	this->priority = priority;
}
