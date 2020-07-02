#pragma once
#include "gameObject.h"

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
		int doWalkingAnimation();

	private:
		double m_maxSpeed;
		unsigned char m_anim;
		char X_AXIS, Y_AXIS;
	};
}