#pragma once
#include "../objects.h"


namespace jmaths {
	namespace primitives {

		class Line : public jmaths::scene::JObjects {

		private:
			glm::vec2 m_x;
			glm::vec2 m_y;
			void generate();

		public:
			Line(glm::vec2, glm::vec2);
			Line(float a, float b, float length);

		};
	}
}