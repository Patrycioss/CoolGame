#include "Player.hpp"

void Player::Update() {
	Vector2 direction{0, 0};

	if (IsKeyDown(KEY_UP)) {
		direction.y -= 1;
	}

	if (IsKeyDown(KEY_DOWN)) {
		direction.y += 1;
	}

	if (IsKeyDown(KEY_LEFT)) {
		direction.x -= 1;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		direction.x += 1;
	}

	SetPosition(GetPosition() + direction * GetFrameTime() * 1000);
}

void Player::Render() {
	const auto [x,y] = GetPosition();
	DrawTexture(texture, x, y, color);
}

Player::Player(const Vector2& position, const int priority, const Color& color)
	: Object(position, priority), texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())),
	  color(color) {
}
