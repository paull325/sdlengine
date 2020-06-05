#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	class gameObject
	{
	public:
		gameObject(const std::string& gameObjectName);
		gameObject(const std::string& gameObjectName, std::function<void()> loadFunction, std::function<void()> updateFunction);
		~gameObject();

		std::string gameObjectName();
		void setGameObjectName(const std::string& gameObjectName);

		void onLoad();
		void setUpdateFunction(std::function<void()> updateFunction);
		void updateGameObject();

	private:
		std::string m_gameObjectName;

		std::function<void()> m_updateFunction;
		std::function<void()> m_loadFunction;
	};
}