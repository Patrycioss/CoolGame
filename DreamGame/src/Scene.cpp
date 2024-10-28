#include "Scene.hpp"

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

Scene::Scene(const std::string& name) {
	this->name = name;
}

void Scene::EnableLogging(const bool enable) {
	this->loggingEnabled = enable;
}

