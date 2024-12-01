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

	float rotation = 0;
	if (IsKeyDown(KEY_A)) {
		rotation -= 1;
	}

	if (IsKeyDown(KEY_D)) {
		rotation += 1;
	}

	// printf("rotatiion %f\n", rotation);
	
	SetPosition(LocalPosition() + direction * GetFrameTime() * 1000);
	SetRotation(LocalRotation() + rotation * GetFrameTime() * 1000);
}

void Player::Render() {
	const auto [x,y] = WorldPosition();
	const auto [scaleX, scaleY] = WorldScale();
	// DrawTexture(texture, x, y, color);
	Vector2 size = Vector2{scaleX * texture.width, scaleY * texture.height};
	DrawTexturePro(texture, {0,0,(float)texture.width,(float)texture.height},{x,y,size.x, size.y}, size/2.0f, WorldRotation(), color);
}

Player::Player(const std::string& name,const Vector2& position, const int priority, const Color& color)
	: Object(name,position, priority), texture(LoadTexture((std::string(RESOURCES) + "/textures/awesomeface.png").c_str())),
	  color(color) {
}
