#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	class IEntity
	{
	public:
		virtual ~IEntity() {};

		void name(const std::string& name) { m_name = name; };
		const std::string& name() const { return m_name; };

		virtual void update() = 0;

		void activate() { m_active = true; };
		void deactivate() { m_active = false; };;

	protected:
		bool m_active;
		std::string m_name;
	};

	class keyListener : public IEntity
	{
	public:
		keyListener() { keystate = SDL_GetKeyboardState(NULL); };
		~keyListener() {};

		void update() override;

		bool checkKeyDown(SDL_Scancode code);

	private:
		const Uint8* keystate = SDL_GetKeyboardState(NULL);
	};

	class gameObject : public IEntity
	{
	public:
		gameObject();
		gameObject(globalScene* g);
		gameObject(globalScene* g, const std::string& name);
		~gameObject();

		void update() override;

		bool loadSprite(const std::string& imagePath);

		void position(int x, int y) { m_xPosition = x; m_yPosition = y;};
		const int xPosition() const { return m_xPosition; };
		const int yPosition() const { return m_yPosition; };

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

		void update() override;
		void updateSprite() override;
		void move(int xDistance, int yDistance) { m_xPosition += xDistance; m_yPosition += yDistance; };
	};
}