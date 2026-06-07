#pragma once
#define GLM_ENABLE_EXPERIMENTAL

#include "scene.h"
#include "../window/window.h"

#include <cassert>  // for assert
#include <glm/gtx/string_cast.hpp>

namespace jmaths::scene {

    // Initialize static member
    Scene* Scene::active_scene = nullptr;

    Scene::Scene() {
        // Assert if instance already exists
        assert(active_scene == nullptr && "Only one Scene instance allowed!");
        active_scene = this;
        init();
    }

    Scene::~Scene() {
        _all_objects.clear();

        if (window) {
            glfwDestroyWindow(window);
        }

        glfwTerminate();
        active_scene = nullptr;
    }

    void Scene::init() {
        window = create_window(800, 500, "Jmaths");
        if (!window) {
            std::cout << "Failed to initialize Window" << std::endl;
        }
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        // viewport
        glViewport(0, 0, 800, 500);

        // depth test
        glEnable(GL_DEPTH_TEST);

        // camera init
        camera = std::make_unique<camera::Camera>();

        // shader
        m_shader.load("src/shaders/default.vert", "src/shaders/default.frag");
    }

    bool Scene::is_running() {
        return window && !glfwWindowShouldClose(window);
    }

    void Scene::update() {
        Time::update();

        if (window) {
            glClearColor(m_bgclr.x, m_bgclr.y, m_bgclr.z, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        m_shader.use();

        // update transforms
        for (auto* obj : _all_objects) {
            obj->update_transforms();
        }

        //// renders the animations
        for (auto& anim : _all_animations) {
            anim->update();
        }

        // renders objects
        for (auto* obj : _all_objects) {
            m_shader.SetUniformMat4f("pv", camera->get_pvmatrix());
            m_shader.SetUniformMat4f("u_model", obj->get_model());
            m_shader.SetUniform3fv("u_color", obj->m_color);
            obj->draw();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Scene::add(JObjects& obj) {
        _all_objects.push_back(&obj);
    }




    void jmaths::scene::Scene::set_bg(glm::vec3 color) {
        m_bgclr = color;
    }

    void jmaths::scene::Scene::play(JObjects& obj, float duration) {

        // storing all the verts
        auto grab = obj.get_vert();

        //.. sending it to animations
        _all_animations.push_back(std::make_unique<jmaths::animations::Animations>(obj, grab, duration));

        // clearing the target obj so that it would not render fully at first
        obj.clear();
        
        // adding to the scene, thus it can draw 
        add(obj);
    }
}