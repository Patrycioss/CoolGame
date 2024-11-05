#pragma once

#include <string>

#include "ObjectManager.hpp"

class Scene {
	friend class SceneManager;

	private:
		std::string name;

		ObjectManager objectManager;

		bool logStartStop = true;
		bool logUpdate = false;
		bool logRender = false;

		void InternalStart();
		void InternalUpdate();
		void InternalRender();
		void InternalStop();

	protected:
		virtual void Start();
		virtual void Update();
		virtual void Render();
		virtual void Stop();

	public:
		explicit Scene(const std::string& name);

		template<Concepts::Derived<Object> T, typename... Args>
		T* Add(Args... args) {
			return objectManager.Add<T>(args...);
		}

		template<Concepts::Derived<Object> T>
		T* Get(const unsigned int ID) {
			return objectManager.Get<T>(ID);
		}

		bool Remove(unsigned ID);
		void Sort();

		void LogStartStop(bool value);
		void LogUpdate(bool value);
		void LogRender(bool value);

		const std::string& Name();

		~Scene();
};
