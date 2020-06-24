#include "stdinclude.h"
#include "geometry.h"

namespace simpleEngine
{
	geometryObject::geometryObject(int x, int y, int xSize, int ySize)
	{
		m_xPosition = x;
		m_yPosition = y;
		m_xSize = xSize;
		m_ySize = ySize;
	}

	void geometryObject::set(int x, int y, int xSize, int ySize)
	{
		m_xPosition = x;
		m_yPosition = y;
		m_xSize = xSize;
		m_ySize = ySize;
	}
}