#pragma once
#include "../pch.h"
#include "../buffers/gl_buffers.h"

namespace jmaths::animations {

	class Animations {

		public:
			Animations();
			void play(const std::vector<glm::vec3>& points, float duration = 5.0f);
			void render();



	private:
		std::vector<glm::vec3> m_points = std::vector<glm::vec3>({});
		std::unique_ptr<geometry> m_geo;
		float  m_duration = 1.0f;
		float  m_start = 0.0f;
		size_t m_cursor = 0;
	};


	
}