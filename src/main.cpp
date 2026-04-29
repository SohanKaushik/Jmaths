#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "buffers/gl_buffers.h"
#include "window/window.h"
#include <glm/glm.hpp>
#include <cmath>

#include <glm/gtc/matrix_transform.hpp>

// Vertex Shader source code
const char* vs_src = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 MVP;\n"
"void main()\n"
"{\n"
"   gl_Position = MVP * vec4(aPos, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0, 0.0, 0.0, 1.0);\n"
"}\n\0";

int main() {

    GLFWwindow* _wind = create_window(800, 500, "Jmaths");
    if (!_wind) return -1;


    // glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    std::vector<float> vert2 = {
        // vertical line
         0.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
    };


    // viewport
    glViewport(0, 0, 800, 500);

    float aspect = 800.0f / 500.0f;
    
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_src, NULL);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSource, NULL);
    glCompileShader(fs);

    GLuint shaderp = glCreateProgram();
    glAttachShader(shaderp, vs);
    glAttachShader(shaderp, fs);
    glLinkProgram(shaderp);

    glDeleteShader(vs);
    glDeleteShader(fs);


    while (!glfwWindowShouldClose(_wind))
    {
        // Clear screen
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        // current shader
        glUseProgram(shaderp);

        glm::mat4 view = glm::mat4(1.0f); // pan, zoom, rotate 
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)aspect, 0.1f, 1000.0f); // projection









        glm::mat4 model = glm::mat4(1.0f);

        float time = glfwGetTime() * 500;
        model = glm::translate(
            model,
            glm::vec3(0, 0, -1) // move right & up
        );

        model = glm::rotate(model, glm::radians(time), glm::vec3(0.0f, 1.0f, 0.0f));


        glm::mat4 MVP = projection * view * model;

        std::vector<glm::vec3> points;

        int step = 4;
        float radius = 0.2f;

        for (size_t i = 0; i <= step; i++)
        {
            float angle = (2.0f * glm::pi<float>() * i) / step;
            points.push_back(glm::vec3(radius * cos(angle), radius * sin(angle), 0.0f));
        }

        // convert vec3 to float
        std::vector<float> floatVector;
        floatVector.reserve(points.size() * 3);  // Reserve space for efficiency
        for (const auto& vec : points) {
            floatVector.push_back(vec.x);
            floatVector.push_back(vec.y);
            floatVector.push_back(vec.z);
        }

        unsigned int loc = glGetUniformLocation(shaderp, "MVP");
        glUniformMatrix4fv(loc, 1, GL_FALSE, &MVP[0][0]);
        

        /*
        for (auto& obj : objects)
        {
            glm::mat4 model = obj.getModel();
            glm::mat4 MVP = projection * view * model;

            glUniformMatrix4fv(loc, 1, GL_FALSE, &MVP[0][0]);

            obj.draw();
        }
        */

        auto lines = std::make_unique<geometry>(floatVector, rdrtype::CONNECT_LINES);
        auto line2 = std::make_unique<geometry>(floatVector, rdrtype::CONNECT_LINES);

        lines->draw();

        // Swap buffers
        glfwSwapBuffers(_wind);

        // Handle events
        glfwPollEvents();
    }

    glfwTerminate();
	return 0;
}