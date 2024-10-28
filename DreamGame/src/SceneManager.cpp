#include "SceneManager.hpp"

void SceneManager::SetScene(const std::string& name) {
	if (!hasActiveScene || activeScene->name != name) {
		const char* key = name.c_str();
		if (scenes.contains(key)) {
			const auto& scene = scenes.at(key);
			activeScene = scene.get();

			if (hasActiveScene) {
				activeScene->InternalStop();
			}

			activeScene = scene.get();
			hasActiveScene = true;
			activeScene->InternalStart();
		} else {
			//Todo: Log that scene can't be set cause it doesn't exist in the map.
		}
	}
}

void SceneManager::Update() const {
	if (hasActiveScene) {
		activeScene->Update();
	}
}
