#pragma once

#include "../../engine/Engine.hpp"

class TestScene1 : public Scene {
	private:
		Texture2D texture;
	
	protected:
		void Start() override;
		void Update() override;
		void Render() override;
		void Stop() override;

	public:
	explicit TestScene1(const std::string& name);
		using Scene::Scene;
};
