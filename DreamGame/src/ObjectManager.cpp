#include "ObjectManager.hpp"

void ObjectManager::Sort() {
	for (int i = (int)sorted.size() - 1; i >= 0; i--) {
		GameObject*& current = sorted[i];

		if (current == nullptr) {
			sorted.erase(sorted.begin() + i);
		}

		int j = i - 1;

		if (j >= 0) {
			GameObject*& next = sorted[j];

			if (next == nullptr) {
				sorted.erase(sorted.begin() + j);
				continue;
			}

			if (next->GetPriority() < current->GetPriority()) {
				std::swap(next, current);
			}
		}
	}
}

void ObjectManager::Update() {
	for (auto& a : sorted) {
		a->Update();
	}
}

void ObjectManager::Render() {
	for (auto& a : sorted) {
		a->Render();
	}
}
