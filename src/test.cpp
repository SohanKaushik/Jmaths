#include <jmaths.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

using namespace jmaths::animations;

int main() {
    Scene sc1;  

    Axes axes;
    axes.make_grid(5);
    axes.set_scale(10);
    axes.set_position({0,0,-20});

    Circle circle(20, 1);
    circle.set_position({ 0,0,0 });

    Circle circle1(10, 1);
    circle1.set_position({ 0,0,0 });

  
    //sc1.add(axes);
    sc1.add(circle);
    sc1.add(circle1);

    
    while (sc1.is_running()) {

        // code
        sc1.update();
    }

    return 0;
}


