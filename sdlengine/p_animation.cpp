#include "stdinclude.h"
#include "player.h"
#include "keyListener.h"
#include "globalScene.h"
#include "window.h"

namespace simpleEngine
{
	int frameCounter, frameDifference, lastMeasure = 0;
	bool alt = false;

	int player::doWalkingAnimation()
	{
		frameCounter++;
		frameDifference = frameCounter - lastMeasure;
		if (frameDifference == 4)
		{
			lastMeasure = frameCounter;
			if (m_xTile == 0 && !alt)
			{
				alt = true;
				return 1;
			}
			if (m_xTile == 0 && alt)
			{
				alt = false;
				return 2;
			}
			if (m_xTile == 1)
			{
				return 0;
			}
			if (m_xTile == 2)
			{
				return 0;
			}
		}
		return m_xTile;
	}
}