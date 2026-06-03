#pragma once
#include "../pch.h"
#include "../buffers/gl_buffers.h"
#include "../scene/renderable.h"

namespace jmaths {

	namespace scene {

		struct Transform {
			glm::vec3 position = { 0.0f, 0.0f, 0.0f };
			glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };
			glm::vec3 scale = { 1.0f, 1.0f, 1.0f };
		};


		class JObjects {

		private:
			bool transform_dirty = true;
			glm::mat4 m_model = glm::mat4(1.0f);
			

		public:
			std::vector<std::unique_ptr<geometry>> m_geo;
			JObjects();
			JObjects(const std::vector<glm::vec3>& vert);
			void set_position(const glm::vec3& t);
			void set_rotation(const glm::vec3& r);

			void set_scale(const glm::vec3& s);
			void set_scale(const float& s);
			void set_color(const glm::vec3& c);
			glm::mat4 get_model();

		public:
			// will deal with it later
			Transform m_transform = {};
			glm::vec3 m_color = glm::vec3(0.0f);

			// could be optimized like such update_rot(), update_trans(), update_scale() seperately
			void update_transforms();
			void draw(); // render queue

		protected:
			void feed_vert(const std::vector<glm::vec3>& _v, rdrtype rdr);
		};

	}

}