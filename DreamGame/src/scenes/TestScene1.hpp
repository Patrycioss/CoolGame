#pragma once

#include "Scene.hpp"

class TestScene1 : public Scene {
	protected:
		void Start() override;
		void Update() override;
		void Render() override;
		void Stop() override;

	public:
		using Scene::Scene;
};
