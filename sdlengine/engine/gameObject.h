#pragma once
#include "stdinclude.h"
#include "entity.h"
#include "geometry.h"

namespace simpleEngine
{
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

	protected:
		globalScene* m_global;
		SDL_Surface* m_sprite;
		geometryPtr m_geometry;
	};
}