#pragma once
#include "raylib.h"

class Window {
	private:
		Vector2 resolution;
		Vector2 size;
		Vector2 mousePosition;

		void UpdateWindowSize();

	public:
		explicit Window(const Vector2& resolution, bool fullscreen = false);
		const Vector2& Size() const;
		const Vector2& Resolution() const;
		void Start();
		void Update();
		bool ShouldClose();
};
