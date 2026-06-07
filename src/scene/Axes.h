#pragma once
#include "../pch.h"
#include "../scene/objects.h"
#include "../src/maths/range.h"
#include "JObjects/Graphs.h"

namespace jmaths:: scene {
	
	class Axes : public JObjects {

	private:
		utility::Range m_bound_x = {-10,10};
		utility::Range m_bound_y = {-10,10};

	public:
		Axes();
		Axes(utility::Range x, utility::Range y);

		void make_grid(int half_size, float spacing = 1.0f);

		void plot(std::function<float(float)> fn, float samples = 100, float step = 0.5f);
		Graphs plot(std::function<float(float)> fn, utility::Range range);
	};
}