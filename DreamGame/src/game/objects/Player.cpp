#include "Player.hpp"

void Player::Update() {
}

void Player::Render() {
	DrawTexture(texture, position.x, position.y,color);
}

Player::Player(const Vector2& position, const int priority, const Color& color)
	: Object(position, priority), texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())),
	  color(color) {
}
