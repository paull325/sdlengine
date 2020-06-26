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
	};
}