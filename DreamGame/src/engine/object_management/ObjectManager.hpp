#pragma once
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

#include "../Object.hpp"
#include "../utils/Concepts.hpp"

class ObjectManager {
	private:
		std::unordered_map<unsigned int, std::unique_ptr<Object>> objectMap;
		std::vector<Object*> sorted;

	public:
		template<Concepts::Derived<Object> T, typename... Args>
		T* Add(Args... args) {
			auto a = std::unique_ptr<T>(new T(std::move(args)...));
			auto pair = objectMap.emplace(a->GetID(), std::move(a));
			T* ptr = static_cast<T*>(pair.first->second.get());
			ptr->InternalSetManager(this);
			sorted.push_back(ptr);
			return ptr;
		}

		template<Concepts::Derived<Object> T>
		T* Get(const unsigned int ID) {
			if (!objectMap.contains(ID)) {
				return nullptr;
			}
			return static_cast<T*>(objectMap[ID].get());
		}

		Object* Get(const unsigned int ID) {
			if (!objectMap.contains(ID)) {
				return nullptr;
			}
			return objectMap[ID].get();
		}

		bool Remove(unsigned ID);

		void Sort();
		void Update();
		void Render();
};
