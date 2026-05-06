#pragma once
#include "../pch.h"
#include "objects.h"

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

    private:
        std::vector<JObjects*> _all_objects;
        GLFWwindow* window;
    };
}