#pragma once

#include "../../engine/Engine.hpp"

class Player final : public Object {
	private:
		Texture texture;
		Color color;

	protected:
		void Update() override;
		void Render() override;

	public:
		explicit Player(const std::string& name, const Vector2& position, int priority, const Color& color = WHITE);
};
