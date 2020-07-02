#pragma once
#include "stdinclude.h"
#include "gameObject.h"
#include "globalScene.h"

namespace simpleEngine
{
#define IDLE 0
#define WALKING 1

	class player : public gameObject
	{
	public:
		player();
		player(globalScene* g);
		~player();

		void animate();
		virtual void update();

		double maxSpeed() { return m_maxSpeed; };
		void maxSpeed(double maxSpeed) { m_maxSpeed = maxSpeed; };

		/*		FUNCTIONAL		*/
		void doMovement();

	private:
		double m_maxSpeed;
		unsigned char m_anim;	//animation state
		char X_AXIS, Y_AXIS;

		int anim_frame;
		std::array<int, 4> ANIM_walking = { 0, 1, 0, 2 };

		template<std::size_t SIZE>
		int playAnimation(std::array<int, SIZE> anim, int frameStep)
		{
			if (m_global->frame() % frameStep == 0)
			{
				if (anim_frame < anim.size() - 1)
				{
					anim_frame++;
				}
				else
				{
					anim_frame = 0;
				}
			}

			return anim[anim_frame];
		}
	};
}