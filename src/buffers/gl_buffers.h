#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

enum class rdrtype : GLenum {
	TRIANGLES = GL_TRIANGLES,
	LINES = GL_LINES,
	POINTS = GL_POINTS,
	CONNECT_LINES = GL_LINE_STRIP
}; 

class geometry {
	private:
		unsigned int m_vao = 0;
		unsigned int m_vbo = 0;
		int          m_vcount = 0;
		rdrtype		 m_type;

	public:
		geometry(const std::vector<float>& vert, rdrtype _type = rdrtype::LINES): m_type(_type), m_vcount(vert.size() / 3) {

			// Create and bind VAO
			glGenVertexArrays(1, &m_vao);
			glBindVertexArray(m_vao);

			// Create and bind VBO
			glGenBuffers(1, &m_vbo);
			glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
			// send the data to gpu
			glBufferData(GL_ARRAY_BUFFER, vert.size() * sizeof(float), vert.data(), GL_STATIC_DRAW);
	
			// position
			glVertexAttribPointer(
				0,                  // location in shader	
				3,                  // 3 floats per vertex
				GL_FLOAT,
				GL_FALSE,
				3 * sizeof(float),  // stride
				(void*)0            // offset
			);
	
			glEnableVertexAttribArray(0);
	
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	
		// no copying
		geometry(const geometry&) = delete;
		geometry& operator=(const geometry&) = delete;

		~geometry() {
			glDeleteVertexArrays(1, &m_vao);
			glDeleteBuffers(1, &m_vbo);
		}

		void draw() {
			glBindVertexArray(m_vao);
			glDrawArrays(static_cast<GLenum>(m_type), 0, m_vcount);
		}
};


