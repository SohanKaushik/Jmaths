#pragma once
#include "../pch.h"
#include "../scene/objects.h"

namespace jmaths:: scene {
	
	class Axes : public JObjects {

	public:
		Axes();
		void make_grid(int half_size, float spacing = 1.0f);
		void plot(std::function<float(float)> fn, float samples = 100, float step = 0.5f);
	};
}