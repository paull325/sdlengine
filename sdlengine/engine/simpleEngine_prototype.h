#pragma once

namespace simpleEngine
{
	class IEntity;
	class gameObject;
	class player;
	class keyListener;
	class window;
	class globalScene;

	using gameObjectPtr = std::shared_ptr<gameObject>;
	using playerPtr = std::shared_ptr<player>;
}