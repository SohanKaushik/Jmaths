#include <jmaths.h>

using namespace jmaths::animations;

int main() {
    Scene sc1;  

    Axes axes;
    axes.make_grid(5);
    axes.set_scale(10);
    axes.set_position({0,0,-20});

    Circle circle(20, 1);
    circle.set_position({ 0,0,0 });

    Circle circle1(50, 1);
    circle1.set_position({ 0,0,0 });

    axes.plot([](float x) { return cos(x); },10, 0.1f);
  
    sc1.add(axes);

   sc1.add(circle);
  //  sc1.add(circle1);

    circle.set_color({ 0.0f, 0.0f, 0.95f });   // neon cyan
    circle1.set_color({ 1.0f, 0.25f, 0.75f });  // neon pink
    axes.set_color({ 0.0f, 1, 1 });   // neon cyan

    while (sc1.is_running()) {

        // code
        sc1.update();
    }

    return 0;
}


