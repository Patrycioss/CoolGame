#include "Object.hpp"

#include "../../cmake-build-build-web/_deps/raylib-src/src/raymath.h"
#include "object_management/ObjectManager.hpp"
#include "utils/Logger.hpp"
#include "utils/Vector2Extensions.hpp"
#include "utils/MatrixExtensions.hpp"

void Object::InternalSetManager(ObjectManager* manager) {
	objectManager = manager;
}

void Object::InternalUpdate() {
	Update();
}

void Object::InternalRender() {
	Render();
}

void Object::RecalculateTransform(const Matrix& parentMatrix) {
	// BEGIN_LOG();
	// LOG << GetName() << "Local position: " << localPosition;
	// END();
	Matrix modelMatrix = MatrixMultiply(parentMatrix, MatrixTranslate(localPosition.x, localPosition.y, 0));
	modelMatrix = MatrixMultiply(modelMatrix, MatrixRotate({0, 0, 1}, localRotation));
	modelMatrix = MatrixMultiply(modelMatrix, MatrixScale(localScale.x, localScale.y, 1));

	worldPosition = Vector2{modelMatrix.m3, modelMatrix.m7};

	// BEGIN_LOG();
	// LOG << GetName() << ":\n";
	// LOG << "Local rotation: " << localRotation << "\n";
	// LOG << "World position: " << worldPosition << "\n"; //<< ", World Rotation: " << worldRotation << ", World Scale: " << worldScale;
	// LOG << "Model Matrix: \n";
	// LOG << modelMatrix;
	


	// if (dirty) {
	// 	if (hasParent) {
	//
	// 		
	//
	// 		
	// 		//
	// 		// auto modelMat = MatrixIdentity();
	// 		// modelMat = MatrixMultiply(modelMat, MatrixRotate({0,0,1}, ))
	// 		//
	// 		// worldRotation = localRotation + parent->WorldRotation();
	// 		//
	// 		//
	// 		// Vector2 direction{sin(worldRotation * DEG2RAD), cos(worldRotation * DEG2RAD)};
	// 		// direction = Vector2Normalize(direction);
	// 		//
	// 		// float distance = Vector2Length(localPosition);
	// 		// // std::cout << direction << std::endl;
	// 		//
	// 		// worldPosition = parent->WorldPosition() + (distance * direction);
	// 		// // BEGIN_LOG();
	// 		// // LOG << "Direction: " << direction << " LocalPosition * direction: " << localPosition;
	// 		// // END();
	// 		// worldScale = localScale * parent->worldScale;
	//

	// 	}
	// 	else {
	// 		worldPosition = localPosition;
	// 		worldScale = localScale;
	// 		worldRotation = localRotation;
	//
	// 		// BEGIN_LOG();
	// 		// LOG << GetName() << "World position: " << worldPosition << ", World Rotation: " << worldRotation << ", World Scale: " << worldScale;
	// 		// END();
	// 	}
	// }

	for (const auto& child : children) {
		if (dirty) {
			child->MarkDirty();
		}

		child->RecalculateTransform(modelMatrix);
	}
}

Object::Object(const std::string& name, const Vector2& position, const int priority)
	: collider(*this, Vector2{0, 0}),
	  name(name),
	  priority(priority),
	  localPosition(position),
	  localScale(1.0f, 1.0f), localRotation(0) {
}

void Object::Update() {
}

void Object::Render() {
}

const Collider& Object::Collider() const {
	return collider;
}

std::string Object::GetName() const {
	return name;
}

int Object::GetPriority() const {
	return priority;
}

void Object::SetPriority(const int priority) {
	this->priority = priority;
}

bool Object::SetParent(Object* parent) {
	if (parent == nullptr) {
		if (this->parent != nullptr) {
			this->parent->RemoveChild(this);
		}
		this->parent = nullptr;
		hasParent = false;
		return true;
	}

	if (parent == this->parent) {
		BEGIN_ERROR();
		LOG << "Object with ID: " << name << " already has parent with ID: !";
		END();
		return false;
	}

	if (this->parent != nullptr) {
		this->parent->RemoveChild(this);
	}

	this->parent = parent;

	hasParent = true;
	return true;
}

bool Object::AddChild(Object* child) {
	if (child == nullptr) {
		BEGIN_ERROR();
		LOG << "Cannot add child that is null!";
		END();
		return false;
	}

	const auto alreadyAdded = std::ranges::find(children, child);
	if (alreadyAdded != children.end()) {
		BEGIN_ERROR();
		LOG << "Object with id: " << name << " already has child with id: " << child->GetName();
		END();
		return false;
	}

	if (!child->SetParent(this)) {
		return false;
	}
	children.push_back(child);
	MarkDirty();
	// child->MarkDirty();
	// child->RecalculateTransform();
	// child->SetPosition(child->WorldPosition() - WorldPosition()); 
	return true;
}

bool Object::RemoveChild(Object* child) {
	if (child == nullptr) {
		BEGIN_ERROR();
		LOG << "Cannot remove child that is null!";
		END();
		return false;
	}

	const auto pos = std::ranges::find(children, child);

	if (pos == children.end()) {
		BEGIN_LOG();
		LOG << "Failed to remove child with name " << child->GetName();
		return false;
	}

	children.erase(pos);
	return true;
}

void Object::SetPosition(const Vector2& position) {
	this->localPosition = position;

	for (const auto& child : children) {
		child->MarkDirty();
	}
}

void Object::SetScale(const Vector2& scale) {
	this->localScale = scale;

	for (const auto& child : children) {
		child->MarkDirty();
	}
}

void Object::SetRotation(const float rotation) {
	this->localRotation = rotation;

	for (const auto& child : children) {
		child->MarkDirty();
	}
}

const Vector2& Object::LocalPosition() const {
	return localPosition;
}

const Vector2& Object::LocalScale() const {
	return localScale;
}

float Object::LocalRotation() const {
	return localRotation;
}

const Vector2& Object::WorldPosition() const {
	return worldPosition;
}

const Vector2& Object::WorldScale() const {
	return worldScale;
}

float Object::WorldRotation() const {
	return worldRotation;
}

void Object::MarkDirty() {
	dirty = true;
}

bool Object::HasParent() const {
	return hasParent;
}
