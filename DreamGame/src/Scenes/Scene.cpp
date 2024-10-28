﻿#include "Scene.hpp"

#include "../Logger.hpp"

void Scene::InternalStart() {
	Start();

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

void Scene::Stop() {
}

Scene::Scene(const std::string& name) {
	this->name = name;
}

const std::string& Scene::Name() {
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

Scene::~Scene() {
};
