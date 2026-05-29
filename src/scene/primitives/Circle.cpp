#include "Circle.h"

jmaths::primitives::Circle::Circle(int rad = 1, int quality = 1){
	m_radius = rad;
	m_quality = quality;

	generate();
}

void jmaths::primitives::Circle::generate(){

	std::vector<glm::vec3> m_vert;

	for (size_t i = 0; i < m_quality * 100; i++) {
		float angle = 2.0f * glm::pi<float>() * i / (m_quality * 100);

		float x = m_radius * cos(angle);
		float y = m_radius * sin(angle);

		m_vert.push_back({ x, y, 0 });
	}

	feed_vert(m_vert, rdrtype::LOOP);
}
