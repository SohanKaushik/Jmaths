#pragma once
#include "../objects.h"


namespace jmaths {
	namespace primitives {
		
		class Circle : public jmaths::scene::JObjects {

			private:
				int m_radius;
				int m_quality;
				int m_steps;
				void generate();

			public:
				Circle(int rad, int quality);

		};
	}
}