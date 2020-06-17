#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	class scene
	{
	public:
		scene() { m_sceneName = ""; m_active = false; };
		scene(const std::string& sceneName) { m_sceneName = sceneName; m_active = true; };
		~scene();

		void sceneName(const std::string& sceneName) { m_sceneName = sceneName; };
		const std::string& sceneName() const { return m_sceneName; }

		void load();
		void update();

		void activate() { m_active = true; };
		void deactivate() { m_active = false; };;

		bool addPlayer(player& p);
		const playerPtr getPlayerById(int id) { return m_playerList.at(id); };

		bool addGameObject(gameObject& obj);
		const gameObjectPtr getGameObjectByName(const std::string& gameObjectName);
		const gameObjectPtr getGameObjectById(int id) { return m_gameObjectList.at(id); };

	protected:
		bool m_active;

		std::vector<gameObjectPtr> m_gameObjectList;
		std::vector<playerPtr> m_playerList;

		std::string m_sceneName;
	};

}