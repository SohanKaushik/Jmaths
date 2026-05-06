#include <jmaths.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>


int main() {
    Scene sc1;  

    JObjects obj1;
    obj1.set_position({ 0,0,-100 });

    sc1.add(obj1);

    while (sc1.is_running()) {
        std::cout << glm::to_string(obj1.m_transform.position) << "\n";
        sc1.update();
    }

    return 0;
}


