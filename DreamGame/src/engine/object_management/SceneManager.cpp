#include "SceneManager.hpp"

SceneManager::SceneManager() = default;

void SceneManager::SetScene(const std::string& name) {
	if (!hasActiveScene || activeScene->name != name) {
		if (scenes.contains(name)) {
			const auto& scene = scenes.at(name);
			activeScene = scene.get();

			if (hasActiveScene) {
				activeScene->InternalStop();
			}

			activeScene = scene.get();
			hasActiveScene = true;
			activeScene->InternalStart();
		} else {
			BEGIN_ERROR();
			LOG << "Can't set scene with name: '" << name << "' cause it isn't registered in the scene map!";
			END();
		}
	}
}

void SceneManager::Update() const {
	if (hasActiveScene) {
		activeScene->InternalUpdate();
	}
}

void SceneManager::Render() const {
	if (hasActiveScene) {
		activeScene->InternalRender();
	}
}

Scene*& SceneManager::ActiveScene() {
	return activeScene;
}
