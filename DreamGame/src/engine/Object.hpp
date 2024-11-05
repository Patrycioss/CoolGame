#pragma once
#include <raylib.h>
#include <vector>

#include "Collider.hpp"

class ObjectManager;

class Object {
	friend ObjectManager;

	private:
		static int lastID;

		Collider collider;
		int priority;
		const int ID;

		int parent = -1;
		std::vector<int> children;
		ObjectManager* objectManager = nullptr;

		Vector2 position;
		Vector2 scale;
		float rotation;

		void InternalSetManager(ObjectManager* manager);
		void InternalUpdate();
		void InternalRender();

	protected:
		virtual void Update();
		virtual void Render();

	public:
		virtual ~Object() = default;
		explicit Object(const Vector2& position, int priority);

		[[nodiscard]] const Collider& Collider() const;

		[[nodiscard]] int GetID() const;
		[[nodiscard]] int GetPriority() const;

		void SetPriority(int priority);

		void SetParent(int parentID);

		void AddChild(int id);
		bool RemoveChild(int id);

		void SetPosition(const Vector2& position);
		void SetScale(const Vector2& scale);
		void SetRotation(float rotation);
		const Vector2& GetPosition() const;
		const Vector2& GetScale() const;
		float GetRotation() const;
};


