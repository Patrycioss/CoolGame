#pragma once
#include "Scene.hpp"

#include <unordered_map>
#include <memory>

#include "../utils/Logger.hpp"
#include "../utils/Concepts.hpp"

class SceneManager {
	private:
		std::unordered_map<std::string, std::unique_ptr<Scene>> scenes{};

		Scene* activeScene = nullptr;
		bool hasActiveScene = false;

	public:
		SceneManager();
		void SetScene(const std::string& name);
		void Update() const;
		void Render() const;

		[[nodiscard]] Scene*& ActiveScene();

		template<Concepts::Derived<Scene> T>
		void AddScene(const std::string& name) {
			if (scenes.contains(name)) {
				BEGIN_ERROR();
				LOG << "Can't add scene, scene: " << name << " already exists";
				END();
				return;
			}

			scenes.emplace(name, std::make_unique<T>(name));
		}
};
