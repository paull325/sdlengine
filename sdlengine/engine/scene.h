#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	class gameObject;

	class scene
	{
	public:
		scene();
		scene(const std::string& sceneName, std::function<void()> loadFunction, std::function<void()> updateFunction);
		~scene();

		std::string sceneName();
		void setSceneName(const std::string& gameObjectName);

		void end();
		void onLoad();
		void update();

		bool addGameObject(gameObject& obj);
		gameObject* getGameObjectByName(const std::string& gameObjectName);
		gameObject* getGameObjectById(int id);

		size_t getGameObjectListSize();

	protected:
		bool m_active;
		std::vector<gameObject> m_gameObjectList;

		virtual bool init();

	private:
		std::string m_sceneName;

		std::function<void()> m_updateFunction;
		std::function<void()> m_loadFunction;
	};

}