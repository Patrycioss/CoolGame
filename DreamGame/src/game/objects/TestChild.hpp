#pragma once

#include "../../engine/Engine.hpp"

class TestChild : public Object {
	private:
		Texture texture;
		Color color;

	public:
		TestChild(const Vector2& position, const int priority, const Color& color);

		void Update() override;
		void Render() override;
};
