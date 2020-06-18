#pragma once
#include "stdinclude.h"
#include "entity.h"

namespace simpleEngine
{
	class keyListener : public IEntity
	{
	public:
		keyListener() { keystate = SDL_GetKeyboardState(NULL); };
		~keyListener() {};

		virtual void update();

		bool checkKeyDown(SDL_Scancode code);

	private:
		const Uint8* keystate = SDL_GetKeyboardState(NULL);
	};
}