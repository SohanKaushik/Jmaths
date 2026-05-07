#include "Axes.h"

using namespace jmaths::scene;

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