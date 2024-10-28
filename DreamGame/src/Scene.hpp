#pragma once

#include <string>

class Scene {
	friend class SceneManager;

	private:
		std::string name;
		bool loggingEnabled = true;

		explicit Scene(const std::string& name);

		void InternalStart();
		void InternalUpdate();
		void InternalStop();

	protected:
		void Start();
		void Update();
		void Stop();

		const std::string& Name();

	public:
		void EnableLogging(bool enable);
};
