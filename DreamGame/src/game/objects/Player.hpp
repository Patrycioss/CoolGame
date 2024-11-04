#pragma once

#include "../../engine/Engine.hpp"

class Player final : public GameObject {
	private:
		Texture texture;
		Color color;

	protected:
		void Update() override;
		void Render() override;

	public:
		explicit Player(const Vector2& position, int priority, const Color& color = WHITE);
};
