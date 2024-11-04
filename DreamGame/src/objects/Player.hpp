#pragma once

#include "GameObject.hpp"

class Player final : public GameObject {
	private:
		Texture texture;

	protected:
		void Update() override;
		void Render() override;

	public:
		explicit Player(const Vector2& position);
};
