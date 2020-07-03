#pragma once
#include "stdinclude.h"
#include "gameObject.h"
#include "globalScene.h"
#include "animation.h"

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

	private:
		double m_maxSpeed;
		unsigned char m_anim;	//animation state
		char X_AXIS, Y_AXIS;

		animation<4> walking = animation<4>({ 0, 1, 0, 2 });
		animation<2> idle = animation<2>({ 0, 1 });

		/*		FUNCTIONAL		*/
		void doMovement();
	};
}