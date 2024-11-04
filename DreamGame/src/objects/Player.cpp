#include "Player.hpp"

void Player::Update() {
}

void Player::Render() {
	DrawTexture(texture, 20, 20,WHITE);
}

Player::Player(const Vector2& position)
	: GameObject(position, 1000),
	  texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())) {
}
