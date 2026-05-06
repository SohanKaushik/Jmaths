#pragma once
#include "../pch.h"

enum class rdrtype : GLenum {
	TRIANGLES = GL_TRIANGLES,
	LINES = GL_LINES,
	POINTS = GL_POINTS,
	CONNECT_LINES = GL_LINE_STRIP
}; 

class geometry {
    private:
        GLuint m_vao = 0;
        GLuint m_vbo = 0;
        std::vector<glm::vec3> m_vert = std::vector<glm::vec3>({});
        rdrtype m_type = rdrtype::LINES;
    
    public:
        geometry(const std::vector<glm::vec3>& vert, rdrtype type = rdrtype::LINES)
            : m_vert(vert), m_type(type)
        {
            glGenVertexArrays(1, &m_vao);
            glGenBuffers(1, &m_vbo);
    
            glBindVertexArray(m_vao);
            glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    
            glBufferData(GL_ARRAY_BUFFER,
                m_vert.size() * sizeof(glm::vec3),
                m_vert.data(),
                GL_STATIC_DRAW);
    
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                sizeof(glm::vec3), (void*)0);
    
            glEnableVertexAttribArray(0);
        }

        geometry() = delete;

        void update(const std::vector<glm::vec3>& nv) {
            m_vert = nv;
    
            glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
            glBufferData(GL_ARRAY_BUFFER,
                m_vert.size() * sizeof(glm::vec3),
                m_vert.data(),
                GL_DYNAMIC_DRAW);
        }
    
        void draw() {
            glBindVertexArray(m_vao);
            glDrawArrays(static_cast<GLenum>(m_type), 0, m_vert.size());
        }
    
        ~geometry()
        {
            glDeleteBuffers(1, &m_vbo);
            glDeleteVertexArrays(1, &m_vao);
        }
};


