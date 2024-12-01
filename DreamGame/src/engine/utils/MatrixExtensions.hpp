#pragma once
#include <ostream>
#include <raylib.h>

inline std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs) {
	lhs << "[" << rhs.m0 << ", " << rhs.m1 << ", " << rhs.m2 << ", " << rhs.m3 << "]\n";
	lhs << "[" << rhs.m4 << ", " << rhs.m5 << ", " << rhs.m6 << ", " << rhs.m7 << "]\n";
	lhs << "[" << rhs.m8 << ", " << rhs.m9 << ", " << rhs.m10 << ", " << rhs.m11 << "]\n";
	lhs << "[" << rhs.m12 << ", " << rhs.m13 << ", " << rhs.m14 << ", " << rhs.m15 << "]\n";
	return lhs;
	
}
