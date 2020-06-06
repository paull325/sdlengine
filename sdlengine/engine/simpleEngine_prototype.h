#pragma once

namespace simpleEngine
{
	class gameObject;
	class entity;

	using gameObjectPtr = std::shared_ptr<gameObject>;
	using entityPtr = std::shared_ptr<entity>;
}