#pragma once
#include <raylib.h>
#include <string>
#include <vector>

#include "Collider.hpp"

class ObjectManager;

class Object {
	friend ObjectManager;

	private:
		const std::string name;
		int priority;
		Vector2 localPosition;
		Vector2 localScale;
		float localRotation;

		Vector2 worldPosition{};
		Vector2 worldScale{};
		float worldRotation{};

		Collider collider;
		bool dirty = true;

		bool hasParent = false;
		Object* parent = nullptr;
		std::vector<Object*> children;
		ObjectManager* objectManager = nullptr;

		void InternalSetManager(ObjectManager* manager);
		void InternalUpdate();
		void InternalRender();
		void RecalculateTransform(const Matrix& parentMatrix);

		bool SetParent(Object* parent);

	protected:
		virtual void Update();
		virtual void Render();

	public:
		virtual ~Object() = default;
		explicit Object(const std::string& name, const Vector2& position, int priority);

		[[nodiscard]] const Collider& Collider() const;

		[[nodiscard]] std::string GetName() const;
		[[nodiscard]] int GetPriority() const;

		void SetPriority(int priority);

		bool AddChild(Object* child);
		bool RemoveChild(Object* child);

		void SetPosition(const Vector2& position);
		void SetScale(const Vector2& scale);
		void SetRotation(float rotation);
		const Vector2& LocalPosition() const;
		const Vector2& LocalScale() const;
		float LocalRotation() const;
		[[nodiscard]] const Vector2& WorldPosition() const;
		[[nodiscard]] const Vector2& WorldScale() const;
		[[nodiscard]] float WorldRotation() const;

		void MarkDirty();
		bool HasParent() const;
};
