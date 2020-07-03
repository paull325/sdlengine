#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	template<std::size_t SIZE>
	class animation
	{
	public:
		animation() { m_global = nullptr; anim_frame = 0; };
		animation(std::array<int, SIZE> animation) { m_global = nullptr; anim_frame = 0; m_animation = animation; };
		~animation() {};

		void global(globalScene* g) { m_global = g; };

		int playAnimation(int frameStep)
		{
			if (m_global != nullptr)
			{
				if (m_global->frame() % frameStep == 0)
				{
					if (anim_frame < SIZE - 1)
					{
						anim_frame++;
					}
					else
					{
						anim_frame = 0;
					}
				}
			}

			return m_animation[anim_frame];
		}

	private:
		std::array<int, SIZE> m_animation;
		globalScene* m_global;
		int anim_frame;
	};
}
