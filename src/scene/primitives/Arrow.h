#pragma once
#include "../objects.h"

namespace jmaths {
	namespace primitives {

		class Arrow : public jmaths::scene::JObjects{
			public:
				Arrow() {
					std::vector<glm::vec3> verts;
					set_scale(7);

					verts.push_back({ 0.0f,  0.5f, 0.0f }); // top
					verts.push_back({ -0.5f, -0.5f, 0.0f }); // left
					verts.push_back({ 0.5f, -0.5f, 0.0f }); // right

					feed_vert(verts, rdrtype::TRIANGLES);
				}
		};
	}
}