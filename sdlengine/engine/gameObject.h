#pragma once
#include "stdinclude.h"
#include "entity.h"

namespace simpleEngine
{
	class gameObject : public IEntity
	{
	public:
		gameObject();
		gameObject(globalScene* g);
		gameObject(globalScene* g, const std::string& name);
		~gameObject();

		virtual void update();

		bool loadSprite(const std::string& imagePath);

		void position(int x, int y) { m_xPosition = x; m_yPosition = y; };
		const int xPosition() const { return m_xPosition; };
		const int yPosition() const { return m_yPosition; };

		void move(int xDistance, int yDistance) { m_xPosition += xDistance; m_yPosition += yDistance; };

		virtual void updateSprite();

	protected:
		globalScene* m_global;
		int m_xPosition, m_yPosition;
		SDL_Surface* m_sprite;
	};

	class player : public gameObject
	{
	public:
		player(globalScene* g);
		~player();

		virtual void update();
		virtual void updateSprite();

		/*		FUNCTIONAL		*/
		void doMovement();
	};
}