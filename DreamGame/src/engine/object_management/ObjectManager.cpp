#include "ObjectManager.hpp"

void ObjectManager::Sort() {
	for (int i = (int)sorted.size() - 1; i >= 0; i--) {

		if (sorted[i] == nullptr) {
			printf("currentnull\n");
			sorted.erase(sorted.begin() + i);
			continue;
		}

		for (int j = i - 1; j >= 0; j--) {
			Object* current = sorted[i];
			Object* next = sorted[j];

			if (next == nullptr) {
				printf("nextnull\n");
				sorted.erase(sorted.begin() + j);
				continue;
			}

			if (current->GetID() == next->GetID()) {
				printf("currentisnext\n");
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
