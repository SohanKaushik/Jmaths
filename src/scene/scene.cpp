#pragma once
#include "scene.h"
#include "../window/window.h"

#include <cassert>  // for assert

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
        glViewport(0, 0, 800, 500);


        // camera init
        camera = std::make_unique<camera::Camera>();
    }

    bool Scene::is_running() {
        return window && !glfwWindowShouldClose(window);
    }

    void Scene::update() {
        if (window) {
            glm::vec3 bg = { 0.12f, 0.12f, 0.14f };
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }

        for (auto* obj : _all_objects) {
            obj->update_transforms();
        }
        for (auto* obj : _all_objects) {
            obj->draw();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    void Scene::add(JObjects& obj) {
        _all_objects.push_back(&obj);
    }
}