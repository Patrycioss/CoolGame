﻿#pragma once

#include <string>

class Scene {
	friend class SceneManager;

	private:
		std::string name;

		bool logStartStop = true;
		bool logUpdate = false;
		bool logRender = false;

		void InternalStart();
		void InternalUpdate();
		void InternalStop();

	protected:
		virtual void Start();
		virtual void Update();
		virtual void Stop();

	public:
		explicit Scene(const std::string& name);

		void LogStartStop(bool value);
		void LogUpdate(bool value);
		void LogRender(bool value);
	
		const std::string& Name();

		~Scene();
};