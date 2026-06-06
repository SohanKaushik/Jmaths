#include "Line.h"

namespace jmaths {
	namespace primitives {


		Line::Line(glm::vec2 x , glm::vec2 y) {
			m_x = x;
			m_y = y;

			generate();
		}

		void Line::generate() {

			std::vector<glm::vec3> m_vert;
			m_vert.push_back({m_x, 0});
			m_vert.push_back({m_y, 0});

			feed_vert(m_vert, rdrtype::LINES);
		}

	}
}