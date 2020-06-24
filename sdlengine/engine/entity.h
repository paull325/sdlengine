#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	class IEntity
	{
	public:
		virtual ~IEntity() {};

		void name(const std::string& name) { m_name = name; };
		const std::string& name() const { return m_name; };

		virtual void update() = 0;

		void activate() { m_active = true; };
		void deactivate() { m_active = false; };;

	protected:
		bool m_active;
		std::string m_name;
	}; 
}