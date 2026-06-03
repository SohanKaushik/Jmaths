#include "Axes.h"

using namespace jmaths::scene;

jmaths::scene::Axes::Axes() {
    feed_vert(std::vector<glm::vec3>{
        {0, 0, 0}
    }, rdrtype::LINES);
}

void Axes::make_grid(int half_size, float spacing) {
    std::vector<glm::vec3> verts;

    for (int i = -half_size; i <= half_size; i++) {
        float t = i * spacing;

        // horizontal lines
        verts.push_back({ -half_size * spacing, t, 0.0f });
        verts.push_back({ half_size * spacing, t, 0.0f });

        // vertical lines
        verts.push_back({ t, -half_size * spacing, 0.0f });
        verts.push_back({ t,  half_size * spacing, 0.0f });
    }

    feed_vert(verts, rdrtype::LINES);
}


void jmaths::scene::Axes::plot(std::function<float(float)> fn,
    float samples,
    float step)
{
    plot(fn, utility::Range{ -samples, samples, step });
}

void jmaths::scene::Axes::plot(std::function<float(float)> fn,
    utility::Range range)
{
    std::vector<glm::vec3> verts;

    for (float x = range.min; x <= range.max; x += range.step) {
        verts.push_back({ x, fn(x), 0.0f });
    }

    feed_vert(verts, rdrtype::CONNECT_LINES);
}