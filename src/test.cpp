#include <jmaths.h>
#include "../src/scene/primitives/Arrow.h"

using namespace jmaths::animations;

int main() {
    Scene sc1 = Scene();  

    Axes axes = Axes({ -10,10,1 }, { -10, 10, 1 });

    //axes.make_grid(8);
    axes.set_scale(10);
    axes.set_position({0,0,-20});

    Circle circle = Circle(20, 1);
    circle.set_position({ 0,0,0 });
    circle.set_color({1,0,0});

    Circle circle1 = Circle(20, 1);
    circle1.set_position({ 0,0,0 });

    Line line = Line({0,0}, {100,100});
    line.set_color({1,0,0});

    //axes.plot([](float x) { return cos(x); } ,10, 0.1f);
    //axes.plot([](float x) { return cos(x); }, range(0,10,0.1));
    //axes.plot([](float x) { return 1/x; }, range(-10,10,0.1));

    //axes.plot([](float x) { return sin(x); });
  

    sc1.add(axes);

    //sc1.add(circle);
    sc1.add(line);
  //  sc1.add(circle1);

  
    circle1.set_color({ 1.0f, 0.25f, 0.75f });  // neon pink
    axes.set_color({ 0, 0, 0 });   // neon cyan


    circle.shift(0,1,0);
    circle.set_scale(3);

    while (sc1.is_running()) {

        // code
        sc1.update();
    }

    return 0;
}


