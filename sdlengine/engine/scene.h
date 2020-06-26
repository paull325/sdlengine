#pragma once
#include "stdinclude.h"
#include "player.h"

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
		virtual void update();

		void activate() { m_active = true; };
		void deactivate() { m_active = false; };

		template <typename T> void addGameObject(T& obj) { m_gameObjectList.emplace_back(std::make_shared<T>(obj)); };

		const gameObjectPtr getGameObjectByName(const std::string& gameObjectName);
		const gameObjectPtr getGameObjectById(int id) { return m_gameObjectList.at(id); };

	protected:
		bool m_active;

		std::vector<gameObjectPtr> m_gameObjectList;

		std::string m_sceneName;

		void updateCollisionFlags(gameObjectPtr obj, int i_);
	};

}