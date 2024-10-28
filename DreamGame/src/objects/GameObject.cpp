#include "GameObject.hpp"

GameObject::GameObject(const Vector2& position)
	: transform(position) {
}

void GameObject::Update() {
}

void GameObject::Render() {
}

Vector2& GameObject::position(const Vector2& newValue) {
	transform.position = newValue;
	return transform.position;
}

Vector2& GameObject::position() {
	return transform.position;
}

Vector2& GameObject::scale(const Vector2& newValue) {
	transform.scale = newValue;
	return transform.scale;
}

Vector2& GameObject::scale() {
	return transform.scale;
}

float& GameObject::rotation(const float& newValue) {
	transform.rotation = newValue;
	return transform.rotation;
}

float& GameObject::rotation() {
	return transform.rotation;
}