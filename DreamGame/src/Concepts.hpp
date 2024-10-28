#pragma once

namespace Concepts
{
	template<class T, class U>
	concept Derived = std::is_base_of_v<U, T>;
}
