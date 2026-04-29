#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "buffers/gl_buffers.h"
#include "window/window.h"

// Vertex Shader source code
const char* vs_src = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
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


        glUseProgram(shaderp);
        //line1->draw();
        //line2->draw();
        glPointSize(2.0f);

        std::vector<float> point1 = { 0,0,0 };
        std::vector<float> point2 = { 0,0.5,0 };

        std::vector<float> point3 = { 0.5,0,0 };
        std::vector<float> point4 = { 0,-0.5,0 };

        std::vector<float> point5 = { 0,0,0 };

        std::vector<float> points;
        points.insert(points.end(), point1.begin(), point1.end());
        points.insert(points.end(), point2.begin(), point2.end());
        points.insert(points.end(), point3.begin(), point3.end());
        points.insert(points.end(), point4.begin(), point4.end());
        points.insert(points.end(), point5.begin(), point5.end());

        auto lines = std::make_unique<geometry>(points, rdrtype::CONNECT_LINES);

        lines->draw();

        // Swap buffers
        glfwSwapBuffers(_wind);

        // Handle events
        glfwPollEvents();
    }

    glfwTerminate();
	return 0;
}