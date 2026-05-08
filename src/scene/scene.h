#pragma once
#include "../pch.h"
#include "objects.h"
#include "Camera.h"

namespace jmaths::scene {
    class Scene {
    private:
        static Scene* active_scene;

    public:
        Scene();
        ~Scene();

        Scene(const Scene&) = delete;
        Scene& operator=(const Scene&) = delete;

        void init();
        bool is_running();
        void update();
        void add(JObjects& obj);
        void remove(JObjects& obj);
        void run();
        std::unique_ptr<camera::Camera> camera;

    public: // intentionally made public 
        std::vector<JObjects*> _all_objects;
        GLFWwindow* window;
    };
}