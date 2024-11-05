#pragma once

#include "../../engine/Engine.hpp"
#include "../objects/Player.hpp"

class TestScene1 : public Scene {
	private:
		Texture2D texture;

		Player* player1 = nullptr;
		Player* player2 = nullptr;
		Player* player3 = nullptr;
		Player* player4 = nullptr;

	protected:
		void Start() override;
		void Update() override;
		void Render() override;
		void Stop() override;

	public:
		explicit TestScene1(const std::string& name);
		using Scene::Scene;
};