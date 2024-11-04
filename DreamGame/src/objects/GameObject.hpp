#pragma once
#include <raylib.h>
#include "../Collider.hpp"

class ObjectManager;

class GameObject {
	friend ObjectManager;

	private:
		Collider collider;

		const unsigned int ID;
		int priority;
		static unsigned int lastID;

		void InternalUpdate();
		void InternalRender();

	protected:
		virtual void Update();
		virtual void Render();

	public:
		Vector2 position;
		Vector2 scale;
		float rotation;

		virtual ~GameObject() = default;
		explicit GameObject(const Vector2& position, int priority);

		[[nodiscard]] const Collider& Collider() const;

		[[nodiscard]] unsigned int GetID() const;
		[[nodiscard]] int GetPriority() const;
};
