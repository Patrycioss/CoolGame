﻿#include "ObjectManager.hpp"

bool ObjectManager::Remove(const unsigned ID) {
	int objectCount = (int)objectMap.size();
	bool success = objectMap.erase(ID) > 0;

	if (success) {
		printf("Successfully removed! Object count before remove: %i, after: %i\n", objectCount, (int)objectMap.size());
	}
	return success;
}

void ObjectManager::Sort() {
	for (int i = (int)sorted.size() - 1; i >= 0; i--) {
		if (sorted[i] == nullptr) {
			sorted.erase(sorted.begin() + i);
			continue;
		}

		for (int j = i - 1; j >= 0; j--) {
			Object* current = sorted[i];
			Object* next = sorted[j];

			if (next == nullptr) {
				sorted.erase(sorted.begin() + j);
				continue;
			}

			if (current->GetID() == next->GetID()) {
				continue;
			}

			if (next->GetPriority() < current->GetPriority()) {
				sorted[j] = current;
				sorted[i] = next;
			}
		}
	}

	printf("Sorted objects, size of list: %i\n", (int)sorted.size());
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
