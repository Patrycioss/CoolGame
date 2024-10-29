#pragma once

#include <raylib.h>

inline Vector2 operator/(const Vector2& value, const float divisor) {
	return Vector2{ value.x / divisor, value.y / divisor };
}

inline Vector2 operator*(const Vector2& value, const float multiplier) {
	return Vector2{ value.x * multiplier, value.y * multiplier };
}

inline Vector2 operator-=(const Vector2& left, const Vector2& right) {
	return Vector2{ left.x - right.x, left.y - right.y };
}