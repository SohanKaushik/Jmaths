#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

enum rdrtype {
	TRIANGLES = GL_TRIANGLES,
	LINES = GL_LINES,
	POINTS = GL_POINTS
};

class mesh {
	private:
		unsigned int VBO = 0;
		unsigned int VAO = 0;
		rdrtype type = rdrtype::LINES;

	public:
		mesh(const std::vector<float>& vert, rdrtype _type = rdrtype::LINES) {

			// Create and bind VAO
			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			// Create and bind VBO
			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
			// send the data to gpu
			glBufferData(GL_ARRAY_BUFFER, vert.size() * sizeof(float), vert.data(), GL_STATIC_DRAW);
	
			// position
			glVertexAttribPointer(
				0,                  // location in shader	
				2,                  // 3 floats per vertex
				GL_FLOAT,
				GL_FALSE,
				2 * sizeof(float),  // stride
				(void*)0            // offset
			);
	
			glEnableVertexAttribArray(0);
	
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

		
			// render type
			type = _type;
		}
	
		void draw() {
			glBindVertexArray(VAO);
			glDrawArrays(type, 0, 2);
		}
};


