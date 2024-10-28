#pragma once

#include <string>


class Scene 
{
	friend class SceneManager;

	private:
		std::string name;
		bool loggingEnabled = true;

		void InternalStart();
		void InternalUpdate();
		void InternalStop();

	protected:
		void Start();
		void Update();
		void Stop();

	public:
		explicit Scene(const std::string& name);
		void EnableLogging(bool enable);
};
