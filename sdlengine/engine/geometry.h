#pragma once
#include "stdinclude.h"
#include "gameObject.h"

namespace simpleEngine
{
	class geometryObject
	{
	public:
		geometryObject(int x, int y, int xSize, int ySize);
		~geometryObject() {};

		void set(int x, int y, int xSize, int ySize);

		int x() { return m_xPosition; };
		void x(int x) { m_xPosition = x; };

		int y() { return m_yPosition; };
		void y(int y) { m_yPosition = y; };

		void move(int xDistance, int yDistance) { m_xPosition += xDistance; m_yPosition += yDistance; };

		int xSize() { return m_xSize; };
		void xSize(int xSize) { m_xSize = xSize; };

		int ySize() { return m_ySize; };
		void ySize(int ySize) { m_ySize = ySize; };

		double xVel() { return m_xVel; };
		void xVel(double xVel) { m_xVel = xVel; };

		double yVel() { return m_yVel; };
		void yVel(double yVel) { m_yVel = yVel; };

		double xAcc() { return m_xAcc; };
		void xAcc(double xAcc) { m_xAcc = xAcc; };

		double yAcc() { return m_yAcc; };
		void yAcc(double yAcc) { m_yAcc = yAcc; };

	protected:
		int m_xPosition, m_yPosition, m_xSize, m_ySize;
		double m_xVel, m_yVel, m_xAcc, m_yAcc;
	};
}