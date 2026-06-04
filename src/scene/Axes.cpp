#include "Axes.h"

using namespace jmaths::scene;

jmaths::scene::Axes::Axes() {

    std::vector<glm::vec3> _verts;

    // y axis
    _verts.push_back({0,-100,0});
    _verts.push_back({0,100,0});

    // x axis
    _verts.push_back({-100,0,0});
    _verts.push_back({100,0,0});

    feed_vert(_verts, rdrtype::LINES);
}

jmaths::scene::Axes::Axes(utility::Range x, utility::Range y) {

    std::vector<glm::vec3> _verts;

    // y axis
    _verts.push_back({ 0, y.min, 0 });
    _verts.push_back({ 0, y.max, 0 });

    // x axis
    _verts.push_back({ x.min, 0, 0 });
    _verts.push_back({ x.max, 0, 0 });

    for (float i = x.min; i <= x.max; i += x.step) {
        _verts.push_back({ i, -0.1f, 0 });
        _verts.push_back({ i,  0.1f, 0 });
    }

    for (float i = y.min; i <= y.max; i += y.step) {
        _verts.push_back({ -0.1f, i, 0 });
        _verts.push_back({ 0.1f, i, 0 });
    }

    feed_vert(_verts, rdrtype::LINES);
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