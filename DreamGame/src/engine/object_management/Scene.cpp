#include "Scene.hpp"

#include "../utils/Logger.hpp"

void Scene::InternalStart() {
	Start();

	Sort();

	if (logStartStop) {
		Logger::Log("Starting Scene: " + name, __FILE_NAME__, __LINE__);
	}
}

void Scene::InternalUpdate() {
	Update();

	if (logUpdate) {
		Logger::Log("Updating Scene: " + name, __FILE_NAME__, __LINE__);
	}
}

void Scene::InternalRender() {
	objectManager.Render();

	Render();

	if (logRender) {
		Logger::Log("Rendering Scene: " + name, __FILE__, __LINE__);
	}
}

void Scene::InternalStop() {
	Stop();

	if (logStartStop) {
		Logger::Log("Stopping Scene: " + name, __FILE_NAME__, __LINE__);
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

bool Scene::Remove(const unsigned ID) {
	return objectManager.Remove(ID);
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
