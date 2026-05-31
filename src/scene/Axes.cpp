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

void jmaths::scene::Axes::plot(std::function<float(float)> fn, float samples, float step) {
    
    std::vector<glm::vec3> verts;
    for (float x = -samples; x <= samples; x += step) {
        float y = fn(x);
        printf("x = %.1f, y = %.1f\n", x, y);

        verts.push_back({ x, y, 0 });
    }

    feed_vert(verts, rdrtype::CONNECT_LINES);
}
