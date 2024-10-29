#include "Window.hpp"

void Window::UpdateWindowSize() {
	this->size = Vector2(GetScreenWidth(), GetScreenHeight());
}

Window::Window(const Vector2& resolution, const bool fullscreen) : resolution(resolution){

	unsigned int configFlags{};
	configFlags |= FLAG_VSYNC_HINT;
	
	if (fullscreen) {
		configFlags |= FLAG_FULLSCREEN_MODE;
		configFlags |= FLAG_BORDERLESS_WINDOWED_MODE;
	}

	SetConfigFlags(configFlags);

	InitWindow((int)resolution.x, (int)resolution.y, "DreamGame");

	UpdateWindowSize();
}

const Vector2& Window::Size() const {
	return this->size;
}

const Vector2& Window::Resolution() const {
	return this->resolution;
}

void Window::Update() {
	mousePosition = GetMousePosition();

	if (IsWindowResized()) {
		UpdateWindowSize();
	}
}

bool Window::ShouldClose() {
	return WindowShouldClose();
}
