#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	class gameObject
	{
	public:
		gameObject();
		gameObject(const std::string& gameObjectName);
		gameObject(const std::string& gameObjectName, std::function<void()> loadFunction, std::function<void()> updateFunction);
		~gameObject();

		std::string gameObjectName();
		void setGameObjectName(const std::string& gameObjectName);

		void onLoad();
		void setUpdateFunction(std::function<void()> updateFunction);
		virtual void updateGameObject();

		void activate();
		void deactivate();

	protected:
		bool m_active;
		std::string m_gameObjectName;

		std::function<void()> m_loadFunction, m_updateFunction;
	};

	class entity : public gameObject
	{
	public:
		entity();
		entity(const std::string& entityName);
		entity(const std::string& entityName, std::function<void()> loadFunction, std::function<void()> updateFunction);
		~entity();

		bool loadSprite(const std::string& imagePath);
		void updateSprite();
		void updateGameObject() override;

		void move(int xDistance, int yDistance);

		int m_xPosition, m_yPosition;

	private:
		SDL_Surface* m_sprite;
	};
}