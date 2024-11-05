#include "TestChild.hpp"

TestChild::TestChild(const Vector2& position, const int priority, const Color& color)
	: Object(position, priority),
	  texture(LoadTexture(
		  (std::string(RESOURCES) + "/textures/awesomeface.png").
		  c_str())),
	  color(color) {
}

void TestChild::Update() {
}

void TestChild::Render() {
	const auto [x,y] = GetPosition();
	DrawTexture(texture, x, y, color);
}
