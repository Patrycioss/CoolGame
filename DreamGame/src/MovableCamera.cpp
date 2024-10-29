#include "MovableCamera.hpp"

MovableCamera::MovableCamera(const Vector2& offset, const Vector2& target, const float rotation, const float zoom)
	: camera(offset, target, rotation, zoom) {
}

void MovableCamera::SetTarget(const Vector2& target) {
	camera.target = target;
}

void MovableCamera::Begin() const {
	BeginMode2D(camera);
}

void MovableCamera::End() const {
	EndMode2D();
}