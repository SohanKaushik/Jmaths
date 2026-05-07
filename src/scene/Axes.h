#pragma once
#include "../pch.h"
#include "../scene/objects.h"

namespace jmaths:: scene {
	
	class Axes : public JObjects {

	public:
		void make_grid(int half_size, float spacing = 1.0f);
	};
}