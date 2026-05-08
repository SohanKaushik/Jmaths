#pragma once
#include "../pch.h"

namespace jmaths {
	namespace scene {
		namespace camera {

			enum Mode {
				Orthographic,
				Perspective
			};

			class Camera {

			private:
				Mode m_mode;
				bool m_dirty;
				glm::mat4 m_projection = glm::mat4(1.0f);
				glm::mat4 m_view = glm::mat4(1.0f);

			private:
				void orbit();

			public:
				Camera();
				void set_projection(Mode mode);
				const glm::mat4& get_pvmatrix();
				void update_projection();

			};
		}
	}
}