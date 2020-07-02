#pragma once
#include "stdinclude.h"
#include "entity.h"
#include "geometry.h"

namespace simpleEngine
{
#define RIGHT false
#define LEFT true

	class gameObject : public IEntity
	{
	public:
		gameObject();
		gameObject(globalScene* g);
		gameObject(globalScene* g, const std::string& name);
		~gameObject();

		virtual void update();

		bool loadSprite(const std::string& imagePath);

		const geometryPtr geometry() { return m_geometry; };

		virtual void updateSprite();

		int layer() { return m_layer; };
		void layer(int layer) { m_layer = layer; };

		void tile(unsigned char x, unsigned char y) { m_xTile = x; m_yTile = y; };

		bool COLLISION_LEFT;
		bool COLLISION_RIGHT;
		bool COLLISION_TOP;
		bool COLLISION_BOTTOM;

	protected:
		bool LOOK_DIR;
		unsigned char m_xTile, m_yTile, m_layer;
		globalScene* m_global;
		SDL_Surface* m_sprite;
		geometryPtr m_geometry;
	};
}