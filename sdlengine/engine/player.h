#pragma once
#include "gameObject.h"

namespace simpleEngine
{
	class player : public gameObject
	{
	public:
		player();
		player(globalScene* g);
		~player();

		virtual void update();

		/*		FUNCTIONAL		*/
		void doMovement();
		
		bool COLLISION_LEFT;
		bool COLLISION_RIGHT;
		bool COLLISION_TOP;
		bool COLLISION_BOTTOM;
	};
}