#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
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
		gameObjectPtr getGameObjectByName(const std::string& gameObjectName);
		gameObjectPtr getGameObjectById(int id);
		size_t gameObjectListSize();

		bool addEntity(entity& obj);
		entityPtr getEntityByName(const std::string& entityName);
		entityPtr getEntityById(int id);
		size_t entityListSize();

	protected:
		bool m_active;
		std::vector<gameObjectPtr> m_gameObjectList;
		std::vector<entityPtr> m_entityList;

	private:
		std::string m_sceneName;

		std::function<void()> m_loadFunction, m_updateFunction;
	};

}