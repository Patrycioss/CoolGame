﻿#pragma once
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

#include "../GameObject.hpp"
#include "../utils/Concepts.hpp"

class ObjectManager {
	private:
		std::unordered_map<unsigned int, std::unique_ptr<GameObject>> objectMap;
		std::vector<GameObject*> sorted;

	public:
		template<Concepts::Derived<GameObject> T, typename... Args>
		T* Add(Args... args) {
			auto a = std::unique_ptr<T>(new T(std::move(args)...));
			auto pair = objectMap.emplace(a->GetID(), std::move(a));
			T* ptr = static_cast<T*>(pair.first->second.get());
			sorted.push_back(ptr);
			return ptr;
		}

		template<Concepts::Derived<GameObject> T>
		T* Get(const unsigned int ID) {
			if (!objectMap.contains(ID)) {
				return nullptr;
			}
			return static_cast<T*>(objectMap[ID].get());
		}

		void Sort();
		void Update();
		void Render();
};