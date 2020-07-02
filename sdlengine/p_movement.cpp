#include "stdinclude.h"
#include "player.h"
#include "keyListener.h"
#include "globalScene.h"
#include "window.h"

#include <math.h>

namespace simpleEngine
{
	void player::doMovement()
	{
		/* update vertical axis */
		if (!(m_global->key()->checkKeyDown(SDL_SCANCODE_W) && m_global->key()->checkKeyDown(SDL_SCANCODE_S)))
		{
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_W) && !COLLISION_TOP )
			{
				Y_AXIS = -1;
				m_global->getSceneById(0)->getGameObjectByName("text")->tile(1, 3);
			}
			else if (m_global->key()->checkKeyDown(SDL_SCANCODE_S) && !COLLISION_BOTTOM)
			{
				Y_AXIS = 1;
				m_global->getSceneById(0)->getGameObjectByName("text")->tile(2, 3);
			}
			else
			{
				Y_AXIS = 0;
				m_global->getSceneById(0)->getGameObjectByName("text")->tile(0, 3);
			}
		}
		else
		{
			Y_AXIS = 0;
		}
		/* update horizontal axis */
		if (!(m_global->key()->checkKeyDown(SDL_SCANCODE_A) && m_global->key()->checkKeyDown(SDL_SCANCODE_D)))
		{
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_A) && !COLLISION_LEFT)
			{
				X_AXIS = -1;
				LOOK_DIR = LEFT;
				m_global->getSceneById(0)->getGameObjectByName("text2")->tile(1, 3);
			}
			else if (m_global->key()->checkKeyDown(SDL_SCANCODE_D) && !COLLISION_RIGHT)
			{
				X_AXIS = 1;
				LOOK_DIR = RIGHT;
				m_global->getSceneById(0)->getGameObjectByName("text2")->tile(2, 3);
			}
			else
			{
				X_AXIS = 0;
				m_global->getSceneById(0)->getGameObjectByName("text2")->tile(0, 3);
			}
		}
		else
		{
			X_AXIS = 0;
		}
		/* accelerate until maxSpeed is reached */
		if (X_AXIS != 0 || Y_AXIS != 0)
		{
			if (abs(m_geometry->xVel()) <= m_maxSpeed / sqrt(pow(X_AXIS, 2) + pow(Y_AXIS, 2)))
			{
				m_geometry->xVel(m_geometry->xVel() + X_AXIS * m_geometry->xAcc() / sqrt(pow(X_AXIS, 2) + pow(Y_AXIS, 2)));
			}
			else
			{
				m_geometry->xVel(X_AXIS * m_maxSpeed / sqrt(pow(X_AXIS, 2) + pow(Y_AXIS, 2)));
			}

			if (abs(m_geometry->yVel()) <= m_maxSpeed / sqrt(pow(X_AXIS, 2) + pow(Y_AXIS, 2)))
			{
				m_geometry->yVel(m_geometry->yVel() + Y_AXIS * m_geometry->yAcc() / sqrt(pow(X_AXIS, 2) + pow(Y_AXIS, 2)));
			}
			else
			{
				m_geometry->yVel(Y_AXIS * m_maxSpeed / sqrt(pow(X_AXIS, 2) + pow(Y_AXIS, 2)));
			}

		}

		/* decelerate */
		if (X_AXIS == 0)
		{
			if ((int) m_geometry->xVel() > 0)
			{
				m_geometry->xVel(m_geometry->xVel() - m_geometry->xAcc());
			}
			else if ((int) m_geometry->xVel() < 0)
			{
				m_geometry->xVel(m_geometry->xVel() + m_geometry->yAcc());
			}
		}
		if (Y_AXIS == 0)
		{
			if ((int) m_geometry->yVel() > 0)
			{
				m_geometry->yVel(m_geometry->yVel() - 1);
			}
			else if ((int) m_geometry->yVel() < 0)
			{
				m_geometry->yVel(m_geometry->yVel() + 1);
			}
		}

		/* move or return to idle state */
		if ((int) m_geometry->xVel() == 0 && (int) m_geometry->yVel() == 0)
		{
			m_anim = IDLE;
		}
		else
		{
			m_anim = WALKING;
			m_geometry->move((int) m_geometry->xVel(), (int) m_geometry->yVel());
			if (m_geometry->x() > 800)
			{
				m_geometry->x(0 - m_geometry->xSize());
			}
			else if (m_geometry->x() + m_geometry->xSize() < 0)
			{
				m_geometry->x(800);
			}

			if (m_geometry->y() > 600)
			{
				m_geometry->y(0 - m_geometry->ySize());
			}
			else if (m_geometry->y() + m_geometry->ySize() < 0)
			{
				m_geometry->y(600);
			}
		}
	}
}