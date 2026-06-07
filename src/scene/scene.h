#pragma once
#include "../pch.h"
#include "objects.h"
#include "Camera.h"


// externals
#include "../src/maths/range.h"
#include "../src/animations/play.h"

namespace jmaths::scene {
    class Scene {
    private:
        static Scene* active_scene;
        glm::vec3 m_bgclr = { 1,1,1 };

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
        

        // externals
        //void plot(std::function<float(float)> x);
        void play(JObjects& obj, float duration = 1.0f);
        void shift(float x = 0, float y = 0, float z = 0);
        void set_bg(glm::vec3 color);

        //maths
        utility::Range range(float min, float max, float step = 0.1f);

        void run();
        std::unique_ptr<camera::Camera> camera;

    public: // intentionally made public 
        std::vector<JObjects*> _all_objects;
        std::vector<std::unique_ptr<jmaths::animations::Animations>> _all_animations;

        Shader m_shader;
        GLFWwindow* window;
    };
}