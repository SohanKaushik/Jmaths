#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include "window/window.h"
#include "animations/play.h"
#include "scene/objects.h"
#include "scene/scene.h"
#include <glm/gtx/string_cast.hpp>

using namespace jmaths::animations;

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

    //GLFWwindow* _wind = create_window(800, 500, "Jmaths");
    //if (!_wind) return -1;


    //// glad
    //if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    //    std::cout << "Failed to initialize GLAD" << std::endl;
    //    return -1;
    //}


    std::vector<float> vert2 = {
        // vertical line
         0.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
    };


   
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

    // generate lorenz attractor points
    std::vector<glm::vec3> points1;
    std::vector<glm::vec3> points2;

    float x1 = 0.01f, y1 = 0.0f, z1 = 0.0f;
    float x2 = 0.0001f, y2 = 0.01f, z2 = 0.01f; // tiny change

    float dt = 0.005f;
    for (int i = 0; i < 20000; i++) {

        float dx = 10.0f * (y1 - x1);
        float dy = x1 * (28.0f - z1) - y1;
        float dz = x1 * y1 - 2.667f * z1;

        float dx2 = 10.0f * (y2 - x2);
        float dy2 = x2 * (28.0f - z2) - y2;
        float dz2 = x2 * y2 - 2.667f * z2;

        x1 += dx * dt;
        y1 += dy * dt;
        z1 += dz * dt;

        x2 += dx2 * dt;
        y2 += dy2 * dt;
        z2 += dz2 * dt;


        points1.push_back(glm::vec3(x1, y1, z1)); // scale down to fit screen
        points2.push_back(glm::vec3(x2, y2, z2)); // scale down to fit screen
    }

    jmaths::scene::Scene sc1;

    Animations anim1;
    Animations anim2;


    /*anim1.play(points1, 100);
    anim2.play(points2, 100);*/

    glm::mat4 view = glm::mat4(1.0f); // pan, zoom, rotate 

    //view = glm::rotate(view, glm::radians(0.0f), glm::vec3(1, 0, 0));   // X
    //view = glm::rotate(view, glm::radians(.0f), glm::vec3(0, 1, 0));    // Y
    //view = glm::rotate(view, glm::radians(0.f), glm::vec3(0, 0, 1));  // Z


  /*  auto obj1 = std::make_unique<jmaths::scene::objects>(
        std::vector<glm::vec3>{
            {1, 1, 1}, { 0,0,0 }
    });*/

   /* auto& obj = sc1.add<jmaths::scene::objects>(
        std::vector<glm::vec3>{
            {1, 1, 1}, { 0, 0, 0 }
    });*/

    using namespace jmaths::scene;

   /* auto obj = new JObjects(std::vector<glm::vec3>{
        {1, 1, 1}, { 0, 0, 0 }
    });*/

    JObjects obj(std::vector<glm::vec3>{
        {1, 1, 1}, { 0, 0, 0 }
    });

    obj.set_position({ 0, 0, -100 });

    JObjects obj2(std::vector<glm::vec3>{
        {1, 1, 1}, { 0, 0, 0 }
    });

    obj2.set_position({ 0, 0, -100 });


    //auto obj2 = std::make_unique<jmaths::scene::objects>();
    //obj2->set_position(glm::vec3(0, 0, -100));
    //obj2->set_rotation(glm::vec3(45, 0, 0));

    while (!glfwWindowShouldClose(_wind))
    {
        // Clear screen
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        // current Shader
        glUseProgram(Shaderp);


        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)aspect, 0.1f, 1000.0f); // projection

      
        //std::cout << glm::to_string(obj1.transform.translate) << std::endl;

        //float time = glfwGetTime() * 12;
        //model = glm::translate(
        //    model,
        //    glm::vec3(0, 0, -100) // move right & up
        //);

        //model = glm::rotate(model, glm::radians(time), glm::vec3(1.0f, 1.0f, 1.0f));

     
      /*  float t = (float)glfwGetTime();
        obj1->set_position({ 1.0f * t, 0.0f, -100.0f });*/


       // std::cout << glm::to_string(obj->m_transform.position) << std::endl;
            //obj2.set_scale({1.0f * t, 0.0f, 0.0});


        // this will go in scene render update
       /* obj1.update_transforms();
        obj2.update_transforms();*/

        
        //glm::mat4 model = glm::mat4(1.0f);

        // move object to position
        //glm::vec3 position = glm::vec3(0, 0, -100);


        //glm::mat4 rotX = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1, 0, 0)); // y - z

        //glm::mat4 rotY = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(0, 1, 0)); // x - z 
        //glm::mat4 rotZ = glm::rotate(glm::mat4(1.0f), glm::radians(67.0f), glm::vec3(0, 0, 1)); // x

        //glm::mat4 rotation = rotZ * rotY * rotX;

        // final model
       // model = glm::translate(glm::mat4(1.0f), position);
        
        
        glm::mat4 MVP = projection * view * obj.get_model();

        int step = 200;
        float radius = 0.2f;

        //for (size_t i = 0; i <= step; i++)
        //{
        //    float angle = (2.0f * glm::pi<float>() * i) / step;
        //    points.push_back(glm::vec3(radius * cos(angle), radius * sin(angle), 0.0f));
        //}
        unsigned int loc = glGetUniformLocation(Shaderp, "MVP");

       
       //glm::mat4 MVP1 = projection * view * obj1->get_model();
       //glUniformMatrix4fv(loc, 1, GL_FALSE, &MVP1[0][0]);
       //anim1.render();
        

        /*
        for (auto& obj : objects)
        {
            glm::mat4 model = obj.getModel();
            glm::mat4 MVP = projection * view * model;

            glUniformMatrix4fv(loc, 1, GL_FALSE, &MVP[0][0]);

            obj.draw();
        }
        */

       //auto line2 = std::make_unique<geometry>(points, rdrtype::CONNECT_LINES);
       //lines->feed(points, rdrtype::CONNECT_LINES);


     


        //glm::mat4 MVP2 = projection * view * obj2->get_model();
        //glUniformMatrix4fv(loc, 1, GL_FALSE, &MVP2[0][0]);
        //anim2.render();

        sc1.add(obj);
        sc1.add(obj2);
      
        sc1.update();

        // Swap buffers
        glfwSwapBuffers(_wind);

        // Handle events
        glfwPollEvents();
    }

    glfwTerminate();
	return 0;
}