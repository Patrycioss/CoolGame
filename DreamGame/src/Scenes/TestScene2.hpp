#pragma once

#include "Scene.hpp"

class TestScene2 final : public Scene {
	protected:
		void Start() override;
		void Update() override;
		void Stop() override;

	public:
		using Scene::Scene;
};