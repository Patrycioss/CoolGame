#pragma once
#include <algorithm>
#include <memory>
#include <vector>

#include "../Object.hpp"
#include "../utils/Concepts.hpp"

class ObjectManager {
	private:
		std::vector<std::unique_ptr<Object>> objects;
		std::vector<Object*> depthSorted;

	public:
		template<Concepts::Derived<Object> T, typename... Args>
		T* Add(Args... args) {
			objects.push_back(std::unique_ptr<T>(new T(std::move(args)...)));
			T* ptr = static_cast<T*>(objects.back().get());
			ptr->InternalSetManager(this);
			depthSorted.push_back(ptr);
			return ptr;
		}


		void Sort();
		void Update();
		void Render();
		bool Remove(const Object* object);
};
