#pragma once
#include "pch.h"

namespace jmaths {
    class Time {
    public:
        static float deltaTime;
        static float elapsed;

        static void update() {
            float now = (float)glfwGetTime();
            deltaTime = now - m_last;
            elapsed = now;
            m_last = now;
        }

    private:
        static float m_last;
    };
}