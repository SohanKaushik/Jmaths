#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


GLFWwindow* create_window(int w, int h, const std::string& wn){


    if (!glfwInit()){
        std::cout << "GLFW init failed\n";
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(w, h, wn.c_str(), NULL, NULL);
    if (!window) {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    return window;
}

int get_height() { 
    return 0;
}