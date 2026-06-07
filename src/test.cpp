#include <jmaths.h>
#include "../src/scene/primitives/Arrow.h"

using namespace jmaths::animations;

int main() {
    Scene sc1 = Scene();  
    sc1.set_bg({0,0,0});

    Axes axes = Axes({ -3,3,1 }, { -3, 3, 1 });

    //axes.make_grid(8);
    axes.set_scale(40);
    axes.set_position({0,0,-20});

    Circle circle = Circle(20, 1);
    circle.set_position({ 0,0,0 });
    circle.set_color({1,0,0});

    Circle circle1 = Circle(20, 1);
    circle1.set_position({ 0,0,0 });

    Graphs g = axes.plot([](float x) { return ((x + 2) * x * (x - 2))/2; }, range(-10, 10, 0.1));
    Graphs g1 = axes.plot([](float x) { return ((x + 2) * x * (x + 2))/2; }, range(-10, 10, 0.1));
  
    g.set_scale(40);
    g.set_color({ 0.988f, 0.435f, 0.396f });

    g1.set_scale(40);
    g1.set_color({ 0.988f, 0.435f, 0.396f });
  

    Line line = Line({0,0}, {40,40});
    line.set_color({1,1,1});

    sc1.play(g1, 1);
    sc1.play(g, 3);

    axes.set_color({ 1,1,1 });
    sc1.add(axes);

    while (sc1.is_running()) {

        // code
        sc1.update();
    }

    return 0;
}


