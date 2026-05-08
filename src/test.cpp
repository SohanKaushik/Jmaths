#include <jmaths.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

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
    Scene sc1;  
    float aspect = 800.0f / 500.0f;

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_src, NULL);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSource, NULL);
    glCompileShader(fs);

    GLuint Shaderp = glCreateProgram();
    glAttachShader(Shaderp, vs);
    glAttachShader(Shaderp, fs);
    glLinkProgram(Shaderp);

    glDeleteShader(vs);
    glDeleteShader(fs);

    Axes axes;
    axes.make_grid(1);
    axes.set_position({ 0,0,-20});
    axes.set_scale({ 20,20,20});


    //sc1.add(obj1);
    sc1.add(axes);
    

    while (sc1.is_running()) {

        glUseProgram(Shaderp);
        for (auto* obj : sc1._all_objects) {
            glm::mat4 MVP = sc1.camera->get_pvmatrix() * obj->get_model();
            unsigned int loc = glGetUniformLocation(Shaderp, "MVP");
            glUniformMatrix4fv(loc, 1, GL_FALSE, &MVP[0][0]);
        }
        sc1.update();

    }

    return 0;
}


