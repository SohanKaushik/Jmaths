#define GLM_ENABLE_EXPERIMENTAL
#include "play.h"
#include <glm/gtx/string_cast.hpp>

namespace jmaths::animations {


	Animations::Animations() {
	}

    Animations::Animations(jmaths::scene::JObjects& obj, std::vector<glm::vec3> verts, float duration) {
        m_target = &obj;
        m_duration = duration;
        m_points = verts;
        m_elapsed = 0.0f;

    }


    void Animations::update() {

        if (is_done) return;

        m_elapsed += Time::deltaTime;

        float t = glm::clamp(m_elapsed / m_duration, 0.0f, 1.0f);

        size_t count = (size_t)(t * m_points.size());


        if (count > m_cursor) {
            m_cursor = count;

            std::vector<glm::vec3> visible(
                m_points.begin(),
                m_points.begin() + m_cursor
            );

            m_target->m_geo[0]->update(visible, rdrtype::CONNECT_LINES);
        }

        if (t >= 1) {
            is_done = true;
        }
    }
}

