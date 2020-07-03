#pragma once

namespace simpleEngine
{
	class IEntity;
	class gameObject;
	class player;
	class geometryObject;
	class keyListener;
	class window;
	class globalScene;
	class scene;
	template<std::size_t SIZE>
	class animation;

	using gameObjectPtr = std::shared_ptr<gameObject>;
	using playerPtr = std::shared_ptr<player>;
	using geometryPtr = std::shared_ptr<geometryObject>;
}