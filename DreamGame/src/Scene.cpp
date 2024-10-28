#include "Scene.hpp"

Scene::Scene(const std::string& name) {
	this->name = name;
}

void Scene::InternalStart() {
	if (loggingEnabled) {
		// Todo: Send to logger
	}
}

void Scene::InternalUpdate() {
	if (loggingEnabled) {
		// Todo: Send to logger
	}
}

void Scene::InternalStop() {
	if (loggingEnabled) {
		// Todo: Send to logger
	}
}

const std::string& Scene::Name() {
	return name;
}

void Scene::EnableLogging(const bool enable) {
	this->loggingEnabled = enable;
}
