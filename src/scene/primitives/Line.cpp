#include "pch.h"
#include "Line.h"

namespace jmaths {
	namespace primitives {


		Line::Line(glm::vec2 x, glm::vec2 y) {
			std::vector<glm::vec3> m_vert;

			m_vert.push_back({ x, 0 });
			m_vert.push_back({ y, 0 });

			feed_vert(m_vert, rdrtype::LINES);
		}

		Line::Line(float a, float b, float length) {
			std::vector<glm::vec3> m_vert;

			for (int i = -length; i <= length; i++) {
				m_vert.push_back({ (float)i, a * i + b, 0.0f });
			}

			feed_vert(m_vert, rdrtype::CONNECT_LINES);
		}
	}
}