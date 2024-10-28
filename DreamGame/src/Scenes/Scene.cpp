#include "Scene.hpp"

#include "../Logger.hpp"

void Scene::InternalStart() {
	Start();

	if (loggingEnabled) {
		Logger::Log("Starting Scene: " + name);
	}
}

void Scene::InternalUpdate() {
	Update();

	if (loggingEnabled) {
		Logger::Log("Updating Scene: " + name);
	}
}

void Scene::InternalStop() {
	Stop();

	if (loggingEnabled) {
		Logger::Log("Stopping Scene: " + name);
	}
}

void Scene::Start() {
}

void Scene::Update() {
}

void Scene::Stop() {
}

Scene::Scene(const std::string& name) {
	this->name = name;
}

const std::string& Scene::Name() {
	return name;
}

void Scene::EnableLogging(const bool enable) {
	this->loggingEnabled = enable;
}

Scene::~Scene() {
};
