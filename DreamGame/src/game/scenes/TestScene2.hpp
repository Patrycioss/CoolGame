﻿#pragma once

#include "../../engine/Engine.hpp"

class TestScene2 final : public Scene {
	protected:
		void Start() override;
		void Update() override;
		void Render() override;
		void Stop() override;

	public:
		using Scene::Scene;
};