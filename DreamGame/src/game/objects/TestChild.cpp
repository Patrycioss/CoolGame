#include "TestChild.hpp"

TestChild::TestChild(const std::string& name, const Vector2& position, const int priority, const Color& color)
	: Object(name, position, priority),
	  texture(LoadTexture(
		  (std::string(RESOURCES) + "/textures/awesomeface.png").
		  c_str())),
	  color(color) {
}

void TestChild::Update() {
}

void TestChild::Render() {
	const auto [x,y] = WorldPosition();
	DrawTexture(texture, x, y, color);
}
