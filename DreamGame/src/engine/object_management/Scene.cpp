#include "Scene.hpp"

#include "../utils/Logger.hpp"

void Scene::InternalStart() {
	Start();

	Sort();

	if (logStartStop) {
		BEGIN_LOG();
		LOG << "Starting Scene: " << name;
		END();
	}
}

void Scene::InternalUpdate() {
	objectManager.Update();

	Update();

	if (logUpdate) {
		BEGIN_LOG();
		LOG << "Updating Scene: " << name;
		END();
	}
}

void Scene::InternalRender() {
	objectManager.Render();

	Render();

	if (logRender) {
		BEGIN_LOG();
		LOG << "Rendering Scene: " << name;
		END();
	}
}

void Scene::InternalStop() {
	Stop();

	if (logStartStop) {
		BEGIN_LOG();
		LOG << "Stopping Scene: " << name;
		END();
	}
}

void Scene::Start() {
}

void Scene::Update() {
}

void Scene::Render() {
}

void Scene::Stop() {
}

Scene::Scene(const std::string& name)
	: name(name) {
}

bool Scene::Remove(const Object* object) {
	return objectManager.Remove(object);
}

void Scene::Sort() {
	objectManager.Sort();
}

const std::string& Scene::GetName() const {
	return name;
}

void Scene::LogStartStop(const bool value) {
	this->logStartStop = value;
}

void Scene::LogUpdate(const bool value) {
	this->logUpdate = value;
}

void Scene::LogRender(const bool value) {
	this->logRender = value;
}
