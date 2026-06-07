#pragma once
#include "../pch.h"
#include "../buffers/gl_buffers.h"
#include "../scene/objects.h"
#include "../maths/Time.h"

namespace jmaths::animations {

	class Animations {

		public:
			Animations();
			Animations(jmaths::scene::JObjects& original, std::vector<glm::vec3> verts, float duration);

			/*void play(jmaths::scene::JObjects& obj, float duration = 5.0f);
			void play(const std::vector<glm::vec3>& points, float duration = 5.0f);*/
			void update();



	private:
		std::vector<glm::vec3> m_points = std::vector<glm::vec3>({});
		std::unique_ptr<geometry> m_geo;
		jmaths::scene::JObjects*  m_target;
		float  m_duration = 1.0f;
		float  m_elapsed = 0.0f;

		float m_cursor = 0.0f;

		bool is_done = false;
	};


	
}