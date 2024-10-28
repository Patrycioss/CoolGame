#pragma once
#include "Scene.hpp"

#include <unordered_map>
#include <memory>

#include "../Concepts.hpp"
#include "../Logger.hpp"

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
				Logger::LogError("Can't add scene, scene: '" + name + "' already exists!", __FILE_NAME__, __LINE__);
				return;
			}

			scenes.emplace(name, std::make_unique<T>(name));
		}
};
