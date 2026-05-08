#include "Camera.h"

jmaths::scene::camera::Camera::Camera() {
	m_mode = Mode::Orthographic;
	float aspect = 800.0f / 500.0f;
	m_projection = glm::ortho(-100.0f * aspect, 100.0f * aspect, -100.f, 100.0f, 0.1f, 1000.0f);
	m_dirty = true;
	//glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)aspect, 0.1f, 1000.0f); // projection

}

void jmaths::scene::camera::Camera::set_projection(Mode mode) {
	m_dirty = true;
	m_mode = mode;
}

const glm::mat4& jmaths::scene::camera::Camera::get_pvmatrix() {
	return m_projection * m_view;
}

void jmaths::scene::camera::Camera::update_projection() {
	if (!m_dirty) return;

	/*if (m_mode == Mode::Perspective) {
		glm::perspective();
	}
	else {
		glm::ortho();
	}

	m_dirty = false;*/
}
