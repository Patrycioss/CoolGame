#include "Object.hpp"

#include "object_management/ObjectManager.hpp"
#include "utils/Logger.hpp"
#include "utils/Vector2Extensions.hpp"

int Object::lastID = 0;

void Object::InternalSetManager(ObjectManager* manager) {
	objectManager = manager;
}

void Object::InternalUpdate() {
	Update();
}

void Object::InternalRender() {
	Render();
}

Object::Object(const Vector2& position, const int priority)
	: collider(*this, Vector2{0, 0}),
	  ID(lastID),
	  priority(priority),
	  position(position),
	  scale(1.0f), rotation(0) {
	lastID++;
}

void Object::Update() {
}

void Object::Render() {
}

const Collider& Object::Collider() const {
	return collider;
}

int Object::GetID() const {
	return ID;
}

int Object::GetPriority() const {
	return priority;
}

void Object::SetPriority(const int priority) {
	this->priority = priority;
}

void Object::SetParent(const int parentID) {
	if (parent == parentID) {
		BEGIN_ERROR();
		LOG << "Object with ID: " << ID << " already has this parent!";
		END();
	}

	Object* newParent = objectManager->Get(parentID);

	if (newParent == nullptr) {
		BEGIN_ERROR();
		LOG << "Could not find new parent object with ID: " << parentID;
		END();
		return;
	}

	if (parent != -1) {
		Object* currentParent = objectManager->Get(parentID);
		if (currentParent != nullptr) {
			currentParent->RemoveChild(parentID);
		}
	}

	this->parent = parentID;
	newParent->AddChild(parentID);

	BEGIN_LOG();
	LOG << "Set parent of object with ID: " << ID << " to object with ID:" << parentID;
	END();
}

void Object::AddChild(const int id) {
	auto alreadyAdded = std::find(children.begin(), children.end(), id);
	if (alreadyAdded == children.end()) {
		BEGIN_ERROR();
		LOG << "Object with id: " << id << " already has child with id: " << id;
		END();
		return;
	}

	if (objectManager->Get(id) == nullptr) {
		BEGIN_ERROR();
		LOG << "Object with id: " << id << " could not be added as a child as it couldn't be found!";
		END();
		return;
	}

	children.push_back(id);
}

bool Object::RemoveChild(const int id) {
	for (int i = children.size() - 1; i >= 0; i--) {
		if (children[i] == id) {
			children.erase(children.begin() + i);
			return true;
		}
	}

	return false;
}

void Object::SetPosition(const Vector2& position) {
	for (const auto& child : children) {
		Object* childObject = objectManager->Get(child);
		Vector2 offset = childObject->GetPosition() - GetPosition();
		childObject->SetPosition(position + offset);
	}

	this->position = position;
}

void Object::SetScale(const Vector2& scale) {
	for (const auto& child : children) {
		Object* childObject = objectManager->Get(child);
		childObject->SetScale(scale * childObject->GetScale());
	}

	this->scale = scale;
}

void Object::SetRotation(const float rotation) {
	for (const auto& child : children) {
		Object* childObject = objectManager->Get(child);
		childObject->SetRotation(rotation + childObject->rotation);
	}

	this-> rotation = rotation;
}

const Vector2& Object::GetPosition() const {
	return position;
}

const Vector2& Object::GetScale() const {
	return scale;
}

float Object::GetRotation() const {
	return rotation;
}
