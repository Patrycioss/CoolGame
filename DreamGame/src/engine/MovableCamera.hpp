#pragma once

#include <raylib.h>

class MovableCamera {
	private:
		Camera2D camera;

	public:
		MovableCamera(const Vector2& offset, const Vector2& target, float rotation, float zoom);

		void SetTarget(const Vector2& target);

		void Begin() const;

		void End() const;
};
