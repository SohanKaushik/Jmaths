#pragma once

#include "../pch.h"
#include "../Shader.h"

namespace jmaths {

    class renderable {
    public:
        virtual ~renderable() = default;
        virtual void draw(Shader& Shader) const = 0;
        virtual glm::mat4 get_model() const = 0;
    };
}