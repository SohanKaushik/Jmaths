#include "objects.h"

jmaths::scene::JObjects::JObjects() {
}

jmaths::scene::JObjects::JObjects(const std::vector<glm::vec3>& vert) {

}

void jmaths::scene::JObjects::set_position(const glm::vec3& t) {
	if (m_transform.position == t) return;

	m_transform.position = t;
	transform_dirty = true;
}

void jmaths::scene::JObjects::set_rotation(const glm::vec3& rot) {
	if (m_transform.rotation == rot) return;

	m_transform.rotation = rot;
	transform_dirty = true;
}

void jmaths::scene::JObjects::set_scale(const glm::vec3& s) {
	if (m_transform.scale == s) return;

	m_transform.scale = s;
	transform_dirty = true;
}

glm::mat4 jmaths::scene::JObjects::get_model() {
	return m_model;
}

void jmaths::scene::JObjects::update_transforms() {

	if (!transform_dirty) return;

	//..translation
	glm::mat4 T = glm::translate(glm::mat4(1.0f), m_transform.position);

	//..rotation
	glm::mat4 R = glm::mat4(1.0f);
	R = glm::rotate(R, glm::radians(m_transform.rotation.x), { 1,0,0 });
	R = glm::rotate(R, glm::radians(m_transform.rotation.y), { 0,1,0 });
	R = glm::rotate(R, glm::radians(m_transform.rotation.z), { 0,0,1 });

	//..scale
	glm::mat4 S = glm::scale(glm::mat4(1.0f), m_transform.scale);

	//..apply
	m_model = T * R * S;

	transform_dirty = false;
}

void jmaths::scene::JObjects::render_queue() {
	
}

//void jmaths::scene::JObjects::draw(Shader& Shader) const {
//	if (!m_geo) return;
//
//	Shader.SetUniformMat4f("model", m_model);
//	m_geo->draw();
//}
