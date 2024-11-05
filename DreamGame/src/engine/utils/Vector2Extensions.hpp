#pragma once

#include <raylib.h>

inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator*(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline Vector2 operator*(const float lhs, const Vector2& rhs) {
	return Vector2(lhs * rhs.x, lhs * rhs.y);
}

inline Vector2 operator*(const Vector2& lhs, const float rhs) {
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

inline Vector2 operator/(const Vector2& lhs, const float rhs) {
	return Vector2(lhs.x / rhs, lhs.y / rhs);
}