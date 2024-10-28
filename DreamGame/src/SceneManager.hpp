#pragma once

#include "Scene.hpp"

#include <map>

#include "Concepts.hpp"

class SceneManager {
	private:
		std::map<const char*, std::unique_ptr<Scene>> scenes;

		Scene* activeScene = nullptr;
		bool hasActiveScene = false;

	public:
		template<Concepts::Derived<Scene> T>
		void AddScene(const std::string& name) {
			const bool success = scenes.try_emplace(name, std::make_unique<T>(name));

			if (!success) {
				//Todo: Log error: "Can't add scene, scene " + name + " already exists"
			};
		}

		void SetScene(const std::string& name);

		void Update() const;
};
