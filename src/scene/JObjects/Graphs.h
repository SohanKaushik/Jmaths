#pragma once
#include "pch.h"
#include "../objects.h"

namespace jmaths {
	namespace scene {

		class Graphs : public jmaths::scene::JObjects {
			
		private:
			std::function<float(float)> f;
			float xMin, xMax, step;
			glm::vec3 vertices;  // cached
			bool dirty = true;
		/*private:
			using JObjects::draw;
			using JObjects::set_scale;*/

		public:
			Graphs();
			Graphs(std::vector<glm::vec3> points);
		};
	}
}