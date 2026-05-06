#include "play.h"

namespace jmaths::animations {


	Animations::Animations() {
	}

    void Animations::play(const std::vector<glm::vec3>& points, float duration)
    {
        m_points = points;
        m_duration = duration;
        m_start = glfwGetTime();
        m_cursor = 0;

        if (!m_geo)
            m_geo = std::make_unique<geometry>(m_points, rdrtype::CONNECT_LINES);
    }

    void Animations::render()
    {
        float progress = (glfwGetTime() - m_start) / m_duration;
        progress = glm::clamp(progress, 0.0f, 1.0f);

        size_t target = (size_t)(progress * m_points.size());

        if (target > m_cursor)
        {
            m_cursor = target;

            std::vector<glm::vec3> visible(
                m_points.begin(),
                m_points.begin() + m_cursor
            );

            m_geo->update(visible);
        }

        if (m_geo)
            m_geo->draw();
    }
}

