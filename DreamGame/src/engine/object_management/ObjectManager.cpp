#include "ObjectManager.hpp"

void ObjectManager::Sort() {
	for (int i = sorted.size() - 1; i >= 0; i--) {
		Object* current = sorted[i];

		if (current == nullptr) {
			sorted.erase(sorted.begin() + i);
			continue;
		}

		int j = i - 1;

		if (j >= 0) {
			Object* next = sorted[j];

			if (next == nullptr) {
				sorted.erase(sorted.begin() + j);
				continue;
			}

			if (next->GetPriority() < current->GetPriority()) {
				sorted[j] = current;
				sorted[i] = next;
			}
		}
	}
}

void ObjectManager::Update() {
	for (const auto& object : sorted) {
		object->Update();
	}
}

void ObjectManager::Render() {
	for (const auto& object : sorted) {
		object->Render();
	}
}
