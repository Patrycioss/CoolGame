#include "ObjectManager.hpp"

#include "raymath.h"
#include "../utils/Logger.hpp"

bool ObjectManager::Remove(const Object* object) {
	if (object == nullptr) {
		BEGIN_ERROR();
		LOG << "Can't remove null from objects!";
		END();
		return false;
	}

	auto pos = std::ranges::find_if(objects, [object](const std::unique_ptr<Object>& obj) {
		return object == obj.get();
	});
	
	// auto pos = std::find(objects.begin(), objects.end(), object);
	if (pos == objects.end()) {
		BEGIN_LOG();
		LOG << "Could not find object with name !";
	}
	
	objects.erase(pos);
	return true;
}

void ObjectManager::Sort() {
	for (int i = (int)depthSorted.size() - 1; i >= 0; i--) {
		if (depthSorted[i] == nullptr) {
			depthSorted.erase(depthSorted.begin() + i);
			continue;
		}

		for (int j = i - 1; j >= 0; j--) {
			Object* current = depthSorted[i];
			Object* next = depthSorted[j];

			if (next == nullptr) {
				depthSorted.erase(depthSorted.begin() + j);
				continue;
			}

			if (current->GetName() == next->GetName()) {
				continue;
			}

			if (next->GetPriority() < current->GetPriority()) {
				depthSorted[j] = current;
				depthSorted[i] = next;
			}
		}
	}

	BEGIN_LOG();
	LOG << "Sorted objects, size of list: " << (int)depthSorted.size();
	END();
}

void ObjectManager::Update() {
	for (const auto& object : depthSorted) {
		object->Update();
	}

	for (const auto& object : depthSorted) {
		if (!object->HasParent()) {
			object->RecalculateTransform(MatrixIdentity());
		}
	}
}

void ObjectManager::Render() {
	for (const auto& object : depthSorted) {
		object->Render();
	}
}
